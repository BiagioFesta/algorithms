/*
  Copyright (C) 2019  Biagio Festa

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
#include <algorithms/DynamicProgramming/TargetSum.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, TargetSum) {
  using Test = std::tuple<std::vector<int>, int, int>;
  const std::vector<Test> testCases = {{{1, 1, 1, 1, 1}, 3, 5},
                                       {{1, 0}, 1, 2},
                                       {{}, 0, 1},
                                       {{}, 1, 0},
                                       {{1000}, -1000, 1},
                                       {{9, 7, 0, 3, 9, 8, 6, 5, 7, 6}, 2, 40}};

  for (const auto& [vect, S, expt] : testCases) {
    ASSERT_EQ(TargetSum(vect, S), expt);
  }
}

}  // namespace algorithms::test
