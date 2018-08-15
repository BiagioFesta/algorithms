# Algorithms

[![Build Status](https://travis-ci.org/BiagioFesta/algorithms.svg?branch=master)](https://travis-ci.org/BiagioFesta/algorithms)
[![CodeCoverage](https://codecov.io/gh/BiagioFesta/algorithms/branch/master/graphs/badge.svg)](https://codecov.io/gh/BiagioFesta/algorithms/branch/master)

## Brief Description
Study project on algorithm design and implementation.

## Compilation
### Requirements
* Compiler support *C++17*.
* [GTest](https://github.com/google/googletest).

### Build
~~~
git clone https://github.com/BiagioFesta/algorithms.git && \
cd algorithms && \
mkdir build && \
cd build && \
cmake -DCMAKE_BUILD_TYPE=Debug .. && \
make && \
./algorithms_test
~~~
