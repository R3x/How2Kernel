/**
 * procfs2.c -   create a "file" in /proc
 *
 */
#include <linux/module.h>       /* Specifically, a module */
#include <linux/kernel.h>       /* We're doing kernel work */
#include <linux/proc_fs.h>      /* Necessary because we use the proc fs */
#include <linux/uaccess.h>        /* for copy_from_user */
#define PROCFS_MAX_SIZE         1024
#define PROCFS_NAME             "buffer1k"

MODULE_LICENSE("GPL");

/**
 *
 * This structure hold information about the /proc file
 *
 */
static struct proc_dir_entry *Our_Proc_File;
/**
 * The buffer used to store character for this module
 *
 */
static char procfs_buffer[PROCFS_MAX_SIZE];
/**
 * The size of the buffer
 *
 */
static unsigned long procfs_buffer_size = 0;
/**
 * This function is called then the /proc file is read
 *
 */
static
ssize_t
procfile_read(struct file *file,
              char *buffer,
              size_t buffer_length, loff_t *offset)
{
        static int finished = 0;
        /*
         * We return 0 to indicate end of file, that we have
         * no more information. Otherwise, processes will
         * continue to read from us in an endless loop.
         */
        if ( finished ) {
                printk(KERN_INFO "procfs_read: END\n");
                finished = 0;
                return 0;
        }
        finished = 1;
        /*
         * We use put_to_user to copy the string from the kernel's
         * memory segment to the memory segment of the process
         * that called us. get_from_user, BTW, is
         * used for the reverse.
         */
        if ( copy_to_user(buffer, procfs_buffer, procfs_buffer_size) ) {
                return -EFAULT;
        }
        printk(KERN_INFO "procfs_read: read %lu bytes\n", procfs_buffer_size);
        return procfs_buffer_size;       /* Return the number of bytes "read" */
 
}
/**
 * This function is called with the /proc file is written
 *
 */
static
ssize_t procfile_write(struct file *file,const char *buffer, size_t count, loff_t *offset)
{
        /* get buffer size */
        procfs_buffer_size = count;
        if (procfs_buffer_size > PROCFS_MAX_SIZE ) {
                procfs_buffer_size = PROCFS_MAX_SIZE;
        }
        /* write data to the buffer */
        if ( copy_from_user(procfs_buffer, buffer, procfs_buffer_size) ) {
                return -EFAULT;
        }
        return procfs_buffer_size;
}

static struct file_operations fops_struct = {
	.read = procfile_read,
	.write = procfile_write,
};

/**
 *This function is called when the module is loaded
 *
 */
int init_module()
{
        /* create the /proc file */
        Our_Proc_File = proc_create(PROCFS_NAME, 0644, NULL, &fops_struct);
        if (Our_Proc_File == NULL) {
                remove_proc_entry(PROCFS_NAME, NULL);
                printk(KERN_ALERT "Error: Could not initialize /proc/%s\n",
                         PROCFS_NAME);
                return -ENOMEM;
        }
//        Our_Proc_File->owner       = THIS_MODULE;
//        Our_Proc_File->mode        = S_IFREG | S_IRUGO;
//        Our_Proc_File->uid         = 0;
//        Our_Proc_File->gid         = 0;
//        Our_Proc_File->size        = 37;
        printk(KERN_INFO "/proc/%s created\n", PROCFS_NAME);
        return 0;        /* everything is ok */
}
/**
 *This function is called when the module is unloaded
 *
 */
void cleanup_module()
{
        remove_proc_entry(PROCFS_NAME, NULL);
        printk(KERN_INFO "/proc/%s removed\n", PROCFS_NAME);
}
