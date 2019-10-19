#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>


int __init rm_init(void)
{
	complete((struct completion *)0xffffffffc04eb000);
	return 0;
} 

void __exit rm_exit(void)
{
	return ;
}

module_init(rm_init);
module_exit(rm_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("jsx-HEX");
MODULE_DESCRIPTION("Used to remove kernel modules that cannot be uninstalled!");
