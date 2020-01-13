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
#include <algorithms/Array/GetEqualSubstringsWithinBudget.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, GetEqualSubstringsWithinBudget) {
  using Test = std::tuple<std::string, std::string, int, int>;
  const std::vector<Test> testCases = {{"abcd", "bcdf", 3, 3},
                                       {"abcd", "cdef", 3, 1},
                                       {"abcd", "acde", 0, 1},
                                       {"abc", "cba", 0, 1}};

  for (const auto& [s, t, maxCost, expt] : testCases) {
    ASSERT_EQ(GetEqualSubstringsWithinBudget(s, t, maxCost), expt);
  }
}

}  // namespace algorithms::test
