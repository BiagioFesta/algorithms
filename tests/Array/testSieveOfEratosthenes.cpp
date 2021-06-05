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
#include <algorithms/Array/SieveOfEratosthenes.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, SieveOfEratosthenes) {
  using Test = std::pair<int, std::vector<int>>;
  const std::vector<Test> testCases = {{1, {}},
                                       {2, {2}},
                                       {3, {2, 3}},
                                       {10, {2, 3, 5, 7}},
                                       {50, {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}}};

  for (const auto& [n, expt] : testCases) {
    ASSERT_EQ(SieveOfEratosthenes(n), expt);
  }
}

}  // namespace algorithms::test
