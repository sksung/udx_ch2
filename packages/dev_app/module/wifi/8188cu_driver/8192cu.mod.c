#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xbdcc0379, "module_layout" },
	{ 0x4a3c300, "register_netdevice" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2b688622, "complete_and_exit" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0xd8f795ca, "del_timer" },
	{ 0x97255bdf, "strlen" },
	{ 0xb9029095, "dev_set_drvdata" },
	{ 0x267647b2, "find_vpid" },
	{ 0x47939e0d, "__tasklet_hi_schedule" },
	{ 0xd306d6b, "netif_carrier_on" },
	{ 0x204b4554, "skb_clone" },
	{ 0xdf7f00fb, "dev_get_by_name" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0xe47c44f8, "skb_copy" },
	{ 0x8949858b, "schedule_work" },
	{ 0xb0bb9c02, "down_interruptible" },
	{ 0x74e48595, "netif_carrier_off" },
	{ 0x4205ad24, "cancel_work_sync" },
	{ 0x1e39edf1, "usb_kill_urb" },
	{ 0x6d2c9dc4, "remove_proc_entry" },
	{ 0x4e6b7c98, "filp_close" },
	{ 0x4e830a3e, "strnicmp" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x677bb305, "param_ops_bool" },
	{ 0x74c86cc0, "init_timer_key" },
	{ 0x62b72b0d, "mutex_unlock" },
	{ 0x4cb226b0, "usb_autopm_get_interface" },
	{ 0x85df9b6c, "strsep" },
	{ 0xf412a08b, "usb_enable_autosuspend" },
	{ 0x999e8297, "vfree" },
	{ 0xf5d15377, "usb_disable_autosuspend" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0x7d11c268, "jiffies" },
	{ 0xaf34c1d, "skb_trim" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xc9ae16b1, "netif_rx" },
	{ 0xb0c19820, "__pskb_pull_tail" },
	{ 0xf6288e02, "__init_waitqueue_head" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0xacc1ebd1, "param_ops_charp" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x5f754e5a, "memset" },
	{ 0xcafa5294, "alloc_etherdev_mq" },
	{ 0xd2e2a10f, "usb_deregister" },
	{ 0xdc798d37, "__mutex_init" },
	{ 0xea147363, "printk" },
	{ 0x42224298, "sscanf" },
	{ 0x71c90087, "memcmp" },
	{ 0x91745d38, "free_netdev" },
	{ 0xfaef0ed, "__tasklet_schedule" },
	{ 0x328a05f1, "strncpy" },
	{ 0x65bd7092, "register_netdev" },
	{ 0x2a4cbd75, "wireless_send_event" },
	{ 0xfa717e3a, "usb_control_msg" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x3bb63052, "skb_push" },
	{ 0xe16b893b, "mutex_lock" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0x9a6221c5, "mod_timer" },
	{ 0x61a188b7, "kill_pid" },
	{ 0x60b2ff93, "skb_pull" },
	{ 0xa635310a, "device_init_wakeup" },
	{ 0x19de7c73, "usb_free_coherent" },
	{ 0x88a34b34, "init_net" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0x1154e0ee, "dev_kfree_skb_any" },
	{ 0xd79b5a02, "allow_signal" },
	{ 0x59e5070d, "__do_div64" },
	{ 0x82072614, "tasklet_kill" },
	{ 0x69442221, "flush_signals" },
	{ 0x91660c34, "skb_queue_tail" },
	{ 0x3ff62317, "local_bh_disable" },
	{ 0xcd29d6bb, "netif_device_attach" },
	{ 0x2d35e307, "usb_submit_urb" },
	{ 0x87141a68, "__alloc_skb" },
	{ 0xca63e72a, "usb_get_dev" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0xe2e44357, "usb_put_dev" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x799aca4, "local_bh_enable" },
	{ 0xa48d3081, "eth_type_trans" },
	{ 0x64ee621a, "create_proc_entry" },
	{ 0xb3a79c7, "wake_up_process" },
	{ 0x3c20fc65, "unregister_netdevice_queue" },
	{ 0x44da5d0f, "__csum_ipv6_magic" },
	{ 0x37a0cba, "kfree" },
	{ 0xa122e786, "kthread_create" },
	{ 0x9d669763, "memcpy" },
	{ 0xec90eb16, "dev_alloc_name" },
	{ 0x8cf51d15, "up" },
	{ 0xe4c61ac, "usb_register_driver" },
	{ 0x9b8b68da, "skb_dequeue" },
	{ 0x96409c4, "unregister_netdev" },
	{ 0x60f71cfa, "complete" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x551795bb, "__netif_schedule" },
	{ 0x99bb8806, "memmove" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xc055bcf9, "usb_alloc_coherent" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xb23a587b, "skb_put" },
	{ 0x80d817ab, "wait_for_completion_timeout" },
	{ 0x13095525, "param_ops_uint" },
	{ 0x8b3923e9, "skb_copy_bits" },
	{ 0xff446d0a, "dev_get_drvdata" },
	{ 0xb02f90dd, "usb_free_urb" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xa91bc173, "usb_autopm_put_interface" },
	{ 0xdc43a9c8, "daemonize" },
	{ 0x760a0f4f, "yield" },
	{ 0x4765c1e8, "usb_alloc_urb" },
	{ 0x8a1741ac, "filp_open" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0BDAp8191d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp8176d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp8170d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp817Ed*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp817Ad*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp817Bd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp817Dd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp8754d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp817Fd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp818Ad*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp018Ad*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp17C0d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp8177d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp8178d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp817Cd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp8191d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v1058p0631d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2019pED17d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0DF6p0052d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v7392p7811d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v07B8p8189d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0EB0p9071d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v06F8pE033d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v103Cp1629d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2001p3308d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v050Dp1102d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2019pAB2Ad*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v20F4p648Bd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v4855p0090d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v13D3p3357d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0DF6p005Cd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp5088d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v4856p0091d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0846p9041d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2019p4902d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2019pAB2Ed*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2001p330Bd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:vCDABp8010d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0B05p17BAd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp1E1Ed*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04BBp094Cd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:vCDABp8011d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp0A8Ad*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp317Fd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v13D3p3359d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v13D3p3358d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04F2pAFF7d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04F2pAFF9d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04F2pAFFAd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04F2pAFF8d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04F2pAFFBd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04F2pAFFCd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2019p1201d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2001p3307d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2001p330Ad*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2001p3309d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0586p341Fd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v7392p7822d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2019pAB2Bd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v07B8p8178d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v07AAp0056d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v4855p0091d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v050Dp2102d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v050Dp2103d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v20F4p624Dd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0DF6p0061d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0B05p17ABd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0846p9021d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0846pF001d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0E66p0019d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0E66p0020d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v050Dp1004d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp2E2Ed*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2357p0100d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v06F8pE035d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04BBp0950d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0DF6p0070d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0789p016Dd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp8186d*dc*dsc*dp*ic*isc*ip*");

MODULE_INFO(srcversion, "6DA056E65E0119DBE46F0D1");
