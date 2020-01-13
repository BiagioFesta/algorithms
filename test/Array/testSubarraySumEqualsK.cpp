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
#include <algorithms/Array/SubarraySumEqualsK.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, SubarraySumEqualsK) {
  using Test = std::tuple<std::vector<int>, int, int>;
  const std::vector<Test> testCases = {{{1, 1, 1}, 2, 2},
                                       {{1, 0, 0, 1, 0, 2}, 1, 9}};

  for (const auto& [nums, k, expt] : testCases) {
    ASSERT_EQ(SubarraySumEqualsK(nums, k), expt);
  }
}

}  // namespace algorithms::test
