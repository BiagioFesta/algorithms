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
#include <algorithms/DynamicProgramming/PartitionEqualSubSum.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, PartitionEqualSubSum) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{1, 5, 11, 5}, true},
                                       {{1, 5, 11, 5, 1, 1}, true},
                                       {{1}, false},
                                       {{}, false},
                                       {{1, 1}, true}};

  for (const auto& [nums, expt] : testCases) {
    ASSERT_EQ(PartitionEqualSubSum(nums), expt);
  }
}

}  // namespace algorithms::test
