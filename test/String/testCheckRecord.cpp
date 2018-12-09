/*
  Copyright (C) 2018  Biagio Festa

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
#include <algorithms/String/CheckRecord.hpp>
#include <string>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(String, CheckRecord) {
  using Test = std::pair<std::string, bool>;
  const std::vector<Test> testCases = {
      {"PPALLP", true}, {"PPALLL", false}, {"", true}, {"PPALLPPPA", false}};

  for (const auto& [str, expt] : testCases) {
    ASSERT_EQ(CheckRecord(str), expt);
  }
}

}  // namespace algorithms::test
