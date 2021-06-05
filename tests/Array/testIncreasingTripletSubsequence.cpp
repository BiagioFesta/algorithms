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
#include <algorithms/Array/IncreasingTripletSubsequence.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, IncreasingTripletSubsequence) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{10, 30, 1, 2, 3}, true},
                                       {{1, 0, 0, 10, 0, 0, 0, 100, 0}, true},
                                       {{1, 1, 1, 1, 1}, false},
                                       {{1, 5, 2, 3}, true},
                                       {{1, 5, 2, 1}, false},
                                       {{1, 2, 3, 4, 5}, true},
                                       {{5, 4, 3, 2, 1}, false}};

  for (const auto& [nums, expt] : testCases) {
    ASSERT_EQ(IncreasingTripletSubsequence(nums), expt);
  }
}

}  // namespace algorithms::test
