cmake_minimum_required(VERSION 3.8)
project(algorithms)

add_library(SRC_CORE INTERFACE)
target_sources(SRC_CORE INTERFACE
  ${PROJECT_SOURCE_DIR}/src/AlgStrings.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming.cpp
  ${PROJECT_SOURCE_DIR}/src/AlgArrays.cpp
  ${PROJECT_SOURCE_DIR}/src/LRUCache.cpp
  ${PROJECT_SOURCE_DIR}/src/BackTracking.cpp)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup(TARGET)
endif()

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}_test
  test/main.cpp
  test/testAlgStrings.cpp
  test/testDynamicProgramming.cpp
  test/testAlgArrays.cpp
  test/testMinStack.cpp
  test/testUtilities.cpp
  test/testLRUCache.cpp
  test/testBST.cpp
  test/testPriorityQueue.cpp
  test/testBackTracking.cpp
  test/testFlatSet.cpp)
target_include_directories(${PROJECT_NAME}_test PRIVATE src/)
target_link_libraries(${PROJECT_NAME}_test SRC_CORE GTest::GTest GTest::Main)
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_17)

include(CTest)
add_test(NAME TestAll COMMAND ${PROJECT_NAME}_test)

option(BUILD_BENCHMARK "Compile Benchmark program" NO)
if(${BUILD_BENCHMARK})
  find_package(benchmark REQUIRED)

  set(SRC_BENCHMARK
    benchmark/main.cpp
    benchmark/benchmarkFlatSetVsSet.cpp
    benchmark/benchmarkRadixSort.cpp)

  add_executable(${PROJECT_NAME}_benchmark ${SRC_BENCHMARK})
  target_include_directories(${PROJECT_NAME}_benchmark PRIVATE src/)
  target_link_libraries(${PROJECT_NAME}_benchmark PRIVATE SRC_CORE benchmark::benchmark)
  target_compile_features(${PROJECT_NAME}_benchmark PRIVATE cxx_std_17)
endif()
