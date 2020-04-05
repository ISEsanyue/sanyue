#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

static int hello_init(void)
{
        printk(KERN_ALERT"Here I am\n");
        return 0;
}

static void hello_exit(void)
{
        printk(KERN_ALERT"Now I had to say goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");                     