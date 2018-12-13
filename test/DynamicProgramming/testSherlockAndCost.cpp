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
#include <algorithms/DynamicProgramming/SherlockAndCost.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, SherlockAndCost) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {{{1, 2, 3}, 2},
                                       {{10, 1, 10, 1, 10}, 36}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(SherlockAndCost(v), expt);
  }
}

}  // namespace algorithms::test