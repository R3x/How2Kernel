/* Module 1 - "Hello World" */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_ALERT */
 
/*
 * Called when the module is inserted
 */
int init_module(void)
{
	printk(KERN_INFO "Hello world 1.\n");

	/*
	 * return value :
         *      0 means successful 
         *      non 0 means init_module failed and module can't be loaded.  
         */
	return 0;
}

/*
 * Called when the module is removed from the kernel
 */
void cleanup_module(void)
{
        /* Cleanup module should always be of type void */
	printk(KERN_INFO "Goodbye world 1.\n");
}
