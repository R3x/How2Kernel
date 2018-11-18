#!/bin/sh

# set min_mmap_addr to 0x00
echo 0 >  /proc/sys/vm/mmap_min_addr 

# permission for all users to access /proc/kallsyms
echo 0 > /proc/sys/kernel/kptr_restrict      
echo 1 > /proc/sys/kernel/perf_event_paranoid 

# create a guest user 
cd /
mkdir home
adduser -D guest
# setting the passwd of guest as "guest"
sed -i 's/guest:.*:17852:0:99999:7:::/guest:$1$QgQXuAOl$.Fv9ijhDyYuIF7VmrJbc30:17852:0:99999:7:::/g' /etc/shadow 


