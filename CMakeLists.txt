cmake_minimum_required(VERSION 3.8)
project(algorithms)

add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME}
  PRIVATE
  ${PROJECT_SOURCE_DIR}/src/Array/AbsolutePermutation.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/AdvantageShuffle.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/AreAllDistant.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/ArrayDoubledPairs.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/AsteroidCollision.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/BestSightseeingPair.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/ClimbingLeaderboard.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/ContainsDuplicateIII.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/ContainsNearbyDuplicate.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/ContiguousArray.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/DeckIncreasingReveal.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/DistantBarcodes.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/EuclideanAlgorithmGCD.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/Find132Pattern.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/FindDisappearedNumbers.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/FindKClosestElements.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/FindKLargest.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/FindLengthOfLCIS.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/FirstMissingPositive.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/FourSum.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/FruitIntoBaskets.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/GlobalLocalInversions.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/HIndex.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/InsertInterval.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/IsOneBitCharacter.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/IsPalindrome.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/IsPermutation.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/JumpGame2.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/KeysAndRooms.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/KokoEatingBananas.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/LargestNumber.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/LarrysArray.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/LongestMountainArray.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/MajorityElementII.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/MaxWidthRamp.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/MaximumAbsoluteValueExpression.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/MaximumGap.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/MaximumProduct.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/MinimumSizeSubarraySum.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/NextPermutation.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/NonDecreasingArray.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/NumOfIslands.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/Pairs.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/Partition.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/PlusOne.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/RadixSort.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/RotateRight.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/SearchRotatedSortedArray.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/SieveOfEratosthenes.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/SingleElementInSortedArray.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/SortColors.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/StockMaximize.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/SubarraySumEqualsK.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/Subsets.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/ThreeSum.cpp
  ${PROJECT_SOURCE_DIR}/src/Array/ValidateStackSequences.cpp
  ${PROJECT_SOURCE_DIR}/src/BackTracking/CombinationSum.cpp
  ${PROJECT_SOURCE_DIR}/src/BackTracking/CombinationSum3.cpp
  ${PROJECT_SOURCE_DIR}/src/BackTracking/LetterCombinationsPhoneNumber.cpp
  ${PROJECT_SOURCE_DIR}/src/BackTracking/NumbersConsecutiveDifferences.cpp
  ${PROJECT_SOURCE_DIR}/src/BackTracking/PalindromePartitioning.cpp
  ${PROJECT_SOURCE_DIR}/src/BackTracking/WildcardMatching.cpp
  ${PROJECT_SOURCE_DIR}/src/BackTracking/WordSearch.cpp
  ${PROJECT_SOURCE_DIR}/src/CTCI/Chapter2/KthToLast.cpp
  ${PROJECT_SOURCE_DIR}/src/CTCI/Chapter2/RemoveDuplicates.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/BinomialCoefficient.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/CheapestJump.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/CoinChange.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/Fibonacci.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/FindRotateSteps.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/HouseRobberII.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/IntegerBreak.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/Keystroke.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/LongestCommonSubsequence.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/MaxProfit.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/MinPathSum.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/MinSwap.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/OnesAndZeroes.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/PartitionEqualSubSum.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/SherlockAndCost.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/SubstringsSum.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/TallestBillboard.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/TargetSum.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/TwoEggsDropping.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/TwoKeysKeyboard.cpp
  ${PROJECT_SOURCE_DIR}/src/DynamicProgramming/UniquePathsWithObstacles.cpp
  ${PROJECT_SOURCE_DIR}/src/Graph/BusRoutes.cpp
  ${PROJECT_SOURCE_DIR}/src/Graph/CourseSchedule.cpp
  ${PROJECT_SOURCE_DIR}/src/Graph/CourseScheduleII.cpp
  ${PROJECT_SOURCE_DIR}/src/Graph/MinimumGeneticMutation.cpp
  ${PROJECT_SOURCE_DIR}/src/Graph/NetworkDelayTime.cpp
  ${PROJECT_SOURCE_DIR}/src/LRUCache/LRUCache.cpp
  ${PROJECT_SOURCE_DIR}/src/Misc/BrokenCalculator.cpp
  ${PROJECT_SOURCE_DIR}/src/Misc/FindItinerary.cpp
  ${PROJECT_SOURCE_DIR}/src/Misc/IsPerfectSquare.cpp
  ${PROJECT_SOURCE_DIR}/src/Misc/KSymbolInGrammar.cpp
  ${PROJECT_SOURCE_DIR}/src/String/AlphabetBoardPath.cpp
  ${PROJECT_SOURCE_DIR}/src/String/BiggerIsGreater.cpp
  ${PROJECT_SOURCE_DIR}/src/String/CheckRecord.cpp
  ${PROJECT_SOURCE_DIR}/src/String/CountSegment.cpp
  ${PROJECT_SOURCE_DIR}/src/String/DecodeString.cpp
  ${PROJECT_SOURCE_DIR}/src/String/DetectCapitalUse.cpp
  ${PROJECT_SOURCE_DIR}/src/String/EncryptionStr.cpp
  ${PROJECT_SOURCE_DIR}/src/String/FindAllAnagramsString.cpp
  ${PROJECT_SOURCE_DIR}/src/String/FindAndReplacePattern.cpp
  ${PROJECT_SOURCE_DIR}/src/String/FindLongestWord.cpp
  ${PROJECT_SOURCE_DIR}/src/String/FindTheDifference.cpp
  ${PROJECT_SOURCE_DIR}/src/String/FrequencySort.cpp
  ${PROJECT_SOURCE_DIR}/src/String/IsPermutation.cpp
  ${PROJECT_SOURCE_DIR}/src/String/KSimilarStrings.cpp
  ${PROJECT_SOURCE_DIR}/src/String/LenLastWord.cpp
  ${PROJECT_SOURCE_DIR}/src/String/LetterCasePermutation.cpp
  ${PROJECT_SOURCE_DIR}/src/String/LongestPalindrome.cpp
  ${PROJECT_SOURCE_DIR}/src/String/MaxLenSubWithoutRep.cpp
  ${PROJECT_SOURCE_DIR}/src/String/MinAddParentheses.cpp
  ${PROJECT_SOURCE_DIR}/src/String/MinimumWindowSubstring.cpp
  ${PROJECT_SOURCE_DIR}/src/String/OneWay.cpp
  ${PROJECT_SOURCE_DIR}/src/String/OriginalDigits.cpp
  ${PROJECT_SOURCE_DIR}/src/String/PalindromePermutation.cpp
  ${PROJECT_SOURCE_DIR}/src/String/RepeatedDNASequences.cpp
  ${PROJECT_SOURCE_DIR}/src/String/ReverseStringInPlace.cpp
  ${PROJECT_SOURCE_DIR}/src/String/SteadyGene.cpp
  ${PROJECT_SOURCE_DIR}/src/String/StrStr.cpp
  ${PROJECT_SOURCE_DIR}/src/String/StringCompression.cpp
  ${PROJECT_SOURCE_DIR}/src/String/URLify.cpp
  ${PROJECT_SOURCE_DIR}/src/Trie/SimpleTrie.cpp
  ${PROJECT_SOURCE_DIR}/src/Twitter/Twitter.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup(TARGETS)
endif()

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}_test
  ${PROJECT_SOURCE_DIR}/test/Array/testAbsolutePermutation.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testAdvantageShuffle.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testAreAllDistant.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testArrayDoubledPairs.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testAsteroidCollision.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testBestSightseeingPair.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testClimbingLeaderboard.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testContainsDuplicateIII.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testContainsNearbyDuplicate.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testContiguousArray.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testDeckIncreasingReveal.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testDistantBarcodes.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testEuclideanAlgorithmGCD.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testFind132Pattern.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testFindDisappearedNumbers.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testFindKClosestElements.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testFindKLargest.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testFindLengthOfLCIS.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testFirstMissingPositive.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testFourSum.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testFruitIntoBaskets.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testGlobalLocalInversions.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testHIndex.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testInsertInterval.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testIsOneBitCharacter.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testIsPalindrome.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testIsPermutation.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testJumpGame2.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testKeysAndRooms.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testKokoEatingBananas.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testLargestNumber.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testLarrysArray.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testLongestMountainArray.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testMajorityElementII.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testMaxWidthRamp.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testMaximumAbsoluteValueExpression.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testMaximumGap.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testMaximumProduct.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testMinimumSizeSubarraySum.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testNextPermutation.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testNonDecreasingArray.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testNumOfIslands.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testPairs.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testPartition.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testPlusOne.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testRadixSort.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testRotateRight.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testSearchRotatedSortedArray.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testSieveOfEratosthenes.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testSingleElementInSortedArray.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testSortColors.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testStockMaximize.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testSubarraySumEqualsK.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testSubsets.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testThreeSum.cpp
  ${PROJECT_SOURCE_DIR}/test/Array/testValidateStackSequences.cpp
  ${PROJECT_SOURCE_DIR}/test/BST/testBST.cpp
  ${PROJECT_SOURCE_DIR}/test/BackTracking/testCombinationSum.cpp
  ${PROJECT_SOURCE_DIR}/test/BackTracking/testCombinationSum3.cpp
  ${PROJECT_SOURCE_DIR}/test/BackTracking/testLetterCombinationsPhoneNumber.cpp
  ${PROJECT_SOURCE_DIR}/test/BackTracking/testNumbersConsecutiveDifferences.cpp
  ${PROJECT_SOURCE_DIR}/test/BackTracking/testPalindromePartitioning.cpp
  ${PROJECT_SOURCE_DIR}/test/BackTracking/testWildcardMatching.cpp
  ${PROJECT_SOURCE_DIR}/test/BackTracking/testWordSearch.cpp
  ${PROJECT_SOURCE_DIR}/test/CTCI/Chapter2/testDoubleLinkedList.cpp
  ${PROJECT_SOURCE_DIR}/test/CTCI/Chapter2/testKthToLast.cpp
  ${PROJECT_SOURCE_DIR}/test/CTCI/Chapter2/testRemoveDuplicates.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testBinomialCoefficient.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testCheapestJump.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testCoinChange.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testFibonacci.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testFindRotateSteps.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testHouseRobberII.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testIntegerBreak.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testKeystroke.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testLongestCommonSubsequence.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testMaxProfit.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testMinPathSum.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testMinSwap.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testOnesAndZeroes.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testPartitionEqualSubSum.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testSherlockAndCost.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testSubstringsSum.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testTallestBillboard.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testTargetSum.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testTwoEggsDropping.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testTwoKeysKeyboard.cpp
  ${PROJECT_SOURCE_DIR}/test/DynamicProgramming/testUniquePathsWithObstacles.cpp
  ${PROJECT_SOURCE_DIR}/test/FlatSet/testFlatSet.cpp
  ${PROJECT_SOURCE_DIR}/test/Graph/testBusRoutes.cpp
  ${PROJECT_SOURCE_DIR}/test/Graph/testCourseSchedule.cpp
  ${PROJECT_SOURCE_DIR}/test/Graph/testCourseScheduleII.cpp
  ${PROJECT_SOURCE_DIR}/test/Graph/testMinimumGeneticMutation.cpp
  ${PROJECT_SOURCE_DIR}/test/Graph/testNetworkDelayTime.cpp
  ${PROJECT_SOURCE_DIR}/test/LRUCache/testLRUCache.cpp
  ${PROJECT_SOURCE_DIR}/test/Matrix/testMatrix2D.cpp
  ${PROJECT_SOURCE_DIR}/test/MinStack/testMinStack.cpp
  ${PROJECT_SOURCE_DIR}/test/Misc/testBrokenCalculator.cpp
  ${PROJECT_SOURCE_DIR}/test/Misc/testFindItinerary.cpp
  ${PROJECT_SOURCE_DIR}/test/Misc/testIsPerfectSquare.cpp
  ${PROJECT_SOURCE_DIR}/test/Misc/testKSymbolInGrammar.cpp
  ${PROJECT_SOURCE_DIR}/test/PriorityQueue/testPriorityQueue.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testAlphabetBoardPath.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testBiggerIsGreater.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testCheckRecord.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testCountSegment.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testDecodeString.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testDetectCapitalUse.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testEncryptionStr.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testFindAllAnagramsString.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testFindAndReplacePattern.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testFindLongestWord.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testFindTheDifference.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testFrequencySort.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testIsPermutation.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testKSimilarStrings.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testLenLastWord.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testLetterCasePermutation.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testLongestPalindrome.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testMaxLenSubWithoutRep.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testMinAddParentheses.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testMinimumWindowSubstring.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testOneWay.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testOriginalDigits.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testPalindromePermutation.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testRepeatedDNASequences.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testReverseStringInPlace.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testSteadyGene.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testStrStr.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testStringCompression.cpp
  ${PROJECT_SOURCE_DIR}/test/String/testURLify.cpp
  ${PROJECT_SOURCE_DIR}/test/Trie/testSimpleTrie.cpp
  ${PROJECT_SOURCE_DIR}/test/Twitter/testTwitter.cpp)
target_link_libraries(${PROJECT_NAME}_test
  PRIVATE ${PROJECT_NAME}
  PRIVATE CONAN_PKG::gtest)

get_target_property(INSTALL_INCLUDES ${PROJECT_NAME} INTERFACE_INCLUDE_DIRECTORIES)
install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_test
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
install(DIRECTORY ${INSTALL_INCLUDES} DESTINATION .)

include(CTest)
add_test(NAME TestAll COMMAND ${PROJECT_NAME}_test)

option(BUILD_BENCHMARK "Compile Benchmark program" NO)
if(${BUILD_BENCHMARK})
  find_package(benchmark REQUIRED)
  find_package(Threads REQUIRED)

  add_executable(${PROJECT_NAME}_benchmark
    ${PROJECT_SOURCE_DIR}/benchmark/benchmarkFlatSetVsSet.cpp
    ${PROJECT_SOURCE_DIR}/benchmark/benchmarkHIndex.cpp
    ${PROJECT_SOURCE_DIR}/benchmark/benchmarkMatrix2D.cpp
    ${PROJECT_SOURCE_DIR}/benchmark/benchmarkOnesAndZeroes.cpp
    ${PROJECT_SOURCE_DIR}/benchmark/benchmarkRadixSort.cpp
    ${PROJECT_SOURCE_DIR}/benchmark/benchmarkSearchRotatedSortedArray.cpp
    ${PROJECT_SOURCE_DIR}/benchmark/benchmarkTemplateTest.cpp
    ${PROJECT_SOURCE_DIR}/benchmark/benchmarkTreeVsHash.cpp
    ${PROJECT_SOURCE_DIR}/benchmark/main.cpp)

  if (MSVC)
    set(ADDITIONAL_DEPENDENCIES Shlwapi.lib)
  endif()

  target_link_libraries(${PROJECT_NAME}_benchmark
    PRIVATE ${PROJECT_NAME}
    PRIVATE CONAN_PKG::google-benchmark
    PRIVATE Threads::Threads
    ${ADDITIONAL_DEPENDENCIES})

  install(TARGETS ${PROJECT_NAME}_benchmark RUNTIME DESTINATION bin)
endif()
