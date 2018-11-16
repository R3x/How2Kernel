#include <linux/ioctl.h>


#define MAJOR_NUMBER 300
#define DEVICE_NAME "kkid"

struct call_arg
{
        unsigned long fn_addr;
        unsigned long args;
        unsigned long ret;
};

#define IOCTL_CALL _IOWR(MAJOR_NUMBER,0,char *)


