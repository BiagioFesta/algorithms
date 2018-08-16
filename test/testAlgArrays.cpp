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
      {2, 1, {2, 1}}, {3, 0, {1, 2, 3}}, {3, 2, {-1}}};

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

}  // namespace algorithms::test
