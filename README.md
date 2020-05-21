# FlexRAN
============
Copyright (C) 2019-2020 Intel Corporation

Introduction
============
FlexRAN is Intel 4G and 5G baseband PHY Reference Design, which uses Xeon® series Processor with Intel Architecture. This 5GNR Reference PHY consists of a L1 binary which are validated on a Intel® Xeon® SkyLake / CascadeLake platforms and demonstrates the capabilities of the software running different 5GNR L1 features. It implemented the relevant functions in [3GPP TS 38.211, 212, 213, 214 and 215].

L1 Application Overview
============
The L1 application itself support pravite interface, togther with the translate layer application, FAPI interface was supported. FAPI was defined in small cell forum, you can download through https://www.smallcellforum.org/. the FAPI version 222.10.02 was adopted in current release. Details of FAPI and pravite API mapping, you could refer the FAPI document in O-RAN software community O-DU low document https://gerrit.o-ran-sc.org/r/o-du/phy. 
Regard to FEC functionalities, there are two options supported by the application
   * FEC running in IA with DPDK BBDev associate with specific SW FEC SDKs
   * FEC running in FPGA/ASIC with DPDK BBDev interface and associate driver<br>
Details install guide can be find in below installation section

Testmac Application Overview
============
The L1 PHY Application can be tested for functionality and performance (meeting realtime runtime budgets) using an application called the testmac. These are basically testing complete API to IQ samples of all modules within the L1 application. The main purpose of these 2 applications are:
  * To generate APIs to the PHY and receive APIs from the PHY.
  * At the beginning of a UL test, they provide reference IQ samples to the PHY and at the end of a DL test, they receive the IQ samples from the PHY.
There are multiple test folders which have:
  * Config files for multi-slot (xml format)
  * Reference UL IQ Samples to use as Input to PHY (for UL test)
  * Reference DL IQ Samples to use as reference Output to compare from PHY (for DL test)
  * Reference UL Payload files (for UL Test) which have all the payloads for PUSCH / PUCCH / PRACH / SRS / others
At the end of the test, both tools compare the reference DL IQ / UL Payloads and generate a pass / fail report.
These tools are explained in more detail in the next few sections. In terms of testing we have 3 different types of tests:
DL: Downlink Only
UL: Uplink Only
FD: Full Duplex - DL and UL
Each test type has a bunch of test cases (with unique testNum) and these are defined in the *Bit Exact Test Cases* section

Real-Time Host Installation
============

To run the L1 PHY application, you should configure the BIOS and OS of the server. Take Intel Cascade Lake SP server as an example here.

BIOS configuration
----------------------------

Advanced -> Power & Performance
>            CPU Power and Performance Policy : Performance
Advanced -> Power & Performance -> Uncore Power Management
>            Uncore Frequency Scaling : Disabled
>            Performance P-limit : Disabled
Advanced -> Power -> CPU P State Control
>           Enhanced Intel SpeedStep (R) Tech : Enabled
>           Intel Configurable TDP : Enabled
>           Configurable TDP Level : Level 2
>           Intel(R) Turbo Boost Technology : Enabled
>           Energey Efficient Turbo : Disabled 
Advanced -> Power & Performance -> Hardware P States
>           Hardware P-States : Disabled
Advanced -> Power & Performance -> CPU C States Control
>           Package C-State : C0/C1 state
>           C1E : Disabled
>           Processor C6 : Disabled
          
OS configuration
-------------------------------

First you should install CentOS 7 (7.5+) from CentOS official site, then install Real Time kernel and required tools to tune the OS real timer performance. CentOS 7.7 and RT kernel kernel-rt-3.10.0-1062.12.1.rt56.1042 have been validated for this release.

>`yum install -y kernel-rt kernel-rt-devel kernel-rt-kvm rtctl rt-setup rt-tests tuna tuned-profiles-nfv tuned-profiles-nfv-host tuned-profiles-nfv-guest qemu-kvm-tools-ev`

Below give one example to tune the RT kernel performance for Intel Cascade Lake CPU 6248
Edit /etc/tuned/realtime-virtual-host-variables.conf to add isolated_cores=1-19:
>`# Examples:`

>`# isolated_cores=2,4-7`

>`# isolated_cores=2-23`

>`isolated_cores=1-19`

Core 1-19 are isolated from the host OS and dedicated for real time tasks.

Run below command to activate Real Time Profile
>`tuned-adm profile realtime-virtual-host`

Configure kernel command line
Edit /etc/default/grub and append the following to the GRUB_CMDLINE_LINUX:
>`"processor.max_cstate=1 intel_idle.max_cstate=0 intel_pstate=disable idle=poll default_hugepagesz=1G hugepagesz=1G hugepages=32 intel_iommu=off selinux=0 enforcing=0 nmi_watchdog=0 audit=0 mce=off kthread_cpus=0 irqaffinity=0"`

Add the following:
>`GRUB_CMDLINE_LINUX_DEFAULT="${GRUB_CMDLINE_LINUX_DEFAULT:+$GRUB_CMDLINE_LINUX_DEFAULT }\$tuned_params"`
>`GRUB_INITRD_OVERLAY="${GRUB_INITRD_OVERLAY:+$GRUB_INITRD_OVERLAY }\$tuned_initrd"`

After the change, the grub file runs the following command to update the grub:
>`grub2-mkconfig -o /boot/grub2/grub.cfg`

Reboot the server, and check the kernel parameter, which should look like:
>`cat /proc/cmdline`

>`BOOT_IMAGE=/vmlinuz-3.10.0-1062.12.1.rt56.1042.el7.x86_64 root=UUID=9b3e69f6-88af-4af1-8964-238879b4f282 ro crashkernel=auto rd.lvm.lv=centos/root rd.lvm.lv=centos/swap rhgb quiet processor.max_cstate=1 intel_idle.max_cstate=0 intel_pstate=disable idle=poll default_hugepagesz=1G hugepagesz=1G hugepages=32 intel_iommu=off selinux=0 enforcing=0 nmi_watchdog=0 audit=0 mce=off kthread_cpus=0 irqaffinity=0 skew_tick=1 isolcpus=1-19 intel_pstate=disable nosoftlockup nohz=on nohz_full=1-19 rcu_nocbs=1-19`

Set CPU frequency using msr-tools
>`git clone https://github.com/intel/msr-tools/`

>`cd msr-tools/`

>`git checkout msr-tools-1.3`

>`make`

>`cat <<EOF > turbo-2.5G.sh`

>`#!/bin/sh`

>`for i in {0..39}`

>`do`

>`#Set core 0-39 to 2.5GHz (0x1900). Please change according to your CPU model`

>`    ./wrmsr -p \${i} 0x199 0x1900`

>`done`

>`#Set Uncore to Max`

>`./wrmsr -p 0 0x620 0x1e1e`

>`./wrmsr -p 39 0x620 0x1e1e`

>`EOF`

>`chmod 755 turbo-2.5G.sh`

>`sh turbo-2.5G.sh`

Set CPU Frequency Policy to Performance.
>`cpupower frequency-set -g performance`

RT Test and Verify the test result
>`cyclictest -m -n -p95 -d0 -a 1-16 -t 16`

    /dev/cpu_dma_latency set to 0us
    policy: fifo: loadavg: 0.00 0.01 0.05 1/702 25564
    T: 0 (25549) P:95 I:1000 C:  5796 Min:   4 Act:    5 Avg:   4 Max:   6
    T: 1 (25550) P:95 I:1000 C:  5797 Min:   4 Act:    5 Avg:   4 Max:   6
    T: 2 (25551) P:95 I:1000 C:  5791 Min:   4 Act:    5 Avg:   4 Max:   6
    T: 3 (25552) P:95 I:1000 C:  5788 Min:   4 Act:    4 Avg:   4 Max:   6
    T: 4 (25553) P:95 I:1000 C:  5785 Min:   4 Act:    4 Avg:   4 Max:   6
    T: 5 (25554) P:95 I:1000 C:  5782 Min:   4 Act:    5 Avg:   4 Max:   6
    T: 6 (25555) P:95 I:1000 C:  5778 Min:   4 Act:    5 Avg:   4 Max:   6
    T: 7 (25556) P:95 I:1000 C:  5775 Min:   4 Act:    5 Avg:   4 Max:   6
    T: 8 (25557) P:95 I:1000 C:  5772 Min:   4 Act:    5 Avg:   4 Max:   6
    T: 9 (25558) P:95 I:1000 C:  5768 Min:   4 Act:    5 Avg:   4 Max:   6
    T:10 (25559) P:95 I:1000 C:  5765 Min:   4 Act:    5 Avg:   4 Max:   6
    T:11 (25560) P:95 I:1000 C:  5762 Min:   4 Act:    5 Avg:   4 Max:   6
    T:12 (25561) P:95 I:1000 C:  5758 Min:   5 Act:    5 Avg:   5 Max:   5
    T:13 (25562) P:95 I:1000 C:  5758 Min:   4 Act:    5 Avg:   4 Max:   5
    T:14 (25563) P:95 I:1000 C:  5758 Min:   4 Act:    5 Avg:   4 Max:   5
    T:15 (25564) P:95 I:1000 C:  5758 Min:   4 Act:    5 Avg:   4 Max:   5

Run at least 12/24 hours for rigid performance validation. For quick performance validation, 15 minutes is recommended.
Pay attention to the Avg. and Max. On a well-tuned platform, the numbers should be similar.

Build lib
===========

Testing in Baremetal
===========

Testing in Container
===========

Build O-DU docker image
-------------------------

Please follow the build procedures on baremetal host to build FAPI/WLS/FH and copy the code/binaries to the oran_release folder on your build server. The docker build will just copy the pre-built binaries to docker image.

    oran_release/phy
    oran_release/FlexRAN-FEC-SDK-19-04
    oran_release/FlexRAN
Set the network proxy and ORAN_RELEASE environment variable before build

    export http_proxy=<your_proxy>
    export https_proxy=<your_proxy>
    export no_proxy="localhost,127.0.0.1"
    export ORAN_RELEASE=<TOP_FOLDER>/oran_release
Update ${ORAN_RELEASE}/phy/setupenv.sh, change DIR_ROOT to /opt/oran_release. Run below script to trigger the docker build:

    sh ${ORAN_RELEASE}/FlexRAN/docker/build-oran-l1-image.sh
After the docker build finishes, docker image with oran-release tag will be generated

    …
    Successfully tagged oran-release-du:1.0

Run O-DU docker container in Kubernetes cluster
-------------------------------------------------

You can push the O-DU docker image to your local docker registry where Kubernetes cluster can pull the image. Or you can copy the image locally to your Kubernetes worker node. In your worker node, make sure you have configured the system/tools correctly following previous sections for running L1 in baremetal host.

* Assume intel system studio is installed in /opt/intel/system_studio_2019/
* Make sure you have enough 1G hugepages

Update the Kubernetes pod yaml configuration for your system configuration

    cat ${ORAN_RELEASE}/FlexRAN/docker/oran-release-du.yaml
    apiVersion: v1
    kind: Pod
    metadata:
      labels:
        app: oran-release-du-pod
      name: oran-release-du-pod
    spec:
      containers:
      - securityContext:
          privileged: false
          capabilities:
            add:
              - SYS_ADMIN
              - IPC_LOCK
              - SYS_NICE
        command:
          - sleep
          - infinity
        tty: true
        stdin: true
        image: oran-release-du:1.0
        name: l1app
        resources:
          requests:
            memory: "16Gi"
            hugepages-1Gi: 8Gi
          limits:
            memory: "16Gi"
            hugepages-1Gi: 8Gi
        volumeMounts:
        - name: hugepage
          mountPath: /hugepages
        - name: varrun
          mountPath: /var/run/dpdk
          readOnly: false
        - name: iss-path
          mountPath: /opt/intel/system_studio_2019/
      - securityContext:
          privileged: false
          capabilities:
            add:
              - SYS_ADMIN
              - IPC_LOCK
              - SYS_NICE
        command:
          - sleep
          - infinity
        tty: true
        stdin: true
        image: oran-release-du:1.0
        name: oran-fapi
        resources:
          requests:
            hugepages-1Gi: 4Gi
            memory: "4Gi"
          limits:
            hugepages-1Gi: 4Gi
            memory: "4Gi"
        volumeMounts:
        - name: hugepage
          mountPath: /hugepages
        - name: iss-path
          mountPath: /opt/intel/system_studio_2019/
        - name: varrun
          mountPath: /var/run/dpdk
          readOnly: false
      - securityContext:
          privileged: false
          capabilities:
            add:
              - SYS_ADMIN
              - IPC_LOCK
              - SYS_NICE
        command:
          - sleep
          - infinity
        tty: true
        stdin: true
        image: oran-release-du:1.0
        name: testmac
        resources:
          requests:
            memory: "4Gi"
          limits:
            memory: "4Gi"
        volumeMounts:
        - name: hugepage
          mountPath: /hugepages
        - name: iss-path
          mountPath: /opt/intel/system_studio_2019/
        - name: varrun
          mountPath: /var/run/dpdk
          readOnly: false
      volumes:
      - name: hugepage
        emptyDir:
          medium: HugePages
      - name: varrun
        emptyDir: {}
      - name: iss-path
        hostPath:
          path: /opt/intel/system_studio_2019/

Create the pod using kubectl

    kubectl create –f oran-release-du.yaml

After the pod/containers are running, login different containers (l1app, fapi, testmac) and start the applications.
Open first terminal and execute l1app container, and run l1app

    kubectl exec oran-release-du-pod -c l1app -it bash
    source /opt/oran_release/phy/setupenv.sh
    cd /opt/oran_release/FlexRAN/l1/bin/nr5g/gnb/l1/
    ./l1.sh -e
After l1app is started, open second terminal, execute oran-fapi container, and run fapi

    kubectl exec oran-release-du-pod -c oran-fapi -it bash
    source /opt/oran_release/phy/setupenv.sh
    cd /opt/oran_release/phy/fapi_5g/bin
    ./oran_5g_fapi.sh --cfg oran_5g_fapi.cfg
Open third terminal, execute testmac container, and run testmac

    kubectl exec oran-release-du-pod -c testmac -it bash
    source /opt/oran_release/phy/setupenv.sh   
    cd /opt/oran_release/FlexRAN/l1/bin/nr5g/gnb/testmac
    ./l2.sh --testfile oran_bronze_rel_fec_sw.cfg
After testmac container is started and running, you can see the test is running. You can check the terminal of each container to verify the test result.

Bit Exact Test Cases
===========


