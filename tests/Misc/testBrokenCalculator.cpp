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
#include <algorithms/Misc/BrokenCalculator.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Misc, BrokenCalculator) {
  using Test = std::tuple<int, int, int>;
  const std::vector<Test> testCases = {{2, 3, 2}, {5, 8, 2}, {3, 10, 3}, {1024, 1, 1023}, {42, 42, 0}};

  for (const auto& [x, y, expt] : testCases) {
    ASSERT_EQ(BrokenCalculator(x, y), expt);
  }
}

}  // namespace algorithms::test
