#include <stdio.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "kkid.h"

static void execute_kernel_function();
static void check_root();
static void initialize();

static int fp;

int main(int argc, const char *argv[])
{
        initialize();
        int ch;
        while(1) {
                printf("Welcome\n1. Execute kernel function\n2. Check whether you are root\n3. Exit\n: ");   
                scanf("%d", &ch);
                switch(ch) {
                case 1 :
                        execute_kernel_function();
                        break;
                case 2 :
                        check_root();
                        break;
                case 3:
                        exit(0);
                        close(fp);
                        break;
                default : 
                        printf("Enter correct argument\n");
                        break; 
                }
        }
        return 0;
}

static void execute_kernel_function() {
        struct call_arg call_args;
        
        printf("Enter the kernel address of the function you which to execute : ");
        scanf("%lu",&call_args.fn_addr);
        printf("Arguments : ");
        scanf("%lu",&call_args.args);
        printf("Executing Kernal Function !\n");

        ioctl(fp,IOCTL_CALL,&call_args);
        printf("Return value 0x%016lx\n",call_args.ret);
}
static void check_root() {
        printf("Uid : %d ",getuid());
}

static void initialize() {

setvbuf(stdout, NULL, _IONBF, 0);
setvbuf(stdin, NULL, _IONBF, 0);
setvbuf(stderr, NULL, _IONBF, 0);

fp = open("/dev/kkid", O_RDONLY);
if(fp == -1)
{
        printf("Error while Opening File ");
        exit(0);
}
}
