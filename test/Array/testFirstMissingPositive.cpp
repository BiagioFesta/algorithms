/*
  Copyright (C) 2018  Biagio Festa

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
#include <algorithms/Array/FirstMissingPositive.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, FirstMissingPositive) {
  using Test = std::pair<std::vector<int>, int>;

  Test test1 = {{1, 2, 0}, 3};
  ASSERT_EQ(FirstMissingPositive(&test1.first), test1.second);

  Test test2 = {{3, 4, -1, 1}, 2};
  ASSERT_EQ(FirstMissingPositive(&test2.first), test2.second);

  Test test3 = {{7, 8, 9, 11, 12}, 1};
  ASSERT_EQ(FirstMissingPositive(&test3.first), test3.second);

  Test test4 = {{1, 2, 3, 4, 5}, 6};
  ASSERT_EQ(FirstMissingPositive(&test4.first), test4.second);
}

}  // namespace algorithms::test
