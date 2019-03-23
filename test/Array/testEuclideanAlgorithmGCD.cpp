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
#include <algorithms/Array/EuclideanAlgorithmGCD.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, EuclideanAlgorithmGCD) {
  using Test = std::tuple<int, int, int>;
  const std::vector<Test> testCases = {{3, 3, 3},
                                       {1024, 0, 1024},
                                       {3, 2, 1},
                                       {12, 6, 6},
                                       {32, 15, 1},
                                       {36, 144, 36},
                                       {8, 12, 4}};

  for (const auto [i, j, expt] : testCases) {
    ASSERT_EQ(EuclideanAlgorithmGCD(i, j), expt);
    ASSERT_EQ(EuclideanAlgorithmGCD(i, j), EuclideanAlgorithmGCD(j, i));
  }
}

}  // namespace algorithms::test
