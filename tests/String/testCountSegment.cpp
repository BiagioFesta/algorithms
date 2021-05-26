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
#include <algorithms/String/CountSegment.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(String, CountSegment) {
  using Test = std::pair<const char*, int>;
  const std::vector<Test> testCases = {{"Hello, my name is Biagio", 5},
                                       {"    Hello, my name is Biagio    ", 5},
                                       {"OneSingleWord", 1}};

  for (const auto& [str, expt] : testCases) {
    ASSERT_EQ(CountSegment(str), expt);
  }
}

}  // namespace algorithms::test
