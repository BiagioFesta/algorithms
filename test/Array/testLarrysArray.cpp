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
#include <algorithms/Array/LarrysArray.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, LarrysArray) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{3, 1, 2}, true},
                                       {{1, 3, 4, 2}, true},
                                       {{1, 2, 3, 5, 4}, false},
                                       {{1, 6, 5, 2, 4, 3}, true}};

  for (const auto& [vect, expt] : testCases) {
    EXPECT_EQ(LarrysArray(vect), expt);
  }
}

}  // namespace algorithms::test
