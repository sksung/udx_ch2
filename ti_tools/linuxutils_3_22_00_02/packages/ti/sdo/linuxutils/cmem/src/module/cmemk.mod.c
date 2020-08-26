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
	{ 0xd1329880, "param_array_ops" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0x482ec30a, "seq_release" },
	{ 0x370a1ec8, "seq_read" },
	{ 0x5ee8b7c5, "seq_lseek" },
	{ 0xacc1ebd1, "param_ops_charp" },
	{ 0x6d2c9dc4, "remove_proc_entry" },
	{ 0x788fe103, "iomem_resource" },
	{ 0x948cde9, "num_physpages" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xb03e36e0, "class_destroy" },
	{ 0x97ad189a, "device_destroy" },
	{ 0x9bce482f, "__release_region" },
	{ 0x15331242, "omap_iounmap" },
	{ 0x64ee621a, "create_proc_entry" },
	{ 0x85df9b6c, "strsep" },
	{ 0xe9ce8b95, "omap_ioremap" },
	{ 0xadf42bd5, "__request_region" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x9b98d1c5, "device_create" },
	{ 0x543712b0, "__class_create" },
	{ 0x5ff9b045, "__register_chrdev" },
	{ 0xdc798d37, "__mutex_init" },
	{ 0x170ec140, "seq_printf" },
	{ 0x425456c9, "cpu_cache" },
	{ 0xbc10dd97, "__put_user_4" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x353e3fa5, "__get_user_4" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0x8bfb2f87, "kmalloc_caches" },
	{ 0x37a0cba, "kfree" },
	{ 0xa51ae6ab, "kmem_cache_alloc" },
	{ 0xad737d0b, "page_address" },
	{ 0xab455eb0, "up_read" },
	{ 0x1555c09f, "get_user_pages" },
	{ 0xc6d533e1, "down_read" },
	{ 0xad0c5827, "find_vma" },
	{ 0xea147363, "printk" },
	{ 0xfea547b3, "remap_pfn_range" },
	{ 0x48a0f939, "mutex_lock_interruptible" },
	{ 0x62b72b0d, "mutex_unlock" },
	{ 0xfd8115cd, "seq_open" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

