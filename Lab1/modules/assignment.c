/*  
 *  
 * 
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_ALERT */
#include <linux/init.h>		/* Needed for the macros */

static int __init assignment_init(void)
{
    /* Your Code here */
  return 0;
}

static void __exit assignment_exit(void)
{
  /* Your Code here */
}

module_init(assignment_init);
module_exit(assignment_exit);
