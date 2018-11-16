#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/uaccess.h> 

#include "kkid.h"

MODULE_LICENSE("GPL");

MODULE_AUTHOR("teambi0s <amritabi0s1@gmail.com>");
MODULE_DESCRIPTION("kkid module");

#define SUCCESS 0

static ssize_t
device_read(struct file *file,
            char __user *buffer,
            size_t length,
            loff_t * offset)
{
  int size = length > 8 ? 8 : length;
  if(copy_to_user(buffer , "Welcome\n" , size))
    {
       return -EFAULT;
    }

  return size;
}
                           
static int
device_open(struct inode *inode,
            struct file *file)
{
  printk("Device opened\n");
  return SUCCESS;
}

static int
device_close(struct inode *inode,
             struct file * file)
{
  printk("Device Closed\n");
  return SUCCESS;
}

static long 
call_func(struct call_arg * call_arg_ptr)
{
  unsigned long (* call )(unsigned long);
  long ret;
  struct call_arg call_args;
  if(copy_from_user(&call_args,call_arg_ptr,
                    sizeof(struct call_arg)))
    {
                return -EFAULT;
    }
  printk("Calling function @ 0x%016lx \nWith argument  0x%016lx\n"
         ,call_args.fn_addr
         ,call_args.args);
  call =(void *) call_args.fn_addr;
  ret = call(call_args.args);
  return ret;
}

static long
device_ioctl(struct file *file,
             unsigned int ioctl_num,
             unsigned long ioctl_parm)
{
  switch(ioctl_num){
  case IOCTL_CALL:
    ((struct call_arg * )ioctl_parm)->ret = call_func((struct call_arg * ) ioctl_parm);
    printk("Return value 0x%016lx\n",((struct call_arg *)ioctl_parm)->ret);
    return SUCCESS;
    break;
  default :
    break;
  }
  return SUCCESS;
  }

static struct file_operations fops = {
                                      .read = device_read,
                                      .open = device_open,
                                      .release = device_close,
                                      .unlocked_ioctl = device_ioctl,
};

int
init_module(void) {
  int Major;
  Major = register_chrdev(MAJOR_NUMBER,DEVICE_NAME,&fops);
  if (Major < 0) {
    printk("Registering the character device failed with %d\n",
	  Major);
    return Major;
  }
  return SUCCESS;
}

void
cleanup_module(void) {
  unregister_chrdev(MAJOR_NUMBER,DEVICE_NAME);
}

