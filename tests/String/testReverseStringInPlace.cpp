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
#include <algorithms/String/ReverseStringInPlace.hpp>
#include <string>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(String, ReverseStringInPlace) {
  using Test = std::pair<std::string, std::string>;
  const std::vector<Test> testCases = {
      {"hello", "olleh"}, {"A man, a plan, a canal: Panama", "amanaP :lanac a ,nalp a ,nam A"}, {"", ""}};

  std::string aMutableStr;
  for (const auto& [str, expt] : testCases) {
    aMutableStr = str;
    ReverseStringInPlace(&aMutableStr);
    ASSERT_EQ(aMutableStr, expt);
  }
}

}  // namespace algorithms::test
