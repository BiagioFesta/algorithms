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
#include <algorithms/String/MinAddParentheses.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(String, MinAddParentheses) {
  using Test = std::pair<std::string, int>;
  const std::vector<Test> testCases{
      {"())", 1}, {"(((", 3}, {"()", 0}, {"()))((", 4}, {"", 0}};

  for (const auto& [str, expt] : testCases) {
    ASSERT_EQ(MinAddParentheses(str), expt);
  }
}

}  // namespace algorithms::test
