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
#include <algorithm>
#include <algorithms/String/FindAndReplacePattern.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(String, FindAndReplacePattern) {
  using Test = std::
      tuple<std::vector<std::string>, std::string, std::vector<std::string>>;
  const std::vector<Test> testCases = {
      {{"abc", "deq", "mee", "aqq", "dkd", "ccc"}, "abb", {"mee", "aqq"}}};

  for (const auto& [words, pattern, expt] : testCases) {
    const auto aResult = FindAndReplacePattern(words, pattern);
    ASSERT_TRUE(std::is_permutation(
        aResult.cbegin(), aResult.cend(), expt.cbegin(), expt.cend()));
  }
}

}  // namespace algorithms::test
