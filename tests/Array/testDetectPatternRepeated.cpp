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
#include <algorithms/Array/DetectPatternRepeated.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, DetectPatternRepeated) {
  using Test = std::tuple<std::vector<int>, int, int, bool>;
  const std::vector<Test> testCases = {{{1, 2, 4, 4, 4, 4}, 1, 3, true},
                                       {{1, 2, 1, 2, 1, 1, 1, 3}, 2, 2, true},
                                       {{1, 2, 1, 2, 1, 3}, 2, 3, false},
                                       {{1, 2, 3, 1, 2}, 2, 2, false},
                                       {{2, 2, 2, 2}, 2, 3, false}};

  for (const auto& [v, m, k, expt] : testCases) {
    ASSERT_EQ(DetectPatternRepeated(v, m, k), expt);
  }
}

}  // namespace algorithms::test
