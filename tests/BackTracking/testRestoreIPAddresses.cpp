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
#include <algorithms/BackTracking/RestoreIPAddresses.hpp>
#include <string>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(BackTracking, RestoreIPAddresses) {
  using Test = std::pair<std::string, std::vector<std::string>>;
  const std::vector<Test> testCases = {{"010010", {"0.10.0.10", "0.100.1.0"}},
                                       {"0000", {"0.0.0.0"}},
                                       {"25525511135", {"255.255.11.135", "255.255.111.35"}}};

  for (const auto& [str, expt] : testCases) {
    const auto ans = RestoreIPAddresses(str);
    ASSERT_TRUE(std::is_permutation(ans.cbegin(), ans.cend(), expt.cbegin(), expt.cend()));
  }
}

}  // namespace algorithms::test
