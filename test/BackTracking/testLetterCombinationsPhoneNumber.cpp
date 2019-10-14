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

#include <algorithm>
#include <algorithms/BackTracking/LetterCombinationsPhoneNumber.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(BackTracking, LetterCombinationsPhoneNumber) {
  using Test = std::pair<std::string, std::vector<std::string>>;
  const std::vector<Test> testCases = {
      {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}}, {"", {}}};

  for (const auto& [digits, expt] : testCases) {
    const auto ans = LetterCombinationsPhoneNumber(digits);
    ASSERT_TRUE(std::is_permutation(
        ans.cbegin(), ans.cend(), expt.cbegin(), expt.cend()));
  }
}

}  // namespace algorithms::test
