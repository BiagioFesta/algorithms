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
#include <algorithms/Array/MinimumRemoveValidParentheses.hpp>
#include <string>
#include <utility>
#include <vector>

namespace {

bool IsParenthesesStr(const std::string& str) {
  int counter = 0;
  for (const char c : str) {
    if (c == '(')
      ++counter;
    else if (c == ')')
      --counter;
  }
  return counter == 0;
}

}  // anonymous namespace

namespace algorithms::test {

TEST(Array, MinimumRemoveValidParentheses) {
  using Test = std::pair<std::string, std::size_t>;
  const std::vector<Test> testCases = {{"lee(t(c)o)de)", 12}, {"a)b(c)d", 6}, {"))((", 0}, {"(a(b(c)d)", 8}};

  for (const auto& [str, exptLen] : testCases) {
    const auto ans = MinimumRemoveValidParentheses(str);
    ASSERT_EQ(ans.size(), exptLen);
    ASSERT_TRUE(::IsParenthesesStr(ans));
  }
}

}  // namespace algorithms::test
