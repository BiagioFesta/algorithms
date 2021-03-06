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
#include <algorithms/String/StringCompression.hpp>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(String, StringCompression) {
  using Test = std::tuple<const char*, int, bool, std::string>;
  const std::vector<Test> testCases = {{"aabcccccaaa", 11, true, "2ab5c3a"},
                                       {"abc", 3, false, ""},
                                       {"abcc", 3, false, ""},
                                       {"abcccccccccc", 4, false, ""}};

  for (const auto& [str, bufferSize, expt, result] : testCases) {
    const auto buffer = std::make_unique<char[]>(bufferSize);
    ASSERT_EQ(StringCompression(str, buffer.get(), bufferSize), expt);
    if (expt == true) {
      ASSERT_EQ(std::string(buffer.get()), result);
    }
  }
}

}  // namespace algorithms::test
