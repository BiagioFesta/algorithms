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
#include <algorithms/BackTracking/WildcardMatching.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(BackTracking, WildcardMatching) {
  using Test = std::tuple<std::string, std::string, bool>;
  const std::vector<Test> testCases = {{"adceb", "*a*b", true},
                                       {"abc", "a***b***c", true},
                                       {"", "*", true},
                                       {"aa", "a", false},
                                       {"aa", "*", true},
                                       {"cb", "?a", false},
                                       {"adceb", "*a*b", true},
                                       {"acdcb", "a*c?b", false}};

  for (const auto& [s, p, expt] : testCases) {
    ASSERT_EQ(WildcardMatching(s, p), expt);
  }
}

}  // namespace algorithms::test
