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
#  version: O-RAN Bronze release V1.1
#
#######################################################################
#!/bin/bash
#echo off
export RTE_WLS=$DIR_WIRELESS_WLS

l1Binary="./l1app"
#l1Binary="gdb --args ./l1app $@"
cfgxmlfile=
MY_DIR=`pwd`
WLS_DPDK_MODE=1
huge_folder="/mnt/huge"
MACHINE_TYPE=`uname -m`

if [ "x"$1 = "x-xran" ]; then
    cfgxmlfile="phycfg_xran.xml"
    echo "Radio mode with XRAN - Sub6 100Mhz"
    ./dpdk.sh
elif [ "x"$1 = "x-xranmmw" ]; then
    cfgxmlfile="phycfg_xran_mmw.xml"
    echo "Radio mode with XRAN - mmWave 100Mhz"
    ./dpdk.sh
elif [ "x"$1 = "x-fb" ]; then
    cfgxmlfile="phycfg_fb.xml"
    echo "Radio mode with Ferry Bridge - Sub3 20Mhz"
    ./dpdk.sh
elif [ "x"$1 = "x-rsub6" ]; then
    cfgxmlfile="phycfg_radio_sub6.xml"
    echo "Radio mode with Terasic Front Hual FPGA - Sub6 100Mhz"
    echo "Inserting Driver"
	cd ../../../../libs/cpa/sub6/rec
	./run.sh install
	cd $MY_DIR
elif [ "x"$1 = "x-rmmw" ]; then
    cfgxmlfile="phycfg_radio_mmw.xml"
    echo "Radio mode with Terasic Front Hual FPGA - MMWave"
    echo "Inserting Driver"
	cd ../../../../libs/cpa/mmw/rec
	./run.sh install
	cd $MY_DIR
elif [ "x"$1 = "x-e" ]; then
    cfgxmlfile="phycfg_timer.xml"
    echo "TIMER Mode"
else
    echo "Invlaid mode. Options are - ./l1.sh followed by:"
    echo "-e: Timer Mode"
    echo "-fb: Radio mode with Ferry Bridge - Sub3 20Mhz"
    echo "-rsub6: Radio mode with Terasic Front Hual FPGA - Sub6 100Mhz"
    echo "-rmmw: Radio mode with Terasic Front Hual FPGA - MMWave"
    echo "-xran: Radio mode with XRAN - Sub6 100Mhz"
    echo "-xranmmw: Radio mode with XRAN - mmWave 100Mhz"
    exit -1
fi



ulimit -c unlimited

if [ ${MACHINE_TYPE} == 'x86_64' ]; then
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$RTE_WLS:../../../../libs/cpa/bin

    if [ $WLS_DPDK_MODE = "0" ]; then
        echo Non DPDK WLS MODE
        grep Huge /proc/meminfo
        [ -d "$huge_folder" ] || mkdir -p $huge_folder
        if ! mount | grep $huge_folder; then
            mount none $huge_folder -t hugetlbfs -o rw,mode=0777
        fi
    else
        echo DPDK WLS MODE
    fi

    ulimit -c unlimited
    echo 1 > /proc/sys/kernel/core_uses_pid
    sysctl -w kernel.sched_rt_runtime_us=-1
    sysctl -w kernel.shmmax=2147483648
    sysctl -w kernel.shmall=2147483648
    chkconfig --level 12345 irqbalance off
    echo 0 > /proc/sys/kernel/nmi_watchdog
    echo 1 > /sys/module/rcupdate/parameters/rcu_cpu_stall_suppress

    for i in ` ls /proc/irq |grep -v default_smp_affinity | grep -v 0 |grep -v 2 `
    do
        echo 1 > /proc/irq/$i/smp_affinity
    done

    if [ $WLS_DPDK_MODE = "0" ]; then
        lsmod | grep wls >& /dev/null
        if [ $? -eq 0 ]; then
            rmmod wls
        fi

        insmod $RTE_WLS/wls.ko
    fi
else
    echo "Machine type is not supported $MACHINE_TYPE"
    exit -1
fi

cd $MY_DIR
if [ -f "$cfgxmlfile" ]; then
    echo "using configuration file $cfgxmlfile"
else
    echo "configuration file $cfgxmlfile is not found"
    exit 1
fi

l1Cmd="$l1Binary table 0 1 --cfgfile=$cfgxmlfile"
echo ">> Running... "${l1Cmd}

eval $l1Cmd

echo "Cleanup after [PID] $BASHPID"
if [ $WLS_DPDK_MODE = "0" ]; then
    rm -f $huge_folder
fi
exit 0
