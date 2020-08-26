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
	{ 0xd6f451bf, "kobject_put" },
	{ 0xfc5caa72, "platform_driver_probe" },
	{ 0x8bfb2f87, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0x27864d57, "memparse" },
	{ 0x349cba85, "strchr" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0x97255bdf, "strlen" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x677bb305, "param_ops_bool" },
	{ 0x62b72b0d, "mutex_unlock" },
	{ 0x85df9b6c, "strsep" },
	{ 0x2fa7e1fa, "kobject_del" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0xacc1ebd1, "param_ops_charp" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x5f754e5a, "memset" },
	{ 0xa4610bc6, "omap_rev" },
	{ 0xdc798d37, "__mutex_init" },
	{ 0xea147363, "printk" },
	{ 0x42224298, "sscanf" },
	{ 0x8809f63, "kobject_init_and_add" },
	{ 0xeb43e8d7, "multiproc_get_id" },
	{ 0xe16b893b, "mutex_lock" },
	{ 0xd0b41b45, "notify_unregister_event" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0xa51ae6ab, "kmem_cache_alloc" },
	{ 0x4ac18634, "notify_register_event" },
	{ 0x12a38747, "usleep_range" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0xe9ce8b95, "omap_ioremap" },
	{ 0x15331242, "omap_iounmap" },
	{ 0xb7d858e6, "wait_for_completion_interruptible_timeout" },
	{ 0x506d97f5, "omap_readl" },
	{ 0x1d2e87c6, "do_gettimeofday" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d669763, "memcpy" },
	{ 0x3073b97, "omap_writel" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x3b8c7eee, "notify_send_event" },
	{ 0x60f71cfa, "complete" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x1f1e12ae, "platform_driver_unregister" },
	{ 0x13095525, "param_ops_uint" },
	{ 0xe914e41e, "strcpy" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

