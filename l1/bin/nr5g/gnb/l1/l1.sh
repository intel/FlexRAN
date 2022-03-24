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
#!/bin/bash
#echo off
export RTE_WLS=$DIR_WIRELESS_WLS

l1Binary="./l1app"
phycfg_xml_file=
xrancfg_xml_file=
MY_DIR=`pwd`
WLS_DPDK_MODE=1
huge_folder="/mnt/huge"
MACHINE_TYPE=`uname -m`

if [ "x"$1 = "x-xran" ]; then
    phycfg_xml_file="phycfg_xran.xml"
    xrancfg_xml_file="xrancfg_sub6.xml"
    echo "Radio mode with XRAN - Sub6 100Mhz"
    ./dpdk.sh
elif [ "x"$1 = "x-xranurllc" ]; then
    phycfg_xml_file="phycfg_xran_urllc_gnb.xml"
    xrancfg_xml_file="xrancfg_sub6_urllc_gnb.xml"
    echo "Radio mode with XRAN - URLLC GNB Mode"
elif [ "x"$1 = "x-xranurllctue" ]; then
    phycfg_xml_file="phycfg_xran_urllc_tue.xml"
    xrancfg_xml_file="xrancfg_sub6_urllc_tue.xml"
    echo "Radio mode with XRAN - URLLC TestUE Mode"
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
    ./dpdk.sh
elif [ "x"$1 = "x-fb" ]; then
    phycfg_xml_file="phycfg_fb.xml"
    echo "Radio mode with Ferry Bridge - Sub3 20Mhz"
    ./dpdk.sh
elif [ "x"$1 = "x-rsub6" ]; then
    phycfg_xml_file="phycfg_radio_sub6.xml"
    echo "Radio mode with Terasic Front Hual FPGA - Sub6 100Mhz"
    echo "Inserting Driver"
	cd ../../../../libs/cpa/sub6/rec
	./run.sh install
	cd $MY_DIR
elif [ "x"$1 = "x-rmmw" ]; then
    phycfg_xml_file="phycfg_radio_mmw.xml"
    echo "Radio mode with Terasic Front Hual FPGA - MMWave"
    echo "Inserting Driver"
	cd ../../../../libs/cpa/mmw/rec
	./run.sh install
	cd $MY_DIR
elif [ "x"$1 = "x-e" ]; then
    phycfg_xml_file="phycfg_timer.xml"
    echo "TIMER Mode"
else
    echo "Invlaid mode. Options are - ./l1.sh followed by:"
    echo "-e: Timer Mode"
    echo "-fb: Radio mode with Ferry Bridge - Sub3 20Mhz"
    echo "-rsub6: Radio mode with Terasic Front Hual FPGA - Sub6 100Mhz"
    echo "-rmmw: Radio mode with Terasic Front Hual FPGA - MMWave"
    echo "-xran: Radio mode with XRAN - Sub6 100Mhz"
    echo "-xranmmw: Radio mode with XRAN - mmWave 100Mhz"
    echo "-xranmmimo: Radio mode with XRAN - Massive MIMO"
    echo "-xranurllc: Radio mode with XRAN - URLLC GNB"
    echo "-xranurllctue: Radio mode with XRAN - URLLC TestUE"
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
if [ -f "$phycfg_xml_file" ]; then
    echo "using configuration file $phycfg_xml_file"
    l1Cmd="$l1Binary table 0 1 --cfgfile=$phycfg_xml_file"
else
    echo "configuration file $phycfg_xml_file is not found"
    exit 1
fi

if [ -f "$xrancfg_xml_file" ]; then
    echo "using configuration file $xrancfg_xml_file"
    l1Cmd="$l1Binary table 0 1 --cfgfile=$phycfg_xml_file --xranfile=$xrancfg_xml_file"
fi

echo ">> Running... "${l1Cmd}

eval $l1Cmd

echo "Cleanup after [PID] $BASHPID"
if [ $WLS_DPDK_MODE = "0" ]; then
    rm -f $huge_folder
fi
exit 0
