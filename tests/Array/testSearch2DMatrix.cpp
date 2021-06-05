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
#include <algorithms/Array/Search2DMatrix.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, Search2DMatrix) {
  using Test = std::tuple<std::vector<std::vector<int>>, int, bool>;
  const std::vector<Test> testCases = {{{}, 12, false},
                                       {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 3, true},
                                       {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 13, false}};

  for (const auto& [matrix, target, expt] : testCases) {
    ASSERT_EQ(Search2DMatrix(matrix, target), expt);
  }
}

}  // namespace algorithms::test
