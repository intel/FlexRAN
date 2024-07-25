#!/bin/bash
########################################################################
#   Copyright (2021) Intel Corporation.                                                                                                                        
#                                                                                                                                                              
#   Redistribution. Redistribution and use in binary form, without modification, are permitted provided that the following conditions are met:                
#                                                                                                                                                             
#  * Redistributions must reproduce the above copyright notice and the following disclaimer in the documentation and/or other materials provided with       
#    the distribution.                                                                                                                                         
#  * Neither the name of Intel Corporation nor the names of its suppliers may be used to endorse or promote products derived from this software             
#   without specific prior written permission.                                                                                                                
#  * No reverse engineering, decompilation, or disassembly of this software is permitted.                                                                   
#                                                                                                                                                             
#   Limited patent license.  Intel Corporation grants a world-wide, royalty-free, non-exclusive license under patents it now or hereafter                     
#   owns or controls to make, have made, use, import, offer to sell and sell ("Utilize") this software, but solely to the extent that any                     
#   such patent is necessary to Utilize the software in the form provided by Intel. The patent license shall not apply to any combinations which include      
#   this software.  No hardware per se is licensed hereunder.                                                                                                 
# 
#######################################################################    
#echo off
export RTE_WLS=../../../../wls_mod

l1Binary="./l1app"
phycfg_xml_file=
xrancfg_xml_file=
l1Cmd=
MY_DIR=`pwd`
MACHINE_TYPE=`uname -m`

if [ "x"$1 = "x-xran" ]; then
    phycfg_xml_file="phycfg_xran.xml"
    xrancfg_xml_file="xrancfg_sub6.xml"
    echo "Radio mode with XRAN - Sub6 100Mhz"
    ./dpdk.sh
elif [ "x"$1 = "x-xranmmimo" ]; then
    phycfg_xml_file="phycfg_xran.xml"
    xrancfg_xml_file="xrancfg_sub6_mmimo.xml"
    echo "Radio mode with XRAN - Sub6 100Mhz Massive-MIMO (CatB)"
    ./dpdk.sh
elif [ "x"$1 = "x-xranmmw" ]; then
    phycfg_xml_file="phycfg_xran_mmw.xml"
    xrancfg_xml_file="xrancfg_mmw.xml"
    echo "Radio mode with XRAN - mmWave 100Mhz"
    ./dpdk.sh
elif [ "x"$1 = "x-custom" ]; then
    phycfg_xml_file=$2
    xrancfg_xml_file=$3
    echo "Radio mode with XRAN - Custom Mode"
    #./dpdk.sh
elif [ "x"$1 = "x-r" ]; then
    phycfg_xml_file="phycfg_radio.xml"
    echo "Radio mode with Option 8 Front Hual FPGA"
    echo "Inserting Driver"
	cd ../../../../libs/cpa/rec
	./run.sh install
	cd $MY_DIR
elif [ "x"$1 = "x-e" ]; then
    phycfg_xml_file="phycfg_timer.xml"
    echo "TIMER Mode"
else
    echo "Invlaid mode. Options are - ./l1.sh followed by:"
    echo "-e: Timer Mode"
    echo "-r: Radio mode with Option 8 Front Hual FPGA"
    echo "-xran: Radio mode with XRAN - Sub6 100Mhz"
    echo "-xranmmw: Radio mode with XRAN - mmWave 100Mhz"
    echo "-xranmmimo: Radio mode with XRAN - Massive MIMO"
    exit -1
fi



ulimit -c unlimited

if [ ${MACHINE_TYPE} == 'x86_64' ]; then
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$RTE_WLS:../../../../libs/cpa/bin

    ulimit -c unlimited
    echo 1 > /proc/sys/kernel/core_uses_pid
    sysctl -w kernel.sched_rt_runtime_us=-1
    sysctl -w kernel.shmmax=2147483648
    sysctl -w kernel.shmall=2147483648
    systemctl stop irqbalance
    echo 0 > /proc/sys/kernel/nmi_watchdog
    echo 1 > /sys/module/rcupdate/parameters/rcu_cpu_stall_suppress

    VAR=`cat /proc/cmdline`
    VAR1=${VAR#*irqaffinity=}
    VAR2=${VAR1%% *}
    for i in ` ls /proc/irq |grep -v default_smp_affinity | grep -v 0 |grep -v 2 `
    do
        echo ${VAR2} > /proc/irq/$i/smp_affinity_list
    done
else
    echo "Machine type is not supported $MACHINE_TYPE"
    exit -1
fi

cd $MY_DIR
if [ -f "$phycfg_xml_file" ]; then
    echo "using configuration file $phycfg_xml_file"
    core=`grep -o -P '(?<=systemThread>).*(?=, 0, 0)' $phycfg_xml_file`
    if [ -n "$core" ]; then
        l1Cmd="taskset -c $core"
    fi
    l1Cmd="$l1Cmd $l1Binary --cfgfile=$phycfg_xml_file"
else
    echo "configuration file $phycfg_xml_file is not found"
    exit 1
fi

if [ -f "$xrancfg_xml_file" ]; then
    echo "using configuration file $xrancfg_xml_file"
    l1Cmd="$l1Cmd --xranfile=$xrancfg_xml_file"
fi

echo ">> Running... "${l1Cmd}

eval $l1Cmd

echo "Cleanup after [PID] $BASHPID"
exit 0
