cmake_minimum_required(VERSION 3.1)
project(algorithms)

set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${PROJECT_SOURCE_DIR}/cmake)

find_package(GTest REQUIRED)

set(SRC
  src/easyStrings.cpp
  src/dynamicProgramming.cpp)
set(TEST
  test/main.cpp
  test/testEasyStrings.cpp
  test/testDynamicProgramming.cpp)

add_executable(${PROJECT_NAME}_test ${SRC} ${TEST})
target_include_directories(${PROJECT_NAME}_test
  PRIVATE ${GTEST_INCLUDE_DIRS}
  PRIVATE src/)
target_link_libraries(${PROJECT_NAME}_test ${GTEST_BOTH_LIBRARIES})
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_17)
