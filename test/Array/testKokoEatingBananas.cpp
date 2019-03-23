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
#include <algorithms/Array/KokoEatingBananas.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(Array, KokoEatingBananas) {
  using Test = std::tuple<std::vector<int>, int, int>;
  const std::vector<Test> testCases = {
      {{3, 6, 7, 11}, 8, 4},
      {{30, 11, 23, 4, 20}, 5, 30},
      {{30, 11, 23, 4, 20}, 6, 23},
      {{980628391, 681530205, 734313996, 168632541}, 819870953, 4}};

  for (const auto& [v, h, expt] : testCases) {
    ASSERT_EQ(KokoEatingBananas(v, h), expt);
  }
}

}  // namespace algorithms::test
