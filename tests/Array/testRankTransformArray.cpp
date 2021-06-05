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
#include <algorithms/Array/RankTransformArray.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, RankTransformArray) {
  using Test = std::pair<std::vector<int>, std::vector<int>>;
  const std::vector<Test> testCases = {{{40, 10, 20, 30}, {4, 1, 2, 3}},
                                       {{100, 100, 100}, {1, 1, 1}},
                                       {{37, 12, 28, 9, 100, 56, 80, 5, 12}, {5, 3, 4, 2, 8, 6, 7, 1, 3}}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(RankTransformArray(v), expt);
  }
}

}  // namespace algorithms::test
