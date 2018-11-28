/*
  Copyright (C) 2018  Biagio Festa

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include <gtest/gtest.h>
#include <AlgArrays.hpp>
#include <Utilities.hpp>
#include <algorithm>
#include <random>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(AlgArrays, isAlmostNonDecreasing) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> TestCases = {
      {{4, 2, 3}, true}, {{4, 2, 1}, false}, {{3, 4, 2, 3}, false}};

  for (const auto& [str, exp] : TestCases) {
    ASSERT_EQ(isAlmostNonDecreasing(str.data(), str.size()), exp);
  }
}

TEST(AlgArrays, minSizeSubArraySum) {
  const std::vector<int> kData1 = {2, 3, 1, 2, 4, 3};
  ASSERT_EQ(minSizeSubArraySum(kData1.data(), kData1.size(), 7), 2);

  const std::vector<int> kData2 = {1};
  ASSERT_EQ(minSizeSubArraySum(kData2.data(), kData2.size(), 7), 0);

  const std::vector<int> kData3 = {1, 1, 4, 3, 1, 1, 1};
  ASSERT_EQ(minSizeSubArraySum(kData3.data(), kData3.size(), 7), 2);

  const std::vector<int> kData4 = {};
  ASSERT_EQ(minSizeSubArraySum(kData4.data(), kData4.size(), 100), 0);

  const std::vector<int> kData5 = {
      12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
  ASSERT_EQ(minSizeSubArraySum(kData5.data(), kData5.size(), 213), 8);
}

TEST(AlgArrays, findDisappearedNumbers) {
  using Test = std::pair<std::vector<int>, std::vector<int>>;

  const Test test1 = {{4, 3, 2, 7, 8, 2, 3, 1}, {5, 6}};
  const auto result1 = findDisappearedNumbers(test1.first);
  ASSERT_TRUE(checkStrictEqualityContainers(result1, test1.second));
}

TEST(AlgArrays, findLengthOfLCIS) {
  using Test = std::pair<std::vector<int>, int>;

  const Test test1 = {{1, 3, 5, 4, 7}, 3};
  ASSERT_EQ(findLengthOfLCIS(test1.first), test1.second);

  const Test test2 = {{2, 2, 2, 2}, 1};
  ASSERT_EQ(findLengthOfLCIS(test2.first), test2.second);

  const Test test3 = {{}, 0};
  ASSERT_EQ(findLengthOfLCIS(test3.first), test3.second);

  const Test test4 = {{1}, 1};
  ASSERT_EQ(findLengthOfLCIS(test4.first), test4.second);
}

TEST(AlgArrays, firstMissingPositive) {
  using Test = std::pair<std::vector<int>, int>;

  Test test1 = {{1, 2, 0}, 3};
  ASSERT_EQ(firstMissingPositive(&test1.first), test1.second);

  Test test2 = {{3, 4, -1, 1}, 2};
  ASSERT_EQ(firstMissingPositive(&test2.first), test2.second);

  Test test3 = {{7, 8, 9, 11, 12}, 1};
  ASSERT_EQ(firstMissingPositive(&test3.first), test3.second);

  Test test4 = {{1, 2, 3, 4, 5}, 6};
  ASSERT_EQ(firstMissingPositive(&test4.first), test4.second);
}

TEST(AlgArrays, climbingLeaderboard) {
  using Test = std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>;
  const std::vector<Test> testCases = {
      {{100, 100, 50, 40, 40, 20, 10}, {5, 25, 50, 120}, {6, 4, 2, 1}}};

  for (const auto& [board, alice, expt] : testCases) {
    ASSERT_TRUE(
        checkStrictEqualityContainers(climbingLeaderboard(board, alice), expt));
  }
}

TEST(AlgArrays, larrysArray) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{3, 1, 2}, true},
                                       {{1, 3, 4, 2}, true},
                                       {{1, 2, 3, 5, 4}, false},
                                       {{1, 6, 5, 2, 4, 3}, true}};

  for (const auto& [vect, expt] : testCases) {
    EXPECT_EQ(larrysArray(vect), expt);
  }
}

TEST(AlgArrays, absolutePermutation) {
  using Test = std::tuple<int, int, std::vector<int>>;
  const std::vector<Test> testCases = {
      {2, 1, {2, 1}},
      {3, 0, {1, 2, 3}},
      {3, 2, {-1}},
      {10, 1, {2, 1, 4, 3, 6, 5, 8, 7, 10, 9}}};

  for (const auto& [n, k, expt] : testCases) {
    ASSERT_TRUE(checkStrictEqualityContainers(absolutePermutation(n, k), expt));
  }
}

TEST(AlgArrays, addOneToNumber) {
  using Test = std::pair<std::vector<int>, std::vector<int>>;
  const std::vector<Test> testCases = {{{1, 2, 3}, {1, 2, 4}},
                                       {{0}, {1}},
                                       {{9}, {1, 0}},
                                       {{9, 9, 9}, {1, 0, 0, 0}},
                                       {{0, 0, 1, 2}, {1, 3}}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_TRUE(checkStrictEqualityContainers(addOneToNumber(v), expt));
  }
}

TEST(AlgArrays, largestNumber) {
  using Test = std::pair<std::vector<int>, std::string>;
  const std::vector<Test> testCases = {{{3, 30, 34, 5, 9}, "9534330"},
                                       {{0, 0, 0, 0, 0}, "0"}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(largestNumber(v), expt);
  }
}

TEST(AlgArrays, maximumGap) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {{{3, 5, 4, 2}, 2},
                                       {{1, 10}, 1},
                                       {{-1, -1, -1, 2}, 3},
                                       {{1, 2, 2, 2, 2}, 4}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(maximumGap(v), expt);
  }
}

TEST(AlgArrays, isOneBitCharacter) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{1, 1, 0}, true},
                                       {{1, 0, 0}, true},
                                       {{1, 1, 1, 0}, false},
                                       {{0}, true},
                                       {{0, 0}, true}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(isOneBitCharacter(v), expt);
  }
}

TEST(AlgArrays, findMaxLength) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {{{0, 1}, 2},
                                       {{0, 1, 0}, 2},
                                       {{0, 1, 0, 1}, 4},
                                       {{0, 0, 0, 1, 0, 1, 0}, 4}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(findMaxLength(v), expt);
  }
}

TEST(AlgArrays, pairs) {
  using Test = std::tuple<std::vector<int>, int, int>;
  const std::vector<Test> testCases = {{{1, 5, 3, 4, 2}, 2, 3},
                                       {{1, 3, 5, 8, 6, 4, 2}, 2, 5}};

  for (const auto& [nums, target, expt] : testCases) {
    ASSERT_EQ(pairs(nums, target), expt);
  }
}

TEST(AlgArrays, containsNearbyDuplicate) {
  using Test = std::tuple<std::vector<int>, int, bool>;
  const std::vector<Test> testCases = {{{1, 2, 3, 1}, 3, true},
                                       {{1, 0, 1, 1}, 1, true},
                                       {{1, 2, 3, 1, 2, 3}, 2, false},
                                       {{1, 2, 3, 1, 1, 2, 3}, 0, false}};

  for (const auto& [nums, k, expt] : testCases) {
    ASSERT_EQ(containsNearbyDuplicate(nums, k), expt);
  }
}

TEST(AlgArrays, isPermutation) {
  using Test = std::tuple<std::vector<int>, std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{1, 2, 3}, {3, 1, 2}, true},
                                       {{1, 2, 3}, {1, 2}, false},
                                       {{1, 2, 3}, {3, 2, 4}, false}};

  for (const auto& [v1, v2, expt] : testCases) {
    ASSERT_EQ(isPermutation(v1, v2), expt);
  }
}

TEST(AlgArrays, stockMax) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {{{1, 2}, 1},
                                       {{2, 1}, 0},
                                       {{5, 3, 2}, 0},
                                       {{1, 2, 100}, 197},
                                       {{1, 3, 1, 2}, 3},
                                       {{5, 4, 3, 4, 5}, 4},
                                       {{}, 0}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(stockMax(v), expt);
  }
}

TEST(AlgArrays, isPalindrome) {
  using Test = std::pair<int, bool>;
  const std::vector<Test> testCases = {{121, true},
                                       {-121, false},
                                       {10, false},
                                       {0, true},
                                       {12344321, true},
                                       {123421, false},
                                       {1000000001, true}};

  for (const auto [num, expt] : testCases) {
    ASSERT_EQ(isPalindrome(num), expt);
  }
}

TEST(AlgArrays, threeSum) {
  using Test = std::pair<std::vector<int>, std::vector<std::vector<int>>>;

  std::vector<Test> testCases = {
      {{-1, 0, 1, 2, -1, -4}, {{-1, 0, 1}, {-1, -1, 2}}}, {{-1, 0}, {}}};

  for (auto [nums, expt] : testCases) {
    const auto aResult = threeSum(&nums);

    ASSERT_EQ(aResult.size(), expt.size());

    for (const auto& aTripletResutl : aResult) {
      auto aFinder = std::find_if(
          expt.begin(), expt.end(), [&aTripletResutl](const auto& iTriplet) {
            return std::is_permutation(iTriplet.cbegin(),
                                       iTriplet.cend(),
                                       aTripletResutl.cbegin(),
                                       aTripletResutl.cend());
          });

      ASSERT_NE(aFinder, expt.end());

      expt.erase(aFinder);
    }
  }
}

TEST(AlgArrays, partition) {
  using Test = std::pair<std::vector<int>, std::function<bool(int)>>;

  static const auto isLessThanFive = [](const int iNumber) {
    return iNumber < 5;
  };

  std::vector<Test> testCases = {{{1, 2, 3, 4, 5, 6}, isLessThanFive},
                                 {{1, 2, 10, 11, 3}, isLessThanFive},
                                 {{}, isLessThanFive},
                                 {{1, 2, 3}, isLessThanFive},
                                 {{6, 7, 8}, isLessThanFive}};

  for (auto& [v, fn] : testCases) {
    partition(&v, fn);
    ASSERT_TRUE(std::is_partitioned(v.cbegin(), v.cend(), fn));
  }
}

TEST(AlgArrays, find132pattern) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{1, 2, 3, 4}, false},
                                       {{3, 1, 4, 2}, true},
                                       {{-1, 3, 2, 0}, true},
                                       {{}, false}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(find132pattern(v), expt);
  }
}

TEST(AlgArrays, euclideanAlgorithmGCD) {
  using Test = std::tuple<int, int, int>;
  const std::vector<Test> testCases = {{3, 3, 3},
                                       {1024, 0, 1024},
                                       {3, 2, 1},
                                       {12, 6, 6},
                                       {32, 15, 1},
                                       {36, 144, 36},
                                       {8, 12, 4}};

  for (const auto [i, j, expt] : testCases) {
    ASSERT_EQ(euclideanAlgorithmGCD(i, j), expt);
    ASSERT_EQ(euclideanAlgorithmGCD(i, j), euclideanAlgorithmGCD(j, i));
  }
}

TEST(AlgArrays, sieveOfEratosthenes) {
  using Test = std::pair<int, std::vector<int>>;
  const std::vector<Test> testCases = {
      {1, {}},
      {2, {2}},
      {3, {2, 3}},
      {10, {2, 3, 5, 7}},
      {50, {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}}};

  for (const auto& [n, expt] : testCases) {
    ASSERT_EQ(sieveOfEratosthenes(n), expt);
  }
}

TEST(AlgArrays, radixSort) {
  using RndEngine_t = std::mt19937_64;
  constexpr int kNumTest = 64;
  constexpr std::size_t kMaxSize = 64;

  RndEngine_t aRndEngine;
  std::uniform_int_distribution<unsigned int> aDistribution;

  std::vector<unsigned int> aVector, aSortedVector;

  for (int i = 0; i < kNumTest; ++i) {
    aVector.resize(aDistribution(aRndEngine) % kMaxSize);
    std::generate(
        aVector.begin(), aVector.end(), [&aRndEngine, &aDistribution]() {
          return aDistribution(aRndEngine);
        });

    aSortedVector = aVector;
    radixSort(&aSortedVector);

    ASSERT_TRUE(std::is_sorted(aSortedVector.cbegin(), aSortedVector.cend()));
    ASSERT_TRUE(std::is_permutation(aSortedVector.cbegin(),
                                    aSortedVector.cend(),
                                    aVector.cbegin(),
                                    aVector.cend()));
  }
}

TEST(AlgArrays, maximumProduct) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {{{1, 2, 3}, 6},
                                       {{1, 2, 3, 4}, 24},
                                       {{-10, -20, 5, 6, 10}, 2000},
                                       {{1, 0, 100}, 0},
                                       {{1, 1}, 1}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(maximumProduct(v), expt);
  }
}

}  // namespace algorithms::test
