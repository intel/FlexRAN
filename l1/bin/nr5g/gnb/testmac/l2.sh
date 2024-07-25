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
testmacCmd=
testmacFile=./testmac
testmac_cfg_xml_file="testmac_cfg.xml"

export RTE_WLS=../../../../wls_mod
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$RTE_WLS

MACHINE_TYPE=`uname -m`

echo Number of commandline: $#
while [[ $# -ne 0 ]]
do
key="$1"

#echo Parsing: $key
if [[ "$key" == *"--testcfg"* ]]; then
    shift
    testmac_cfg_xml_file=$1
    echo "testmac_cfg_xml_file = $testmac_cfg_xml_file"
elif [[ "$key" == *"--r"* ]]; then
    shift
    if [[ $# -eq 0 ]]; then
        echo "Regression test of physical channel for all numerologies and bandwidths. Options are - ./l2.sh --r followed by:"
        echo "pusch:    PUSCH regression test"
        echo "srs:      SRS regression test"
        echo "prach:    PRACH regression test"
        echo "pucch0:   PUCCH format0 regression test"
        echo "pucch1:   PUCCH format1 regression test"
        echo "pucch234: PUCCH format2 and format3 and format4 regression test"
        echo "pdsch:    PDSCH regression test"
        echo "ssb:      SSB regression test"
        echo "csirs:    CSI-RS regression test"
        echo "pdcch:    PDCCH regression test"
        exit 1
    elif [ $1 = "pucch0" ] || [ $1 = "pucch1" ] || [ $1 = "pucch234" ]; then
        regressionList="${DIR_WIRELESS_TEST_5G}/pucch/$1_regression.cfg"
    else
        regressionList="${DIR_WIRELESS_TEST_5G}/$1/$1_regression.cfg"
    fi

    if [ -f $regressionList ]; then
        finalList+="--testfile="$regressionList
        finalList+=" "
    else
        echo "configuration file $regressionList is not found"
        exit 1
    fi
else
    finalList+=$key
    finalList+=" "
fi

shift
done

if [ ${MACHINE_TYPE} == 'x86_64' ]; then

	ulimit -c unlimited
	echo 1 > /proc/sys/kernel/core_uses_pid

	sysctl -w kernel.sched_rt_runtime_us=-1
	sysctl -w kernel.shmmax=2147483648
	sysctl -w kernel.shmall=2147483648
	systemctl stop irqbalance
	echo 0 > /proc/sys/kernel/nmi_watchdog
	echo 1 > /sys/module/rcupdate/parameters/rcu_cpu_stall_suppress

#	for i in ` ls /proc/irq |grep -v default_smp_affinity | grep -v 0 |grep -v 2 `
#	do
#		cat /proc/irq/$i/smp_affinity
#	done
fi

if [ -f "$testmac_cfg_xml_file" ]; then
    echo "using configuration file $testmac_cfg_xml_file"
    core=`grep -o -P '(?<=systemThread>).*(?=, 0, 0)' $testmac_cfg_xml_file`
    if [ -n "$core" ]; then
        testmacCmd="taskset -c $core"
    fi
    testmacCmd="$testmacCmd $testmacFile DIR_WIRELESS_TEST_4G=$DIR_WIRELESS_TEST_4G DIR_WIRELESS_TEST_5G=$DIR_WIRELESS_TEST_5G --cfgfile $testmac_cfg_xml_file $finalList"
else
    echo "configuration file $testmac_cfg_xml_file is not found"
    exit 1
fi

cpuListString=`lscpu | grep "On-line CPU(s) list"`
if [ -n "$cpuListString" ]; then
    cpuList=`echo ${cpuListString##* }`
    testmacCmd="$testmacCmd CORE_LIST=$cpuList"
fi

echo start LTE Test MAC

echo ">> Running... "${testmacCmd}

eval $testmacCmd
