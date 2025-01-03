[sudo] password for abelboua: 
root@abelboua42:/home/abelboua# cat monitoring.sh 
#!/usr/bin/bash

arch=$(uname -a);
fCPU=$(cat /proc/cpuinfo | grep 'core is' | wc -l)
vCpu=$(nproc)
mem_used=$(free --mega | grep Mem | awk '{print $3}')
mem_total=$(free --mega | grep Mem | awk '{print $2}')
mem_percent=$(free --mega | grep Mem | awk '{printf"%.2f", $3/$2*100}')
Disk_size=$(df --total | grep total | awk '{printf"%.0f", $2/1048576}')
Disk_used=$(df --total | grep total | awk '{printf"%.0f", $3/1024}')
Disk_percent=$(df --total | grep total | awk '{printf"%.0f", $5}')
Cpu_load=$(sar 1 1 | grep Average | awk '{print 100-$8}')
last_boot=$(who -b | awk '{print $3, $4}')
LVM=$(if [ $(lsblk | awk '{print $6}' | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
Connection=$(netstat -tn | grep ESTAB | wc -l)
users_connected=$(users | tr ' ' '\n' | uniq | wc -l)
ip=$(hostname -I)
mac=$(ip addr show | grep ether | awk '{print $2}')
sudo=$(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l)

wall "
	#Architecture: $arch
	#CPU physical: $(cat /proc/cpuinfo | grep 'core id' | wc -l)
	#vCPU : $(nproc)
	#Memory Usage: $mem_used"/"$mem_total"MB" ($mem_percent%)
	#Disk Usage: $Disk_used/$Disk_size"Gb" ($Disk_percent%)
	#CPU load: $Cpu_load%
	#Last boot: $last_boot
	#lVM use: $LVM
	#Connections TCP: $Connection ESTABLISHED
	#User log: $users_connected
	#Network: IP $ip ($mac)
	#Sudo: $sudo cmd
	"



