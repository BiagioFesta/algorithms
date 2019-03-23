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
#include <algorithms/Array/IsPalindrome.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, IsPalindrome) {
  using Test = std::pair<int, bool>;
  const std::vector<Test> testCases = {{121, true},
                                       {-121, false},
                                       {10, false},
                                       {0, true},
                                       {12344321, true},
                                       {123421, false},
                                       {1000000001, true}};

  for (const auto [num, expt] : testCases) {
    ASSERT_EQ(IsPalindrome(num), expt);
  }
}

}  // namespace algorithms::test
