# Lab 3

In Linux, there is an additional mechanism for the kernel and kernel modules to send information to processes --- the /proc file system. Originally designed to allow easy access to information about processes (hence the name), it is now used by every bit of the kernel which has something interesting to report, such as /proc/modules which provides the list of modules and /proc/meminfo which stats memory usage statistics.

The method to use the proc file system is very similar to the one used with device drivers --- a structure is created with all the information needed for the /proc file, including pointers to any handler functions (in our case there is only one, the one called when somebody attempts to read from the /proc file). Then, init_module registers the structure with the kernel and cleanup_module unregisters it.

### Module 1

procfs3.c -  create a "file" in /proc, file when read prints HelloWorld!

### Module 2

procfs3.c -  create a "file" in /proc, file can be written to and read from.

### Module 3
procfs3.c -  create a "file" in /proc

This program uses the seq_file library to manage the /proc file to reimplement the functionality of Module 2.
