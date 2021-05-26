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
#include <algorithms/DynamicProgramming/TwoEggsDropping.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, TwoEggsDropping) {
  using Test = std::tuple<int, int, int>;
  const std::vector<Test> testCases = {{0, 0, -1},
                                       {1, 1, 0},
                                       {2, 2, 0},
                                       {3, 2, 1},
                                       {4, 3, 0},
                                       {5, 3, 1},
                                       {10, 4, 3},
                                       {36, 8, 7},
                                       {100, 14, 8}};

  for (const auto& [n, expt1, expt2] : testCases) {
    const auto aSolution = TwoEggsDropping(n);
    ASSERT_EQ(aSolution.first, expt1);
    ASSERT_EQ(aSolution.second, expt2);
  }
}

}  // namespace algorithms::test
