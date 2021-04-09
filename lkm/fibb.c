#include <linux/module.h>	 /* Needed by all modules */
#include <linux/kernel.h>	 /* Needed for KERN_INFO */
#include <linux/init.h>	 /* Needed for the macros */

///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");

///< The author -- visible when you use modinfo
MODULE_AUTHOR("Joyeeta Dey");

///< The description -- see modinfo
MODULE_DESCRIPTION("Fibonacci Program");

///< The version of the module
MODULE_VERSION("0.1");

void fibonacci(int n){
	int i,t1 = 0, t2 = 1, nextTerm;
	for (i = 1; i <= n; ++i) {
        printk("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

}

static int __init f_start(void)
{
	printk(KERN_INFO "Loading fibonacci module...\n");
	printk(KERN_INFO "Fibonacci series of 10 numbers is is:\n");
	fibonacci(10);
	return 0;
}

static void __exit f_end(void)
{
	printk(KERN_INFO "Goodbye Miss Joyeeta\n");
}


module_init(f_start);
module_exit(f_end);

