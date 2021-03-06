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
#include <algorithms/Misc/KSymbolInGrammar.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Misc, KSymbolInGrammar) {
  using Test = std::tuple<int, int, int>;
  const std::vector<Test> testCases = {{1, 1, 0}, {2, 1, 0}, {2, 2, 1}, {4, 5, 1}, {30, 40, 0}};

  for (const auto& [n, k, expt] : testCases) {
    ASSERT_EQ(KSymbolInGrammar(n, k), expt);
  }
}

}  // namespace algorithms::test
