#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init lkm_exnum(void)
{
	int x = 1,y = 2;
	printk("exnum module begin!\n");
	printk("x = %d,y = %d\n",x,y);
	printk("max = %d\n",max(x++,y++));
	printk("x = %d,y = %d\n",x,y);
	printk("min = %d\n",min(x++,y++));
	
	return 0;
}

static void __exit lkm_exit(void)
{
	printk("exnum module end!\n");
}

module_init(lkm_exnum);
module_exit(lkm_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("jsx");
