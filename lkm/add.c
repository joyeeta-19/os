/**
* @file hello.c
* @author Akshat Sinha
* @date 10 Sept 2016
* @version 0.1
* @brief An introductory "Hello World!" loadable kernel
* module (LKM) that can display a message in the /var/log/kern.log
* file when the module is loaded and removed. The module can accept
* an argument when it is loaded -- the name, which appears in the
* kernel log files.
*/
#include <linux/module.h>	 /* Needed by all modules */
#include <linux/kernel.h>	 /* Needed for KERN_INFO */
#include <linux/init.h>	 /* Needed for the macros */

///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");

///< The author -- visible when you use modinfo
MODULE_AUTHOR("Joyeeta Dey");

///< The description -- see modinfo
MODULE_DESCRIPTION("Addition Program");

///< The version of the module
MODULE_VERSION("0.1");

int add(int a,int b){
	return a+b;
}

static int __init add_start(void)
{
	printk(KERN_INFO "Loading add module...\n");
	printk(KERN_INFO "Addition of two numbers is: %d\n",add(3,4));
	return 0;
}

static void __exit add_end(void)
{
	printk(KERN_INFO "Goodbye Miss Joyeeta\n");
}

module_init(add_start);
module_exit(add_end);

