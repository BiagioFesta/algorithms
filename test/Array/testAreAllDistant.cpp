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
#include <algorithms/Array/AreAllDistant.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, AreAllDistant) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{}, true},
                                       {{1}, true},
                                       {{1, 2}, true},
                                       {{1, 2, 1, 2}, true},
                                       {{1, 2, 1, 1, 2}, false}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(AreAllDistant(v), expt);
  }
}

}  // namespace algorithms::test
