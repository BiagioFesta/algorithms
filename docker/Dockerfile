FROM ubuntu:latest
MAINTAINER Biagio Festa

# Install dependencies
RUN apt-get update && \
    apt-get install -y gcc g++ cmake make git libgtest-dev

# Compile Gtest
RUN cd /usr/src/gtest && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .. && \
    make && \
    make install

# Compile Project
RUN cd /root && \
    git clone https://github.com/BiagioFesta/algorithms.git && \
    cd algorithms && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_BUILD_TYPE=Debug .. && \
    make

