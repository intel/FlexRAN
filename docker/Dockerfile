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

FROM centos:centos7.7.1908

ENV https_proxy $https_proxy
ENV http_proxy $http_proxy
ENV no_proxy $no_proxy

RUN yum update -y && yum install -y libhugetlbfs-utils libhugetlbfs-devel libhugetlbfs numactl-devel ethtool gcc make module-init-tools kmod patch xz iproute pciutils python vim cmake unzip nano mc iputils-ping libaio libaio-devel net-tools  wget zip expect-5.45-14.el7_1.x86_64

WORKDIR /opt/oran_release

ENV TARGET_DIR /opt/oran_release

COPY . $TARGET_DIR


