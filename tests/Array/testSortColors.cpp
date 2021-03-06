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
#include <algorithm>
#include <algorithms/Array/SortColors.hpp>
#include <vector>

namespace algorithms::test {

TEST(Array, SortColors) {
  using Test = std::vector<int>;
  const std::vector<Test> testCases = {{2, 0, 2, 1, 1, 0}};

  for (const auto& v : testCases) {
    auto mutableV = v;
    SortColors(&mutableV);
    ASSERT_TRUE(std::is_sorted(mutableV.cbegin(), mutableV.cend()));
  }
}

}  // namespace algorithms::test
