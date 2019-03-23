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
#include <algorithms/Array/AbsolutePermutation.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, AbsolutePermutation) {
  using Test = std::tuple<int, int, std::vector<int>>;
  const std::vector<Test> testCases = {
      {2, 1, {2, 1}},
      {3, 0, {1, 2, 3}},
      {3, 2, {-1}},
      {10, 1, {2, 1, 4, 3, 6, 5, 8, 7, 10, 9}}};

  for (const auto& [n, k, expt] : testCases) {
    ASSERT_EQ(AbsolutePermutation(n, k), expt);
  }
}

}  // namespace algorithms::test
