/*  
 * Assignment module : Make changes to the assignment from lab1 using ioctl so that 
 * we can change the xor key
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
