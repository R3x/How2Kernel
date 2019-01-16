/**
 * canary.c - A module to demostrate stack smashing with canary
 *
 */
#include <linux/module.h>       /* Specifically, a module */
#include <linux/kernel.h>       /* We're doing kernel work */
#include <linux/proc_fs.h>      /* Necessary because we use the proc fs */
#include <linux/uaccess.h>        /* for copy_from_user */

#define PROCFS_MAX_SIZE         1024
#define PROCFS_NAME             "canary"

MODULE_LICENSE("GPL");

static struct proc_dir_entry *Our_Proc_File;
static char procfs_buffer[PROCFS_MAX_SIZE];
static unsigned long procfs_buffer_size = 0;

static
ssize_t
procfile_read(struct file *file,
              char *buffer,
              size_t buffer_length, loff_t *offset)
{
	static int flag = 0; 
	char localbuf[16]; //token
	memset(localbuf, 0, 16);
	if(flag) {
		printk(KERN_INFO "read : END\n");
		flag = 0;
		return 0;
	}
	printk(KERN_INFO "read (/proc/%s) : called\n",PROCFS_NAME);
	if(sizeof localbuf > 10) {
		printk("nope");
		dump_stack();
	}
	memcpy(&localbuf, procfs_buffer, sizeof localbuf);
	flag = 1;
	return sprintf(buffer,localbuf);
}

static
ssize_t procfile_write(struct file *file,const char *buffer, size_t count, loff_t *offset)
{
        char localbuf[16];
	memset(localbuf, 0, 16);
	memset(procfs_buffer, 0, 16);
        /* get buffer size */
        procfs_buffer_size = count;
        /* write data to the buffer */
        if ( copy_from_user(procfs_buffer, buffer, procfs_buffer_size) ) {
                return -EFAULT;
        }
        memcpy(localbuf,procfs_buffer,procfs_buffer_size);
        printk(KERN_INFO "copied to buffer : %s", localbuf);
        return procfs_buffer_size;
}

static struct file_operations fops_struct = {
	.read = procfile_read,
	.write = procfile_write,
};

int init_module()
{
        /* create the /proc file */
        Our_Proc_File = proc_create(PROCFS_NAME, 0666, NULL, &fops_struct);
        if (Our_Proc_File == NULL) {
                remove_proc_entry(PROCFS_NAME, NULL);
                printk(KERN_ALERT "Error: Could not initialize /proc/%s\n",
                         PROCFS_NAME);
                return -ENOMEM;
        }
        printk(KERN_INFO "/proc/%s created\n", PROCFS_NAME);
        return 0;        /* everything is ok */
}

void cleanup_module()
{
        remove_proc_entry(PROCFS_NAME, NULL);
        printk(KERN_INFO "/proc/%s removed\n", PROCFS_NAME);
}
