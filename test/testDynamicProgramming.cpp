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
#include <DynamicProgramming.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(dynamicProgramming, binomialCoefficient) {
  static const std::vector<std::tuple<int, int, int>> testCases = {
      {4, 2, 6}, {1, 1, 1}, {20, 3, 1140}};

  for (const auto& [n, k, exp] : testCases) {
    ASSERT_EQ(binomialCoefficient(n, k), exp);
  }
}

TEST(dynamicProgramming, fibonacci) {
  using Test = std::pair<int, int>;
  static const std::vector<Test> testCases = {
      {0, 1}, {1, 1}, {2, 1}, {3, 2}, {5, 5}, {10, 55}};

  for (const auto& [n, r] : testCases) {
    ASSERT_EQ(fibonacci(n), r);
  }
}

TEST(dynamicProgramming, minPathSum) {
  static const std::vector<int> kMatrix = {1, 3, 1, 1, 5, 1, 4, 2, 1};
  static const int kExpectedSol = 7;

  ASSERT_EQ(minPathSum(kMatrix.data(), 3, 3), kExpectedSol);
}

TEST(dynamicProgramming, longestCommonSubsequence) {
  using Test = std::tuple<std::string, std::string, int>;
  const std::vector<Test> testCases = {
      {"ABCD", "ABDC", 3}, {"SHINCHAN", "NOHARAAA", 3}, {"ABC", "DEF", 0}};

  for (const auto& [str1, str2, expt] : testCases) {
    ASSERT_EQ(longestCommonSubsequence(str1, str2), expt);
  }
}

TEST(dynamicProgramming, sherlockAndCost) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {{{1, 2, 3}, 2},
                                       {{10, 1, 10, 1, 10}, 36}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(sherlockAndCost(v), expt);
  }
}

}  // namespace algorithms::test
