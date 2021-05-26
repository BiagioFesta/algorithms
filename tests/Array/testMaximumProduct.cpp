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
#include <algorithms/Array/MaximumProduct.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, MaximumProduct) {
  using Test = std::pair<std::vector<int>, int>;
  const std::vector<Test> testCases = {{{1, 2, 3}, 6},
                                       {{1, 2, 3, 4}, 24},
                                       {{-10, -20, 5, 6, 10}, 2000},
                                       {{1, 0, 100}, 0},
                                       {{1, 1}, 1}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(MaximumProduct(v), expt);
  }
}

}  // namespace algorithms::test
