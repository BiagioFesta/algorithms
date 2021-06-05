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
#include <algorithm>
#include <algorithms/String/FrequencySort.hpp>
#include <string>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(String, FrequencySort) {
  using Test = std::pair<std::string, std::vector<std::string>>;
  const std::vector<Test> testCases = {
      {"tree", {"eert", "eetr"}}, {"cccaaa", {"cccaaa", "aaaccc"}}, {"Aabb", {"bbAa", "bbaA"}}};

  for (const auto& [s, expts] : testCases) {
    const std::string result = FrequencySort(s);
    ASSERT_TRUE(std::any_of(expts.cbegin(), expts.cend(), [&result](const auto& expt) { return expt == result; }));
  }
}

}  // namespace algorithms::test
