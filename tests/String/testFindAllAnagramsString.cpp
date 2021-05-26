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
#include <algorithms/String/FindAllAnagramsString.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(String, FindAllAnagramsString) {
  using Test = std::tuple<std::string, std::string, std::vector<int>>;
  const std::vector<Test> testCases = {{"cbaebabacd", "abc", {0, 6}},
                                       {"abc", "cba", {0}},
                                       {"dabc", "cba", {1}},
                                       {"", "a", {}}};

  for (const auto& [s, p, expt] : testCases) {
    const auto result = FindAllAnagramsString(s, p);
    ASSERT_TRUE(std::is_permutation(
        result.cbegin(), result.cend(), expt.cbegin(), expt.cend()));
  }
}

}  // namespace algorithms::test
