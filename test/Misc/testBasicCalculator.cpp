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
#include <algorithms/Misc/BasicCalculator.hpp>
#include <string>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Misc, BasicCalculator) {
  using Test = std::pair<std::string, int>;
  const std::vector<Test> testCases = {{"2-4-(8+2-6+(8+4-(1)+8-10))", -15},
                                       {"1 + 1", 2},
                                       {"11 + 11", 22},
                                       {"11+11", 22},
                                       {"(5-(1+(5)))", -1},
                                       {"2-(5-6)", 3},
                                       {"2-1 + 2", 3},
                                       {"(1+(4+5+2)-3)+(6+8)", 23}};

  for (const auto& [s, expt] : testCases) {
    ASSERT_EQ(BasicCalculator(s), expt);
  }
}

}  // namespace algorithms::test
