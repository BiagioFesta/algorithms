# Algorithms

[![Algorithms Test Build](https://github.com/BiagioFesta/algorithms/actions/workflows/TestBuild.yml/badge.svg)](https://github.com/BiagioFesta/algorithms/actions/workflows/TestBuild.yml)
[![codecov](https://codecov.io/gh/BiagioFesta/algorithms/branch/master/graph/badge.svg?token=ex1ltEuNcK)](https://codecov.io/gh/BiagioFesta/algorithms)
[![cppstd](https://img.shields.io/badge/C++-17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)

## Brief Description

Study project on algorithm design and implementation in C++.

## Problem List
See the [Problems List Here](https://github.com/BiagioFesta/algorithms/blob/master/docs/GenTable/ProblemsListTable.md).

## How To Compile It
### Requirements
  * C++ compiler with C++17 support;
  * [CMake](https://cmake.org/).

### Commands

* Clone the repository and open the project directory:
```
git clone https://github.com/BiagioFesta/algorithms.git
```
```
cd algorithms
```

*  Create a build directory (linux commands):
```
cmake -E make_directory build
```
```
cd build
```

* Generate compilation files:
```
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DBUILD_BENCHMARKS=ON ..
```

* Run compilation:
```
cmake --build . --config Release
```
