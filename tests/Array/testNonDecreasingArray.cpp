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
#include <algorithms/Array/NonDecreasingArray.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, NonDecreasingArray) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> TestCases = {{{4, 2, 3}, true}, {{4, 2, 1}, false}, {{3, 4, 2, 3}, false}};

  for (const auto& [str, exp] : TestCases) {
    ASSERT_EQ(NonDecreasingArray(str.data(), str.size()), exp);
  }
}

}  // namespace algorithms::test
