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
#include <algorithms/Array/KeysAndRooms.hpp>
#include <utility>

namespace algorithms::test {

TEST(Array, KeysAndRooms) {
  using Test = std::pair<std::vector<std::vector<int>>, bool>;

  const std::vector<Test> testCases = {{{{1}, {2}, {3}, {}}, true},
                                       {{{1, 3}, {3, 0, 1}, {2}, {0}}, false}};

  for (const auto& [rooms, expt] : testCases) {
    ASSERT_EQ(KeysAndRooms(rooms), expt);
  }
}

}  // namespace algorithms::test
