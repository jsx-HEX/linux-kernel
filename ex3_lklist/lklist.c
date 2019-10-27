#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

#define N 100
struct lklist
{
	int data;
	struct list_head list;
};
struct lklist lk;

void create_lklist(void)
{
	struct lklist *node;
	int i;

	INIT_LIST_HEAD(&lk.list);
	printk("\nCreating jsx-HEX's linux kernel list!\n");
	for(i = 0; i < N; i++)
	{
		node = (struct lklist*)kmalloc(sizeof(struct lklist),GFP_KERNEL);
		node -> data = i+1;
		list_add_tail(&node -> list, &lk.list);
		printk("Node %d has added to the lklist...\n", i+1);
	}
}

void traverse_lklist(void)
{
	struct lklist *p;
	struct list_head *pos;
	int i = 1;
	printk("\nTraverse jsx-HEx's linux kernel list!\n");
	list_for_each(pos, &lk.list)
	{
		p = list_entry(pos,struct lklist, list);
		printk("Node %d's data: %d\n",i, p->data);
		i++;
	}
	printk("\n\n");
}

void del_lklist(void)
{
	struct list_head *n, *pos;
	struct lklist *p;
	int i = 10;
	printk("\nDelete jsx-HEX's linux kernel list!\n");
	list_for_each_safe(pos, n, &lk.list)
	{
		p = list_entry(pos, struct lklist, list);
		list_del(pos);
		kfree(p);
		printk("\nThe node has removed from the lklist...\n");
		i--;
		if(i == 0)
			break;
	}
}


static int __init lklist_init(void)
{
	printk("\nLinux kernel list is starting...\n");
	create_lklist();
	traverse_lklist();
	del_lklist();
	traverse_lklist();
	return 0;
}

static void __exit lklist_exit(void)
{
	printk("\nlklist is exiting...\n");
}

module_init(lklist_init);
module_exit(lklist_exit);
MODULE_LICENSE("GPL");







