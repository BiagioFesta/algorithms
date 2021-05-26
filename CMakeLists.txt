cmake_minimum_required(VERSION 3.14)
project(algorithms)

option(BUILD_TESTS "Build Tests" ON)
option(BUILD_BENCHMARKS "Build Benchmarks" ON)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if(${BUILD_TESTS})
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()

if(${BUILD_BENCHMARKS})
  add_subdirectory(${PROJECT_SOURCE_DIR}/benchmarks)
endif()
