enable_testing()
include(GoogleTest)
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG a3460d1aeeaa43fdf137a6adefef10ba0b59fe4b)
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
set(BUILD_GMOCK
    OFF
    CACHE BOOL "" FORCE)
set(INSTALL_GTEST
    OFF
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(algorithms_tests)
target_link_libraries(algorithms_tests PRIVATE algorithms gtest gtest_main)

add_subdirectory(Array)
add_subdirectory(BackTracking)
add_subdirectory(BinaryIndexedTree)
add_subdirectory(BST)
add_subdirectory(CTCI)
add_subdirectory(DynamicProgramming)
add_subdirectory(FlatSet)
add_subdirectory(Graph)
add_subdirectory(LRUCache)
add_subdirectory(Matrix)
add_subdirectory(MinStack)
add_subdirectory(Misc)
add_subdirectory(PriorityQueue)
add_subdirectory(String)
add_subdirectory(Trie)
add_subdirectory(Twitter)

gtest_add_tests(TARGET algorithms_tests)

install(TARGETS algorithms_tests)
