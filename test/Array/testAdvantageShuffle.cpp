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
#include <algorithm>
#include <algorithms/Array/AdvantageShuffle.hpp>
#include <cassert>
#include <tuple>
#include <vector>

namespace {

/*! \brief Count the number of 'advantages' input 'a' has against 'b'.
 *  \note The advantage is the number of times that a[i] > b[i] for all i.
 */
int CountNumAdvantage(const std::vector<int>& a, const std::vector<int>& b) {
  assert(a.size() == b.size());
  int c = 0;
  for (std::size_t i = 0; i < a.size(); ++i) {
    if (b[i] < a[i]) {
      ++c;
    }
  }
  return c;
}

}  // anonymous namespace

namespace algorithms::test {

TEST(Array, AdvantageShuffle) {
  using Test = std::tuple<std::vector<int>, std::vector<int>, int>;
  const std::vector<Test> testCases = {{{2, 7, 11, 15}, {1, 10, 4, 11}, 4},
                                       {{12, 24, 8, 32}, {13, 25, 32, 11}, 3},
                                       {{2, 0, 4, 1, 2}, {1, 3, 0, 0, 2}, 4}};

  for (const auto& [a, b, numAdvantageExpt] : testCases) {
    const auto result = AdvantageShuffle(a, b);

    ASSERT_TRUE(std::is_permutation(
        result.cbegin(), result.cend(), a.cbegin(), a.cend()));
    ASSERT_EQ(::CountNumAdvantage(result, b), numAdvantageExpt);
  }
}

}  // namespace algorithms::test
