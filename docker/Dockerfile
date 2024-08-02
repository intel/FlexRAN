################################################################################
#   Copyright (c) 2019 Intel.                             #
#                                                                              #
#   Licensed under the Apache License, Version 2.0 (the "License");            #
#   you may not use this file except in compliance with the License.           #
#   You may obtain a copy of the License at                                    #
#                                                                              #
#       http://www.apache.org/licenses/LICENSE-2.0                             #
#                                                                              #
#   Unless required by applicable law or agreed to in writing, software        #
#   distributed under the License is distributed on an "AS IS" BASIS,          #
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   #
#   See the License for the specific language governing permissions and        #
#   limitations under the License.                                             #
################################################################################

FROM ubuntu:22.04

ENV https_proxy $https_proxy
ENV http_proxy $http_proxy
ENV no_proxy $no_proxy

RUN apt update
RUN apt upgrade -y
RUN apt install -y build-essential libhugetlbfs-bin libhugetlbfs-dev libtool-bin cmake python3-pip tcpdump net-tools bc cmake wget  pciutils vim tcpdump ntpdate driverctl lshw numactl linux-tools-common libnuma-dev xterm pkg-config  rt-tests git libtool libcrypto++-dev linux-tools-generic vim python3 pciutils

WORKDIR /opt/oran_release

ENV TARGET_DIR /opt/oran_release

COPY . $TARGET_DIR


