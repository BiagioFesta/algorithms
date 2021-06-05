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
#include <algorithm>
#include <algorithms/Array/FourSum.hpp>

namespace {

//! \return 'true' whether the container has no duplicated elements.
template <typename Container>
bool NoDuplicate(const Container& c) {
  return std::all_of(
      std::begin(c), std::end(c), [&c](const auto& e) { return std::count(std::begin(c), std::end(c), e) == 1; });
}

}  // anonymous namespace

namespace algorithms::test {

TEST(Array, FourSum) {
  using Test = std::tuple<std::vector<int>, int, std::vector<std::vector<int>>>;

  const std::vector<Test> testCases = {{{1, 0, -1, 0, -2, 2}, 0, {{-1, 0, 0, 1}, {-2, -1, 1, 2}, {-2, 0, 0, 2}}},
                                       {{0, 0, 0, 0}, 0, {{0, 0, 0, 0}}}};

  for (const auto& [nums, target, expt] : testCases) {
    auto numsMutable = nums;
    const auto result = FourSum(&numsMutable, target);

    ASSERT_TRUE(::NoDuplicate(result));
    ASSERT_TRUE(std::is_permutation(result.cbegin(), result.cend(), expt.cbegin(), expt.cend()));
  }
}

}  // namespace algorithms::test
