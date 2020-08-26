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
	{ 0x482ec30a, "seq_release" },
	{ 0xe914e41e, "strcpy" },
	{ 0x69442221, "flush_signals" },
	{ 0xdc43a9c8, "daemonize" },
	{ 0xa81f7b27, "usb_reset_device" },
	{ 0xf25e30d4, "napi_gro_receive" },
	{ 0xe2e44357, "usb_put_dev" },
	{ 0x47939e0d, "__tasklet_hi_schedule" },
	{ 0x74c86cc0, "init_timer_key" },
	{ 0x91660c34, "skb_queue_tail" },
	{ 0xb3a79c7, "wake_up_process" },
	{ 0x13095525, "param_ops_uint" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0x8a1741ac, "filp_open" },
	{ 0x65bd7092, "register_netdev" },
	{ 0xacc1ebd1, "param_ops_charp" },
	{ 0x4765c1e8, "usb_alloc_urb" },
	{ 0x349cba85, "strchr" },
	{ 0x96409c4, "unregister_netdev" },
	{ 0x9a1dfd65, "strpbrk" },
	{ 0x82072614, "tasklet_kill" },
	{ 0x4e6b7c98, "filp_close" },
	{ 0x37a0cba, "kfree" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x551795bb, "__netif_schedule" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x9b8b68da, "skb_dequeue" },
	{ 0x4e830a3e, "strnicmp" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x3c20fc65, "unregister_netdevice_queue" },
	{ 0xf9a482f9, "msleep" },
	{ 0x59e5070d, "__do_div64" },
	{ 0xff178f6, "__aeabi_idivmod" },
	{ 0x125e71c9, "napi_complete" },
	{ 0xd8f795ca, "del_timer" },
	{ 0xff446d0a, "dev_get_drvdata" },
	{ 0x170ec140, "seq_printf" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xe4c61ac, "usb_register_driver" },
	{ 0x2d35e307, "usb_submit_urb" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x71c90087, "memcmp" },
	{ 0x61a188b7, "kill_pid" },
	{ 0x2a4cbd75, "wireless_send_event" },
	{ 0x799aca4, "local_bh_enable" },
	{ 0x204b4554, "skb_clone" },
	{ 0xc055bcf9, "usb_alloc_coherent" },
	{ 0x4205ad24, "cancel_work_sync" },
	{ 0xb9029095, "dev_set_drvdata" },
	{ 0x8b3923e9, "skb_copy_bits" },
	{ 0xf8654eb, "pskb_copy" },
	{ 0x5f754e5a, "memset" },
	{ 0x11089ac7, "_ctype" },
	{ 0xb0bb9c02, "down_interruptible" },
	{ 0x1154e0ee, "dev_kfree_skb_any" },
	{ 0xc9ae16b1, "netif_rx" },
	{ 0xdf7f00fb, "dev_get_by_name" },
	{ 0xec90eb16, "dev_alloc_name" },
	{ 0xe47c44f8, "skb_copy" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x1e39edf1, "usb_kill_urb" },
	{ 0xd79b5a02, "allow_signal" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0x328a05f1, "strncpy" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xf5d15377, "usb_disable_autosuspend" },
	{ 0xa635310a, "device_init_wakeup" },
	{ 0x42224298, "sscanf" },
	{ 0x87141a68, "__alloc_skb" },
	{ 0xd306d6b, "netif_carrier_on" },
	{ 0xf412a08b, "usb_enable_autosuspend" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x3ff62317, "local_bh_disable" },
	{ 0x8cf51d15, "up" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0xfa717e3a, "usb_control_msg" },
	{ 0xd1329880, "param_array_ops" },
	{ 0x999e8297, "vfree" },
	{ 0xcd29d6bb, "netif_device_attach" },
	{ 0x2b688622, "complete_and_exit" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xfd8115cd, "seq_open" },
	{ 0x60f71cfa, "complete" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0x85df9b6c, "strsep" },
	{ 0x99bb8806, "memmove" },
	{ 0x267647b2, "find_vpid" },
	{ 0xff2d6697, "__napi_schedule" },
	{ 0xa91bc173, "usb_autopm_put_interface" },
	{ 0x88a34b34, "init_net" },
	{ 0xb23a587b, "skb_put" },
	{ 0x5ee8b7c5, "seq_lseek" },
	{ 0xf6288e02, "__init_waitqueue_head" },
	{ 0x80d817ab, "wait_for_completion_timeout" },
	{ 0x9a6221c5, "mod_timer" },
	{ 0x74e48595, "netif_carrier_off" },
	{ 0x9964142a, "proc_create_data" },
	{ 0xd2e2a10f, "usb_deregister" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x19de7c73, "usb_free_coherent" },
	{ 0x7d11c268, "jiffies" },
	{ 0xf014aebb, "single_release" },
	{ 0xca63e72a, "usb_get_dev" },
	{ 0x701d0ebd, "snprintf" },
	{ 0xb02f90dd, "usb_free_urb" },
	{ 0xb86e4ab9, "random32" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x4a3c300, "register_netdevice" },
	{ 0x97255bdf, "strlen" },
	{ 0xdc798d37, "__mutex_init" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xb0c19820, "__pskb_pull_tail" },
	{ 0x12a38747, "usleep_range" },
	{ 0x91745d38, "free_netdev" },
	{ 0x3bb63052, "skb_push" },
	{ 0xa122e786, "kthread_create" },
	{ 0x44da5d0f, "__csum_ipv6_magic" },
	{ 0x6d2c9dc4, "remove_proc_entry" },
	{ 0x84b183ae, "strncmp" },
	{ 0x9f984513, "strrchr" },
	{ 0xc03dcd6b, "netif_napi_del" },
	{ 0x370a1ec8, "seq_read" },
	{ 0xaf34c1d, "skb_trim" },
	{ 0x4cb226b0, "usb_autopm_get_interface" },
	{ 0x6882766a, "netif_receive_skb" },
	{ 0xcafa5294, "alloc_etherdev_mq" },
	{ 0x63ecad53, "register_netdevice_notifier" },
	{ 0xfe769456, "unregister_netdevice_notifier" },
	{ 0x9d669763, "memcpy" },
	{ 0x48a0f939, "mutex_lock_interruptible" },
	{ 0xfaef0ed, "__tasklet_schedule" },
	{ 0x60b2ff93, "skb_pull" },
	{ 0x760a0f4f, "yield" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0xa48d3081, "eth_type_trans" },
	{ 0x62b72b0d, "mutex_unlock" },
	{ 0x58ed733c, "proc_mkdir" },
	{ 0xea147363, "printk" },
	{ 0x272ce470, "single_open" },
	{ 0x8949858b, "schedule_work" },
	{ 0x5c391bc, "netif_napi_add" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0BDAp0811d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp0821d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp8822d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDApA811d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0BDAp0820d*dc*dsc*dp*icFFiscFFipFF*");
MODULE_ALIAS("usb:v0BDAp0823d*dc*dsc*dp*icFFiscFFipFF*");
MODULE_ALIAS("usb:v7392pA811d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v04BBp0953d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2001p3314d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v2001p3318d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v0E66p0023d*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v056Ep400Ed*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v056Ep400Fd*dc*dsc*dp*ic*isc*ip*");
MODULE_ALIAS("usb:v20F4p804Bd*dc*dsc*dp*ic*isc*ip*");

MODULE_INFO(srcversion, "B90FC356C9BFEA79924D9A5");
