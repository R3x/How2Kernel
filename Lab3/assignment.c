/*  
 * Perform a single key xor on the string with the given key and print 
 * the resulting hex encoded string by implementing read 
 * for the procfs file. 
 * 
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_ALERT */
#include <linux/init.h>		/* Needed for the macros */

/* Include other required Header Files*/

static struct file_operations fops_struct = {

    /* Your Code here */

};

static ssize_t procfile_write(struct file *file,const char *buffer, size_t count, loff_t *offset)
{
    /* Your Code here */
}

static ssize_t procfile_read(struct file *file, char *buffer, size_t buffer_length, loff_t *offset)
{
    /* Your Code here */
}

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
