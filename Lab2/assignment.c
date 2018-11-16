/*  
 * Assignment module 
 * 
 */


#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_ALERT */
#include <linux/init.h>		/* Needed for the macros */

/* Include other required Header Files*/


/* Prototypes for the functions you have to implement*/

int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

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
