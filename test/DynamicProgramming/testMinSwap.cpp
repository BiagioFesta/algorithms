/*
  Copyright (C) 2018  Biagio Festa

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
#include <algorithms/DynamicProgramming/MinSwap.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, MinSwap) {
  using Test = std::tuple<std::vector<int>, std::vector<int>, int>;
  const std::vector<Test> testCases = {{{0, 3, 5, 8, 9}, {2, 1, 4, 6, 9}, 1},
                                       {{1, 3, 5, 4}, {2, 2, 3, 7}, 2},
                                       {{1, 3, 5, 4}, {1, 2, 3, 7}, 1}};

  for (const auto& [v1, v2, expt] : testCases) {
    ASSERT_EQ(MinSwap(v1, v2), expt);
  }
}

}  // namespace algorithms::test
