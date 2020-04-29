FROM ubuntu:19.10
MAINTAINER Biagio Festa

ENV ALGORITHMS_BUILD_TYPE Release
ENV ALGORITHMS_HOME /opt/algorithms
ENV ALGORITHMS_BUILD_BENCHMARKS YES
ENV ALGORITHMS_REPOSITORY https://github.com/BiagioFesta/algorithms.git
ENV ALGORITHMS_CXX_FLAGS "-flto"
ENV ALGORITHMS_EXE_LINKER_FLAGS "-flto"

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
  cmake \
  -DCMAKE_INSTALL_PREFIX=${ALGORITHMS_HOME} \
  -DCMAKE_BUILD_TYPE=${ALGORITHMS_BUILD_TYPE} \
  -DCMAKE_CXX_FLAGS=${ALGORITHMS_CXX_FLAGS} \
  -DCMAKE_EXE_LINKER_FLAGS=${ALGORITHMS_EXE_LINKER_FLAGS} \
  -DBUILD_BENCHMARK=${ALGORITHMS_BUILD_BENCHMARKS} \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=YES \
  .. && \
  cmake --build . && \
  cmake --build . --target install
