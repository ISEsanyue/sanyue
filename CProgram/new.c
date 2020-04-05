#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

//insmod
static int come(void) {
        printk(KERN_ALERT"Here I am!\n");
        return 0;
}

//rmmod
static void leave(void) {
        printk(KERN_ALERT"Now I had to say goodbye\n");
}

module_init(come);
module_exit(leave);

MODULE_LICENSE("GPL");
