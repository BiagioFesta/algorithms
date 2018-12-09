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
#include <algorithm>
#include <algorithms/Array/ThreeSum.hpp>
#include <utility>
#include <vector>

namespace algorithms::test {

TEST(Array, ThreeSum) {
  using Test = std::pair<std::vector<int>, std::vector<std::vector<int>>>;

  std::vector<Test> testCases = {
      {{-1, 0, 1, 2, -1, -4}, {{-1, 0, 1}, {-1, -1, 2}}}, {{-1, 0}, {}}};

  for (auto [nums, expt] : testCases) {
    const auto aResult = ThreeSum(&nums);

    ASSERT_EQ(aResult.size(), expt.size());

    for (const auto& aTripletResutl : aResult) {
      auto aFinder = std::find_if(
          expt.begin(), expt.end(), [&aTripletResutl](const auto& iTriplet) {
            return std::is_permutation(iTriplet.cbegin(),
                                       iTriplet.cend(),
                                       aTripletResutl.cbegin(),
                                       aTripletResutl.cend());
          });

      ASSERT_NE(aFinder, expt.end());

      expt.erase(aFinder);
    }
  }
}

}  // namespace algorithms::test
