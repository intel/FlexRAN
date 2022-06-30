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
testmac_cfg_xml_file="testmac_cfg.xml"

export RTE_WLS=${DIR_WIRELESS_WLS}
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

if [ -f "$testmac_cfg_xml_file" ]; then
    echo "using configuration file $testmac_cfg_xml_file"
    core=`grep -o -P '(?<=systemThread>).*(?=, 0, 0)' $testmac_cfg_xml_file`
    if [ -n "$core" ]; then
        testmacCmd="taskset -c $core"
    fi
if [ "$1" = "-g" ]; then
    shift
        if [ "$RTE_TARGET" == "x86_64-native-linuxapp-icx"]; then
            testmacCmd="$testmacCmd /opt/intel/oneapi/debugger/10.2.4/gdb/intel64/bin/gdb-oneapi --args"
else
            testmacCmd="$testmacCmd /home/opt/intel/system_studio_2019/bin/gdb-ia --args"
fi
    fi
    testmacCmd="$testmacCmd ./testmac DIR_WIRELESS_TEST_4G=$DIR_WIRELESS_TEST_4G DIR_WIRELESS_TEST_5G=$DIR_WIRELESS_TEST_5G $@"
else
    echo "configuration file $testmac_cfg_xml_file is not found"
    exit 1
fi

echo start 5GNR Test MAC

echo ">> Running... "${testmacCmd}

eval $testmacCmd
