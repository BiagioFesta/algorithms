FROM ubuntu:18.10
MAINTAINER Biagio Festa

ENV ALGORITHMS_BUILD_TYPE Release
ENV ALGORITHMS_HOME /opt/algorithms
ENV ALGORITHMS_BUILD_BENCHMARKS YES
ENV ALGORITHMS_REPOSITORY https://github.com/BiagioFesta/algorithms.git

# Install dependencies
RUN apt-get update && \
  apt-get install -y gcc g++ cmake make python3 python3-pip git

# Install conan
RUN pip3 install conan

# Add conan remote
RUN conan remote add conan-mpusz https://api.bintray.com/conan/mpusz/conan-mpusz

# Download and compile repository
RUN cd ${HOME} && \
  git clone ${ALGORITHMS_REPOSITORY} && \
  cd algorithms && \
  mkdir build && \
  cd build && \
  conan install --settings build_type=${ALGORITHMS_BUILD_TYPE} --settings compiler.libcxx=libstdc++11 --build=missing .. && \
  cmake -DCMAKE_INSTALL_PREFIX=${ALGORITHMS_HOME} -DCMAKE_BUILD_TYPE=${ALGORITHMS_BUILD_TYPE} -DBUILD_BENCHMARK=${ALGORITHMS_BUILD_BENCHMARKS} .. && \
  cmake --build . && \
  cmake --build . --target install
