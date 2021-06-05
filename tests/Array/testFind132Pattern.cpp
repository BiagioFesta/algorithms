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
#include <algorithms/Array/Find132Pattern.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, Find132pattern) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> testCases = {{{1, 2, 3, 4}, false}, {{3, 1, 4, 2}, true}, {{-1, 3, 2, 0}, true}, {{}, false}};

  for (const auto& [v, expt] : testCases) {
    ASSERT_EQ(Find132pattern(v), expt);
  }
}

}  // namespace algorithms::test
