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
#include <algorithms/DynamicProgramming/OnesAndZeroes.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, OnesAndZeroes) {
  using Test = std::tuple<std::vector<std::string>, int, int, int>;
  const std::vector<Test> testCases = {
      {{"10", "0", "1"}, 1, 1, 2}, {{"10", "0001", "111001", "1", "0"}, 5, 3, 4}

  };

  for (const auto& [strs, m, n, expt] : testCases) {
    ASSERT_EQ(OnesAndZeroes(strs, m, n), expt);
  }
}

}  // namespace algorithms::test
