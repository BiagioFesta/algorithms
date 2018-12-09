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
#include <algorithms/Array/FindLengthOfLCIS.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, FindLengthOfLCIS) {
  using Test = std::pair<std::vector<int>, int>;

  const Test test1 = {{1, 3, 5, 4, 7}, 3};
  ASSERT_EQ(FindLengthOfLCIS(test1.first), test1.second);

  const Test test2 = {{2, 2, 2, 2}, 1};
  ASSERT_EQ(FindLengthOfLCIS(test2.first), test2.second);

  const Test test3 = {{}, 0};
  ASSERT_EQ(FindLengthOfLCIS(test3.first), test3.second);

  const Test test4 = {{1}, 1};
  ASSERT_EQ(FindLengthOfLCIS(test4.first), test4.second);
}

}  // namespace algorithms::test
