# Lab 5
This lab will be your first major step in learning to root a kernel.

### Topics covered
* understanding security mitigations on the kernel.
* the null dereference bug
* debugging the kernel with gdb stub
* redirecting code execution (PoC) 	
* writing a shellcode to get root privileges

### Mitigations

#### mmap\_min\_addr
Prevent the user from mapping address below a fixed value, thus exploiting null ptr dereferences becomes a hazzle. This value is set in /proc/sys/vm/mmap\_min\_addr. 

#### KALLSYMS 
/proc/kallsyms contains the address of all the modules loaded into the kernel.
User is denied permission to read from this file, so finding the addresses of
prepare\_kernel\_cred() and commit_creds() is difficult. The permission is set
in /proc/sys/kernel/kptr_restrict. A value of "0" gives access to all users, "1"
for root only access, and "2" for no access at all. (log files like /var/log/messages and dmesg can leak some module addresses )

#### SMEP and SMAP
SMEP (Supervisor Mode Execution Protection) prevents execution of code in user memory from the kernel space. If the "user" bit of an address is set and the kernel tries to execute it, a page fault is triggered. 

SMAP (Supervisor Mode Access Protection) prevents the access of user memory from
the kernel space is a similar way.

#### KASLR (Kernel Address Space Layout Randomization)
Just like ASLR, KASLR randomizes memory sections in the are randomizes in the kernel. The base address of the kernel is relocated at boot time. Moreover, the offsets at which modules are loaded every boot is also randomized.  
Kernel stack address are randomized between processes and syscalls.
Heap memory base is also randomized each time the kernel boots.

#### Stack Canaries
To prevent buffer overflows from enabling attackers to mercilessly overwrite the
return address, a random value is placed on the stack before the return address
and this value is verified before the function returns to check if the stack has
been overflown.

#### Stack Depth Overflow Check
Prevents allocations that consume large stack memory with recursive function calls or large stack variables. Such allocations lets the attacker corrupt sensitive data present right after the preallocated stack memory.

### References 

<https://www.kernel.org/doc/html/v4.18/security/self-protection.html>

