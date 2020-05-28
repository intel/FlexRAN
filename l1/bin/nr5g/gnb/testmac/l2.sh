#######################################################################
#
# GPL LICENSE SUMMARY
# 
#   Copyright(c) 2007-2019 Intel Corporation. All rights reserved.
# 
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of version 2 of the GNU General Public License as
#   published by the Free Software Foundation.
# 
#   This program is distributed in the hope that it will be useful, but
#   WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#   General Public License for more details.
# 
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
#   The full GNU General Public License is included in this distribution
#   in the file called LICENSE.GPL.
# 
#   Contact Information:
#   Intel Corporation
# 
#  version: RefPHY-20.02
#
#######################################################################


export RTE_WLS=../../../../wls_mod
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$RTE_WLS

MACHINE_TYPE=`uname -m`

if [ ${MACHINE_TYPE} == 'x86_64' ]; then

	ulimit -c unlimited
	echo 1 > /proc/sys/kernel/core_uses_pid

	sysctl -w kernel.sched_rt_runtime_us=-1
	sysctl -w kernel.shmmax=2147483648
	sysctl -w kernel.shmall=2147483648
	chkconfig --level 12345 irqbalance off
	echo 0 > /proc/sys/kernel/nmi_watchdog
	echo 1 > /sys/module/rcupdate/parameters/rcu_cpu_stall_suppress

#	for i in ` ls /proc/irq |grep -v default_smp_affinity | grep -v 0 |grep -v 2 `
#	do
#		cat /proc/irq/$i/smp_affinity
#	done
fi

echo start 5GNR Test MAC
if [ "$1" = "-g" ]; then
    shift
    gdb-ia --args ./testmac DIR_WIRELESS_TEST=$DIR_WIRELESS_TEST_5G $@
else
    ./testmac DIR_WIRELESS_TEST=$DIR_WIRELESS_TEST_5G $@
fi
