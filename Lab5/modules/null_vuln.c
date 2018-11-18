/**
 *	Vulnerable module to having a null dereference bug
 * 	
 */

#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/module.h>	/* Specifically, a module */
#include <linux/proc_fs.h>	/* Necessary because we use proc fs */
#include <linux/seq_file.h>	/* for seq_file */

#define PROC_NAME	"null_vuln"

#define DRIVER_AUTHOR "teambi0s <amritabi0s1@gmail.com>"
#define DRIVER_DESC   "Creates a file in /proc"


void (* vuln )( void ); // function defined as void


static int my_open(struct inode *inode, struct file *file) {
	vuln(); /* undefinded function, leading to a null derefernce bug */
};


static struct file_operations my_file_ops = {
	.owner   = THIS_MODULE,
	.open    = my_open,
};


/**
 * This function is called when the module is loaded
 *
 */
int init_module(void) {
	printk(KERN_INFO "hello world");
	//struct proc_dir_entry *entry;
	proc_create(PROC_NAME, 0666, NULL,&my_file_ops); /* create a proc file */
	return 0;
}

/**
 * This function is called when the module is unloaded.
 *
 */
void cleanup_module(void) {
	remove_proc_entry(PROC_NAME, NULL);
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
