cmake_minimum_required(VERSION 3.8)
project(algorithms)

set(SRC
  src/AlgStrings.cpp
  src/DynamicProgramming.cpp
  src/AlgArrays.cpp
  src/LRUCache.cpp
  src/BackTracking.cpp)
set(TEST
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

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup(TARGET)
endif()

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}_test ${SRC} ${TEST})
target_include_directories(${PROJECT_NAME}_test PRIVATE src/)
target_link_libraries(${PROJECT_NAME}_test GTest::GTest GTest::Main)
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_17)

include(CTest)
add_test(NAME TestAll COMMAND ${PROJECT_NAME}_test)
