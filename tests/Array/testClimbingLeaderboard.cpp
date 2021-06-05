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
#include <algorithms/Array/ClimbingLeaderboard.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, ClimbingLeaderboard) {
  using Test = std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>;
  const std::vector<Test> testCases = {{{100, 100, 50, 40, 40, 20, 10}, {5, 25, 50, 120}, {6, 4, 2, 1}}};

  for (const auto& [board, alice, expt] : testCases) {
    ASSERT_EQ(climbingLeaderboard(board, alice), expt);
  }
}

}  // namespace algorithms::test
