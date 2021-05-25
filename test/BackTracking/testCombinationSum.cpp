/*
  Copyright (C) 2019  Biagio Festa

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
#include <algorithms/BackTracking/CombinationSum.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(BackTracking, CombinationSum) {
  using Result = std::vector<std::vector<int>>;
  using Test = std::tuple<std::vector<int>, int, Result>;

  const std::vector<Test> testCases = {
      {{2, 3, 6, 7}, 7, {{7}, {2, 2, 3}}},
      {{2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}}};

  for (const auto& [v, t, expt] : testCases) {
    const auto result = CombinationSum(v, t);
    ASSERT_TRUE(std::is_permutation(
        result.cbegin(), result.cend(), expt.cbegin(), expt.cend()));
  }
}

}  // namespace algorithms::test
