#include <stdio.h>

static void execute_kernel_function();
static void check_root();

int main(int argc, const char *argv[])
{
    int ch;
    while(1) {
        printf("Welcome\n1. Execute kernel function\n2. Check whether you are root\n3. Exit");   
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
                break;
            default : 
                printf("Enter correct argument\n");
                break; 
        }
    }
    return 0;
}

static void execute_kernel_function() {
    int argno;
    printf("Enter the kernel address of the function you which to execute");

    printf("How many arguments do you wish to pass");
    scanf("%d", &argno);
    if (argno) {
        int arr[argno];
        for (int i = 0; i < argno; i++) {
            
        }
    }
}
