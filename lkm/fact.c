#include <linux/module.h>	 /* Needed by all modules */
#include <linux/kernel.h>	 /* Needed for KERN_INFO */
#include <linux/init.h>	 /* Needed for the macros */

///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");

///< The author -- visible when you use modinfo
MODULE_AUTHOR("Joyeeta Dey");

///< The description -- see modinfo
MODULE_DESCRIPTION("Factorial Program");

///< The version of the module
MODULE_VERSION("0.1");

int factorial(int n){
	int fact=1;
	int i;
	for(i=1;i<=n;i++){
	fact=fact*i;
	}
	return fact;
}

static int __init f_start(void)
{
	printk(KERN_INFO "Loading factorial module...\n");
	printk(KERN_INFO "Factorial of 6 is: %d\n",factorial(6));
	return 0;
}

static void __exit f_end(void)
{
	printk(KERN_INFO "Goodbye Miss Joyeeta\n");
}


module_init(f_start);
module_exit(f_end);

