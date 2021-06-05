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
#include <algorithms/DynamicProgramming/HouseRobberII.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, HouseRobberII) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {
      {{2, 7, 9, 3, 1}, 11}, {{2, 3, 2}, 3}, {{1, 2, 3, 1}, 4}, {{5}, 5}, {{}, 0}, {{1, 2}, 2}};

  for (const auto& [nums, expt] : testCases) {
    ASSERT_EQ(HouseRobberII(nums), expt);
  }
}

}  // namespace algorithms::test
