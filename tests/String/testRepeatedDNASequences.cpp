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
#include <algorithms/String/RepeatedDNASequences.hpp>
#include <string>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(String, RepeatedDNASequences) {
  using Test = std::pair<std::string, std::vector<std::string>>;
  const std::vector<Test> testCases = {{"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", {"AAAAACCCCC", "CCCCCAAAAA"}},
                                       {"AAAAAAAAAAA", {"AAAAAAAAAA"}},
                                       {"AAAAAAAAAAAA", {"AAAAAAAAAA"}},
                                       {"AAA", {}}};

  for (const auto& [s, expt] : testCases) {
    ASSERT_EQ(RepeatedDNASequences(s), expt);
  }
}

}  // namespace algorithms::test
