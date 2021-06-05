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
#include <algorithms/Array/KthSmallestSortedMatrix.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, KthSmallestSortedMatrix) {
  using Test = std::tuple<std::vector<std::vector<int>>, int, int>;
  const std::vector<Test> testCases = {{{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}}, 8, 13}};

  for (const auto& [matrix, k, expt] : testCases) {
    ASSERT_EQ(KthSmallestSortedMatrix(matrix, k), expt);
  }
}

}  // namespace algorithms::test
