# Modules in Lab 1

Lab 1 will cover some of the basic modules and the concepts behind it.

## Module 1 ([helloworld](helloworld.c)) - Hello World

As per norms we start with a Hello World. This module prints "Hello World 1" to the kernel logs on insertion(`insmod`) and prints "Goodbye World 1 " on removal(`rmmod`).
 
You are introduced to init_module() and cleanup_module() functions.

## Module 2 ([hello2](hello2.c)) - Init macros

Now let's see how we can we can change the names of the init_module() and the cleanup_module() functions - This is one of the preffered practices in the kernel programming space.

You are introduced to the module_init() and the module_exit() macros.

## Module 3 ([hello3](hello3.c)) - More macros 

We now try to define a global variable and print its value during the insmod to the kernel logs.

You are introduced to the \__initdata macro. 

## Module 4 ([hello4](hello4.c)) - Module Documentation

Learn to License your driver with the GPL license and add information about your driver.

Check out the description by running the `modinfo` command

## Module 5 ([hello5](hello5.c)) - Parameters

Learn to pass arguments to the kernel module while inserting it. And then use it

## Assignment Module ([assignment](assignment.c)) - Everything UP to now

Let's Test - Complete the module as mentioned 
- Take a string as a argument during `insmod`
- Have a integer variable 'key' defined as 13.
- Print the string taken from the user and the key in the init_module()
- Perform Ceaser Cipher on the string and print the result during cleanup_module()
- Add the name of the file in the Makefile
- Compile and test it.

