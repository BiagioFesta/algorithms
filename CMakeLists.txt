cmake_minimum_required(VERSION 3.1)
project(algorithms)

set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${PROJECT_SOURCE_DIR}/cmake)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(SRC
  src/AlgStrings.cpp
  src/DynamicProgramming.cpp
  src/AlgArrays.cpp
  src/LRUCache.cpp)
set(TEST
  test/main.cpp
  test/testAlgStrings.cpp
  test/testDynamicProgramming.cpp
  test/testAlgArrays.cpp
  test/testMinStack.cpp
  test/testUtilities.cpp
  test/testLRUCache.cpp)

add_executable(${PROJECT_NAME}_test ${SRC} ${TEST})
target_include_directories(${PROJECT_NAME}_test
  PRIVATE ${GTEST_INCLUDE_DIRS}
  PRIVATE src/)
target_link_libraries(${PROJECT_NAME}_test
  ${GTEST_BOTH_LIBRARIES}
  Threads::Threads)
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_17)

include(CTest)
add_test(NAME TestAll COMMAND ${PROJECT_NAME}_test)
