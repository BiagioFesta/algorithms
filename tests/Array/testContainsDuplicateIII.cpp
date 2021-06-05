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
#include <algorithms/Array/ContainsDuplicateIII.hpp>
#include <limits>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, ContainsDuplicateIII) {
  using Test = std::tuple<std::vector<int>, int, int, bool>;
  const std::vector<Test> testCases = {
      {{1, 2, 3, 1}, 3, 0, true},
      {{1, 0, 1, 1}, 1, 2, true},
      {{1, 5, 9, 1, 5, 9}, 2, 3, false},
      {{std::numeric_limits<int>::min(), std::numeric_limits<int>::min() + 1}, 3, 3, true},
      {{1, 2, 3}, 0, 0, false}

  };

  for (const auto& [nums, k, t, expt] : testCases) {
    ASSERT_EQ(ContainsDuplicateIII(nums, k, t), expt);
  }
}

}  // namespace algorithms::test
