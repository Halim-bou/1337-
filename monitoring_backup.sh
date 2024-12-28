#!/usr/bin/bash

arch=$(uname -a);
fCPU=$(cat /proc/cpuinfo | grep 'core is' | wc -l)
vCpu=$(nproc)
mem_used=$(free --mega | grep Mem | awk '{print $3}')
mem_still=$(free --mega | grep Mem | awk '{print $2}')
mem_percent=$(free --mega | grep Mem | awk '{printf"%.2f", $2/$3}')
Disk_size=$(df --total | grep total | awk '{printf"%.0f", $2/1000000}')
Disk_used=$(df --total | grep total | awk '{printf"%.0f", $3/1000}')
Disk_percent=$(df --total | grep total | awk '{printf"%.0f", 100-$5}')
Cpu_load=$(sar 1 1 | grep Average | awk '{print 100-$8}')
last_boot=$(who -b | awk '{print $3, $4}')
LVM=$(lvscan 2>/dev/null | awk '/ACTIVE/ {found=1}')
Connection=$(netstat -tn | grep ESTAB | wc -l)
users_connected=$(users | tr ' ' '\n' | uniq | wc -l)
ip=$(hostname -I)
mac=$(ifconfig -a | grep ether | awk '{print $2}')
sudo=$(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l)

#echo "#Architecture: $(uname -a)"
#echo "#CPU physical : $(cat /proc/cpuinfo | grep 'core id' | wc -l)"
#echo "#vCPU : $(nproc)"
#echo "#Memory Usage: $(free --mega| grep Mem | awk '{used=$3; still=$2; perc=$2/$3; printf"%.0f/%.0fMB (%.2f%%)",used, still, perc}')"
#echo "#Disk Usage: $(df --total |grep total | awk '{printf("%.0f/%.0fGb (%.0f%%)\n",$3/1000, $2/1000000, 100-$5)}')"
#echo "#CPU load: $(sar 1 1| grep Average | awk '{printf("%.1f%%\n", 100-$8)}')"
#echo "#Last boot: $(who -b | grep "system" | awk '{printf("%s %s\n", $3, $4)}')"
#echo "#LVM use: $(sudo lvscan 2>/dev/null | awk '/ACTIVE/ {found=1} END {if (found) print "yes"; else print "no"}')"
#echo "#Connections TCP : $(netstat -tn | grep ESTAB | wc -l) ESTABLISHED"
#echo "#User log: $(users | tr ' ' '\n' | uniq | wc -l)"
#echo "#Network: IP $(hostname -I) ($(ifconfig -a | grep ether | awk '{print $2}'))"
#echo "#Sudo : $(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l) cmd"

wall "
	#Architecture: $arch
	#CPU physical: $(cat /proc/cpuinfo | grep 'core id' | wc -l)
	#vCPU : $(nproc)
	#Memory Usage: $mem_used"/"$mem_still"MB" ($mem_percent%)
	#Disk Usage: $Disk_used/$Disk_size"Gb" ($Disk_percent%)
	#CPU load: $Cpu_load%
	#Last boot: $last_boot
	#lVM use: $(lvscan 2>/dev/null | awk '/ACTIVE/ {found=1} END  {if (found) print "yes"; else print "no"}')
	#Connections TCP: $Connection ESTABLISHED
	#User log: $users_connected
	#Network: IP $ip ($mac)
	#Sudo: $sudo cmd
	"

