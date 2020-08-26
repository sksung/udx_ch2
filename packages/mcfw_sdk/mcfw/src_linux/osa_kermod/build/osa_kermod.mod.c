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
	{ 0x216e77e9, "cdev_del" },
	{ 0x8bfb2f87, "kmalloc_caches" },
	{ 0x83d70683, "edma_start" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xa3c9a9d4, "cdev_init" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0xa31e44ba, "edma_free_channel" },
	{ 0x61e1850a, "edma_write_slot" },
	{ 0x85737519, "edma_read_slot" },
	{ 0xb0bb9c02, "down_interruptible" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xf6288e02, "__init_waitqueue_head" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x3635439, "edma_stop" },
	{ 0xea147363, "printk" },
	{ 0xec6a4d04, "wait_for_completion_interruptible" },
	{ 0xdfc3f494, "cdev_add" },
	{ 0xa51ae6ab, "kmem_cache_alloc" },
	{ 0x37a0cba, "kfree" },
	{ 0xfefb6077, "edma_alloc_channel" },
	{ 0x8cf51d15, "up" },
	{ 0x60f71cfa, "complete" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

