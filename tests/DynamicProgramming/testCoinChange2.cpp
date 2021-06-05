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
#include <algorithms/DynamicProgramming/CoinChange2.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, CoinChange2) {
  using Test = std::tuple<int, std::vector<int>, int>;
  const std::vector<Test> testCases = {{5, {1, 2, 5}, 4}, {3, {2}, 0}, {10, {10}, 1}, {0, {}, 1}};

  for (const auto& [amount, coins, expt] : testCases) {
    ASSERT_EQ(CoinChange2(amount, coins), expt);
  }
}

}  // namespace algorithms::test
