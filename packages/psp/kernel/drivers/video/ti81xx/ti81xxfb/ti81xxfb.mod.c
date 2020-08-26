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
	{ 0xfc5caa72, "platform_driver_probe" },
	{ 0xca09bb38, "vps_grpx_get_num_grpx" },
	{ 0x7d20c624, "device_remove_file" },
	{ 0x8bfb2f87, "kmalloc_caches" },
	{ 0xa7fb4150, "vps_grpx_get_ctrl" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0x27864d57, "memparse" },
	{ 0xa90c928a, "param_ops_int" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0xf08e7aa0, "framebuffer_release" },
	{ 0xb9029095, "dev_set_drvdata" },
	{ 0xad0e2bc1, "ti81xx_vram_free" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x353e3fa5, "__get_user_4" },
	{ 0x3a70e3f3, "dma_alloc_writecombine" },
	{ 0x251254e6, "cfb_fillrect" },
	{ 0x677bb305, "param_ops_bool" },
	{ 0x62b72b0d, "mutex_unlock" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0xacc1ebd1, "param_ops_charp" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x59f7fd0b, "ti81xx_vram_get_info" },
	{ 0xd6145876, "cfb_imageblit" },
	{ 0x42064352, "dev_err" },
	{ 0xdc798d37, "__mutex_init" },
	{ 0xea147363, "printk" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0x71c90087, "memcmp" },
	{ 0xdf1396fc, "register_framebuffer" },
	{ 0x328a05f1, "strncpy" },
	{ 0x72af248c, "dma_free_coherent" },
	{ 0xe16b893b, "mutex_lock" },
	{ 0xdd612e04, "device_create_file" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x20179bfe, "ti81xx_vram_alloc" },
	{ 0xa51ae6ab, "kmem_cache_alloc" },
	{ 0xbc10dd97, "__put_user_4" },
	{ 0xd6ca0d2d, "framebuffer_alloc" },
	{ 0x37a0cba, "kfree" },
	{ 0xfea547b3, "remap_pfn_range" },
	{ 0x9d669763, "memcpy" },
	{ 0x40826da2, "cfb_copyarea" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x1f1e12ae, "platform_driver_unregister" },
	{ 0xff446d0a, "dev_get_drvdata" },
	{ 0x77c82ff7, "unregister_framebuffer" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=vpss";

