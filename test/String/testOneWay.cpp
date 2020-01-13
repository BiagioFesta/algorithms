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
#include <algorithms/String/OneWay.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(String, OneWay) {
  using Case = std::tuple<std::string, std::string, bool>;
  const std::vector<Case> testCases = {{"pale", "ple", true},
                                       {"pales", "pale", true},
                                       {"pale", "bale", true},
                                       {"pale", "bae", false},
                                       {"paless", "pale", false}};

  for (const auto& [str1, str2, exp] : testCases) {
    ASSERT_EQ(OneWay(str1, str2), exp);
    ASSERT_EQ(OneWay(str2, str1), exp);
  }
}

}  // namespace algorithms::test
