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

Build lib
===========

Testing in Baremetal
===========

Testing in Container
===========

Bit Exact Test Cases
===========


