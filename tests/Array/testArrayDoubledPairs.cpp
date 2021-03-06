/*
  Copyright (C) 2021  Biagio Festa

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
#include <algorithms/Array/ArrayDoubledPairs.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, ArrayDoubledPairs) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{-8, -4, -2, -1, 0, 0, 1, 2, 4, 8}, true},
                                       {{3, 1, 3, 6}, false},
                                       {{2, 1, 2, 6}, false},
                                       {{4, -2, 2, -4}, true},
                                       {{1, 2, 4, 16, 8, 4}, false}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(ArrayDoubledPairs(v), expt);
  }
}

}  // namespace algorithms::test
