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
#include <algorithms/Array/DailyTemperatures.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, DailyTemperatures) {
  using Test = std::pair<std::vector<int>, std::vector<int>>;
  const std::vector<Test> testCases = {{{10, 9, 8, 7, 6, 5, 4, 3, 2, 11}, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}},
                                       {{73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}}};

  for (const auto& [temps, expt] : testCases) {
    ASSERT_EQ(DailyTemperatures(temps), expt);
  }
}

}  // namespace algorithms::test
