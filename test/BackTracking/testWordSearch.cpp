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
#include <algorithms/BackTracking/WordSearch.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(BackTracking, WordSearch) {
  using Test = std::tuple<std::vector<std::vector<char>>, std::string, bool>;

  const std::vector<Test> testCases = {
      {{{'b'}, {'a'}, {'b'}}, "bbabab", false},
      {{{'a'}}, "ab", false},
      {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
       "ABCCED",
       true},
      {{}, "some", false},
      {{}, "", true}};

  for (const auto& [board, str, expt] : testCases) {
    ASSERT_EQ(WordSearch(board, str), expt);
  }
}

}  // namespace algorithms::test
