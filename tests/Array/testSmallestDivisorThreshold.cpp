/*
  Copyright (C) 2022  Biagio Festa

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
#include <algorithms/Array/SmallestDivisorThreshold.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, SmallestDivisorThreshold) {
  using Test = std::tuple<std::vector<int>, int, int>;
  const std::vector<Test> testCases = {{{1, 2, 5, 9}, 6, 5}, {{44, 22, 33, 11, 1}, 5, 44}};

  for (const auto& [nums, threshold, expt] : testCases) {
    ASSERT_EQ(SmallestDivisorThreshold(nums, threshold), expt);
  }
}

}  // namespace algorithms::test
