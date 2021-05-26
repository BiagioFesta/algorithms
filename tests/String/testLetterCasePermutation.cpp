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
#include <algorithm>
#include <algorithms/String/LetterCasePermutation.hpp>
#include <string>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(String, LetterCasePermutation) {
  using Test = std::pair<std::string, std::vector<std::string>>;
  const std::vector<Test> testCases = {
      {"a1b2", {"a1b2", "a1B2", "A1b2", "A1B2"}},
      {"3z4", {"3z4", "3Z4"}},
      {"12345", {"12345"}},
      {"AB", {"AB", "aB", "Ab", "ab"}}};

  std::vector<std::string> result;
  for (const auto& [str, expt] : testCases) {
    LetterCasePermutation(str, &result);
    ASSERT_TRUE(std::is_permutation(
        result.cbegin(), result.cend(), expt.cbegin(), expt.cend()));
  }
}

}  // namespace algorithms::test
