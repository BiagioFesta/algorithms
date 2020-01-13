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
#include <algorithms/String/SwapAdjacentLR.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(String, SwapAdjacentLR) {
  using Test = std::tuple<std::string, std::string, bool>;
  const std::vector<Test> testCases = {{"LR", "RL", false},
                                       {"XXRXXLXXXX", "XXXXRXXLXX", false},
                                       {"RXXLRXRXL", "XRLXXRRLX", true},
                                       {"R", "L", false},
                                       {"X", "L", false}};

  for (const auto& [start, end, expt] : testCases) {
    ASSERT_EQ(SwapAdjacentLR(start, end), expt);
  }
}

}  // namespace algorithms::test
