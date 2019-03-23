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
#include <algorithms/Array/RotateRight.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, RotateRight) {
  using Test = std::tuple<std::vector<int>, int, std::vector<int>>;
  const std::vector<Test> testCases = {
      {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
      {std::vector<int>{}, 10, std::vector<int>{}},
      {{1, 2, 3, 4, 5, 6, 7}, 0, {1, 2, 3, 4, 5, 6, 7}},
      {{1, 2, 3, 4, 5, 6, 7}, -1, {2, 3, 4, 5, 6, 7, 1}},
      {{1, 2, 3}, 3, {1, 2, 3}},
      {{1, 2, 3}, -6, {1, 2, 3}},
      {{1, 2, 3, 4, 5, 6}, 2, {5, 6, 1, 2, 3, 4}}};

  for (const auto& [v, k, expt] : testCases) {
    auto rotated = v;
    RotateRight(&rotated, k);
    ASSERT_EQ(rotated, expt);
  }
}

}  // namespace algorithms::test
