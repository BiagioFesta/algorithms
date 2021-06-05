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
#include <algorithms/Array/StockMaximize.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, StockMaximize) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {
      {{1, 2}, 1}, {{2, 1}, 0}, {{5, 3, 2}, 0}, {{1, 2, 100}, 197}, {{1, 3, 1, 2}, 3}, {{5, 4, 3, 4, 5}, 4}, {{}, 0}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(StockMaximize(v), expt);
  }
}

}  // namespace algorithms::test
