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
#include <algorithms/DynamicProgramming/Keystroke.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, Keystroke) {
  using Test = std::pair<int, int>;
  const std::vector<Test> testCases = {
      {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 9}, {8, 12}};

  for (const auto& [n, expt] : testCases) {
    ASSERT_EQ(Keystroke(n), expt);
  }
}

}  // namespace algorithms::test
