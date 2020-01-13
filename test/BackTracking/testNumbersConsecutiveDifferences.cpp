/*
  Copyright (C) 2020  Biagio Festa

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
#include <algorithm>
#include <algorithms/BackTracking/NumbersConsecutiveDifferences.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(BackTracking, NumbersConsecutiveDifferences) {
  using Test = std::tuple<int, int, std::vector<int>>;
  const std::vector<Test> testCases = {
      {3, 7, {181, 292, 707, 818, 929}},
      {2,
       1,
       {10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98}},
      {1, 0, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}},
      {2, 0, {11, 22, 33, 44, 55, 66, 77, 88, 99}}};

  for (const auto& [n, k, expt] : testCases) {
    const auto ans = NumbersConsecutiveDifferences(n, k);
    ASSERT_TRUE(std::is_permutation(
        expt.cbegin(), expt.cend(), ans.cbegin(), ans.cend()));
  }
}

}  // namespace algorithms::test
