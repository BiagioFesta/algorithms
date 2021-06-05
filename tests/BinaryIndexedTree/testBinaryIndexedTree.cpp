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
#include <algorithms/BinaryIndexedTree/BinaryIndexedTree.hpp>
#include <iterator>
#include <numeric>
#include <vector>

namespace {

using IntegerType = int;
using BIT = algorithms::BinaryIndexedTree<IntegerType>;
constexpr std::size_t kTestSize = 1024;

/*! \return the sum of first index-th positive numbers.
 *  E.g.   index = 3  -->  1 + 2 + 3 = 6
 */
IntegerType SumPositiveNumbers(const std::size_t index) {
  return (index * index + index) >> 1;
}

}  // anonymous namespace

namespace algorithms::test {

TEST(BinaryIndexedTree, DefaultZeros) {
  ::BIT bit(::kTestSize);

  for (std::size_t i = 0; i < ::kTestSize; ++i) {
    ASSERT_EQ(bit.sum(i), 0);
  }
}

TEST(BinaryIndexedTree, IncrementalSum) {
  ::BIT bit(::kTestSize);
  for (std::size_t i = 0; i < ::kTestSize; ++i) {
    bit.update(i, i);
  }

  for (std::size_t i = 0; i < ::kTestSize; ++i) {
    ASSERT_EQ(bit.sum(i), ::SumPositiveNumbers(i));
  }
}

TEST(BinaryIndexedTree, IncrementalPartialSum) {
  ::BIT bit(::kTestSize);
  for (std::size_t i = 0; i < ::kTestSize; ++i) {
    bit.update(i, i);
  }

  for (std::size_t i = 0; i < ::kTestSize; ++i) {
    for (std::size_t j = i; j < ::kTestSize; ++j) {
      const auto expt = SumPositiveNumbers(j) - (i ? SumPositiveNumbers(i - 1) : 0);
      ASSERT_EQ(bit.partialSum(i, j), expt);
    }
  }
}

}  // namespace algorithms::test
