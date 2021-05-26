include(FetchContent)

FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.5.3)
set(BENCHMARK_ENABLE_TESTING
    OFF
    CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL
    OFF
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googlebenchmark)

add_executable(algorithms_benchmarks)
target_sources(
  algorithms_benchmarks
  PRIVATE benchmarkDailyTemperatures.cpp
          benchmarkFlatSetVsSet.cpp
          benchmarkHIndex.cpp
          benchmarkMatrix2D.cpp
          benchmarkOnesAndZeroes.cpp
          benchmarkRadixSort.cpp
          benchmarkSearchRotatedSortedArray.cpp
          benchmarkTemplateTest.cpp
          benchmarkTreeVsHash.cpp)
target_link_libraries(algorithms_benchmarks PRIVATE algorithms benchmark benchmark_main)
install(TARGETS algorithms_benchmarks)
