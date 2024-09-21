#!/bin/bash

# Architecture of the SO
arch=$(uname -a)

# Number of fisical cores
cpu_f=$(grep "physical id" /proc/cpuinfo | wc -l)

# Number of virtual cores
cpu_v=$(grep "processor" /proc/cpuinfo | wc -l)

# Memory Usage
mem_usage=$(free -m | awk '$1 == "Mem:" {printf ("%d/%dMB (%.2f%%)"), $3, $2, $3/$2*100}')

# Disk Usage
disk_t=$(df -BG | grep '^/dev/' | grep -v "/boot" | awk '{d_t += $2} END {printf ("%.1fGb\n"), d_t}')
disk_u=$(df -BM | grep '^/dev/' | grep -v "/boot" | awk '{d_u += $3} END {printf ("%dMb\n"), d_u}')
disk_p=$(df -BM | grep '^/dev/' | grep -v "/boot" | awk '{d_u += $3} {d_t+= $2} END {printf("%d"), d_u/d_t*100}')

# CPU Load
cpu_l=$(top -bn1 | grep "Cpu(s)" | xargs | awk '{print $2 + $4}')

# Last boot
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM use
lvm_u=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# Connections TCP
tcp_c=$(ss -t state established | wc -l )

# User log
u_log=$(users | wc -w)

# Network
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# Sudo commands
s_cmd=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
	CPU physical: $cpu_f
	vCPU: $cpu_v
	#Memory Usage: $mem_usage
	Disk Usage: $disk_u/${disk_t} ($disk_p%)
	CPU load: $cpu_l%
	Last boot: $lb
	LVM use: $lvm_u
	Connections TCP: $tcp_c ESTABLISHED
	User log: $u_log
	Network: IP $ip ($mac)
	Sudo: $s_cmd cmd"
