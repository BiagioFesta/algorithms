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
#include <algorithms/Array/FindKClosestElements.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, FindKClosestElements) {
  using Test = std::tuple<std::vector<int>, int, int, std::vector<int>>;
  const std::vector<Test> testCases = {{{0, 0, 1, 2, 3, 3, 4, 7, 7, 8}, 3, 5, {3, 3, 4}},
                                       {{1, 2, 3, 4, 5}, 4, 3, {1, 2, 3, 4}},
                                       {{1, 2, 3, 4, 5}, 4, -1, {1, 2, 3, 4}},
                                       {{0, 1, 1, 1, 2, 3, 6, 7, 8, 9}, 9, 4, {0, 1, 1, 1, 2, 3, 6, 7, 8}},
                                       {{}, 0, 100, {}},
                                       {{0, 1, 2, 3, 4}, 2, 10, {3, 4}},
                                       {{0, 1, 2, 3, 4, 5, 6}, 4, 6, {3, 4, 5, 6}}};

  for (const auto& [v, k, x, expt] : testCases) {
    ASSERT_EQ(FindKClosestElements(v, k, x), expt);
  }
}

}  // namespace algorithms::test
