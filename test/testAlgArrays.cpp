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
#include <AlgArrays.hpp>
#include <tuple>

namespace algorithms::test {

TEST(AlgArrays, isAlmostNonDecreasing) {
  using Test = std::pair<std::vector<int>, bool>;
  const std::vector<Test> TestCases = {
      {{4, 2, 3}, true}, {{4, 2, 1}, false}, {{3, 4, 2, 3}, false}};

  for (const auto& [str, exp] : TestCases) {
    ASSERT_EQ(isAlmostNonDecreasing(str.data(), str.size()), exp);
  }
}

TEST(AlgArrays, minSizeSubArraySum) {
  const std::vector kData1 = {2, 3, 1, 2, 4, 3};
  ASSERT_EQ(minSizeSubArraySum(kData1.data(), kData1.size(), 7), 2);

  const std::vector kData2 = {1};
  ASSERT_EQ(minSizeSubArraySum(kData2.data(), kData2.size(), 7), 0);

  const std::vector kData3 = {1, 1, 4, 3, 1, 1, 1};
  ASSERT_EQ(minSizeSubArraySum(kData3.data(), kData3.size(), 7), 2);

  const std::vector<int> kData4 = {};
  ASSERT_EQ(minSizeSubArraySum(kData4.data(), kData4.size(), 100), 0);

  const std::vector kData5 = {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
  ASSERT_EQ(minSizeSubArraySum(kData5.data(), kData5.size(), 213), 8);
}

}  // namespace algorithms::test
