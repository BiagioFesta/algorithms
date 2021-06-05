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
#include <algorithms/Array/SearchRotatedSortedArray.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, SearchRotatedSortedArray) {
  using Test = std::tuple<std::vector<int>, int, int>;
  const std::vector<Test> testCases = {{{7, 8, 1, 2, 3, 4, 5, 6}, 2, 3},
                                       {{10, 2, 3, 5, 8, 9}, 10, 0},
                                       {{5, 7, 10, 2, 3}, 7, 1},
                                       {{0, 1, 2, 3, 4, 5, 6, 7}, 3, 3},
                                       {{4, 5, 6, 7, 0, 1, 2}, 0, 4},
                                       {{5, 6, 7, 3, 4}, 10, -1}};

  for (const auto& [nums, target, expt] : testCases) {
    ASSERT_EQ(SearchRotatedSortedArray(nums, target), expt);
  }
}

}  // namespace algorithms::test
