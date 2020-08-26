/*
 * PTP 1588 clock support - character device implementation.
 *
 * Copyright (C) 2010 OMICRON electronics GmbH
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include <linux/module.h>
#include <linux/posix-clock.h>
#include <linux/poll.h>
#include <linux/sched.h>

#include "ptp_private.h"

int ptp_open(struct posix_clock *pc, fmode_t fmode)
{
	return 0;
}

long ptp_ioctl(struct posix_clock *pc, unsigned int cmd, unsigned long arg)
{
	struct ptp_clock_caps caps;
	struct ptp_clock_request req;
	struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
	struct ptp_clock_info *ops = ptp->info;
	int enable, err = 0;

	switch (cmd) {

	case PTP_CLOCK_GETCAPS:
		memset(&caps, 0, sizeof(caps));
		caps.max_adj = ptp->info->max_adj;
		caps.n_alarm = ptp->info->n_alarm;
		caps.n_ext_ts = ptp->info->n_ext_ts;
		caps.n_per_out = ptp->info->n_per_out;
		caps.pps = ptp->info->pps;
		err = copy_to_user((void __user *)arg, &caps, sizeof(caps));
		break;

	case PTP_EXTTS_REQUEST:
		if (copy_from_user(&req.extts, (void __user *)arg,
				   sizeof(req.extts))) {
			err = -EFAULT;
			break;
		}
		if (req.extts.index >= ops->n_ext_ts) {
			err = -EINVAL;
			break;
		}
		req.type = PTP_CLK_REQ_EXTTS;
		enable = req.extts.flags & PTP_ENABLE_FEATURE ? 1 : 0;
		err = ops->enable(ops, &req, enable);
		break;

	case PTP_PEROUT_REQUEST:
		if (copy_from_user(&req.perout, (void __user *)arg,
				   sizeof(req.perout))) {
			err = -EFAULT;
			break;
		}
		if (req.perout.index >= ops->n_per_out) {
			err = -EINVAL;
			break;
		}
		req.type = PTP_CLK_REQ_PEROUT;
		enable = req.perout.period.sec || req.perout.period.nsec;
		err = ops->enable(ops, &req, enable);
		break;

	case PTP_ENABLE_PPS:
		if (!capable(CAP_SYS_TIME))
			return -EPERM;
		req.type = PTP_CLK_REQ_PPS;
		enable = arg ? 1 : 0;
		err = ops->enable(ops, &req, enable);
		break;

	default:
		err = -ENOTTY;
		break;
	}
	return err;
}

unsigned int ptp_poll(struct posix_clock *pc, struct file *fp, poll_table *wait)
{
	struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);

	poll_wait(fp, &ptp->tsev_wq, wait);

	return queue_cnt(&ptp->tsevq) ? POLLIN : 0;
}

ssize_t ptp_read(struct posix_clock *pc,
		 uint rdflags, char __user *buf, size_t cnt)
{
	struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
	struct timestamp_event_queue *queue = &ptp->tsevq;
	struct ptp_extts_event event[PTP_BUF_TIMESTAMPS];
	unsigned long flags;
	size_t qcnt, i;

	if (cnt % sizeof(struct ptp_extts_event) != 0)
		return -EINVAL;

	if (cnt > sizeof(event))
		cnt = sizeof(event);

	cnt = cnt / sizeof(struct ptp_extts_event);

	if (mutex_lock_interruptible(&ptp->tsevq_mux))
		return -ERESTARTSYS;

	if (wait_event_interruptible(ptp->tsev_wq, queue_cnt(queue))) {
		mutex_unlock(&ptp->tsevq_mux);
		return -ERESTARTSYS;
	}

	spin_lock_irqsave(&queue->lock, flags);

	qcnt = queue_cnt(queue);

	if (cnt > qcnt)
		cnt = qcnt;

	for (i = 0; i < cnt; i++) {
		event[i] = queue->buf[queue->head];
		queue->head = (queue->head + 1) % PTP_MAX_TIMESTAMPS;
	}

	spin_unlock_irqrestore(&queue->lock, flags);

	cnt = cnt * sizeof(struct ptp_extts_event);

	mutex_unlock(&ptp->tsevq_mux);

	if (copy_to_user(buf, event, cnt)) {
		mutex_unlock(&ptp->tsevq_mux);
		return -EFAULT;
	}

	return cnt;
}
