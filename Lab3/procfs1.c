/* Hello Proc */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>

#define DRIVER_AUTHOR "teambi0s <amritabi0s1@gmail.com>"
#define DRIVER_DESC   "Creates a file in /proc"

#define proc_fs_name "helloworld"


struct proc_dir_entry *Our_Proc_File;

static ssize_t hello_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
  static int flag = 0; 
  if(flag) {
    printk(KERN_INFO "hello_read : END\n");
    flag = 0;
    return 0;
  }
  printk(KERN_INFO "hello_read (/proc/%s) : called\n",proc_fs_name);
  flag = 1;
  return  sprintf(buf, "HelloWorld!\n");
}

static struct file_operations proc_hello_operations = {
                                                       .read = hello_read,
};

int
init_module() {
  Our_Proc_File = proc_create(proc_fs_name, 0644, NULL, &proc_hello_operations);
  return 0;
}

void cleanup_module() {
  proc_remove(Our_Proc_File);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
