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
#include <algorithms/FlatSet/FlatSet.hpp>
#include <algorithm>
#include <array>
#include <iterator>
#include <limits>
#include <numeric>
#include <set>

namespace {

constexpr int kFixedNumber = 42;
constexpr std::array<int, 10> kSequence{6, 1, 10, 2, -4, 12, 2, 8, 162, 0};

/*! \brief Naive function in order to count the number of unique elements inside
 *  a container.
 */
template <typename InputIt>
std::size_t CountUniqueElements(InputIt first, InputIt last) {
  using value_type = typename std::iterator_traits<InputIt>::value_type;
  return std::set<value_type>(first, last).size();
}

}  // anonymous namespace

namespace algorithms::test {

TEST(FlatSet, DefaultSetIsEmpty) {
  FlatSet<int> aFlatSet;
  ASSERT_TRUE(aFlatSet.empty());
}

TEST(FlatSet, DefaultIsZeroSize) {
  FlatSet<int> aFlatSet;
  ASSERT_EQ(aFlatSet.size(), 0u);
}

TEST(FlatSet, InsertThenNotEmpty) {
  FlatSet<int> aFlatSet;
  aFlatSet.insert(::kFixedNumber);

  ASSERT_FALSE(aFlatSet.empty());
}

TEST(FlatSet, InsertIncreaseSize) {
  FlatSet<int> aFlatSet;
  aFlatSet.insert(::kFixedNumber);

  ASSERT_EQ(aFlatSet.size(), 1u);
}

TEST(FlatSet, FirstInsert) {
  FlatSet<int> aFlatSet;
  const auto aResult = aFlatSet.insert(::kFixedNumber);

  ASSERT_NE(aResult.first, aFlatSet.cend());
  ASSERT_TRUE(aResult.second);
}

TEST(FlatSet, SameInsert) {
  FlatSet<int> aFlatSet;
  const auto aFirstInsert = aFlatSet.insert(::kFixedNumber);
  const auto aSecondInsert = aFlatSet.insert(::kFixedNumber);

  ASSERT_FALSE(aSecondInsert.second);
  ASSERT_EQ(aSecondInsert.first, aFirstInsert.first);
}

TEST(FlatSet, MultipleInsertIncreaseSize) {
  constexpr std::size_t kNumInsert = 64;

  FlatSet<int> aFlatSet;

  for (std::size_t i = 0u; i < kNumInsert; ++i) {
    aFlatSet.insert(i);
    ASSERT_EQ(aFlatSet.size(), i + 1);
  }
}

TEST(FlatSet, LookUpNotFound) {
  FlatSet<int> aFlatSet;
  ASSERT_EQ(aFlatSet.find(::kFixedNumber), aFlatSet.cend());
  ASSERT_FALSE(aFlatSet.contains(::kFixedNumber));
  ASSERT_EQ(aFlatSet.count(::kFixedNumber), 0u);
}

TEST(FlatSet, LookUpFound) {
  FlatSet<int> aFlatSet;
  aFlatSet.insert(::kFixedNumber);

  ASSERT_NE(aFlatSet.find(::kFixedNumber), aFlatSet.cend());
  ASSERT_TRUE(aFlatSet.contains(::kFixedNumber));
  ASSERT_EQ(aFlatSet.count(::kFixedNumber), 1u);
}

TEST(FlatSet, SetIsSorted) {
  FlatSet<int> aFlatSet(::kSequence.cbegin(), ::kSequence.cend());

  ASSERT_EQ(::CountUniqueElements(::kSequence.cbegin(), ::kSequence.cend()),
            aFlatSet.size());
  ASSERT_TRUE(std::is_sorted(aFlatSet.cbegin(), aFlatSet.cend()));
}

TEST(FlatSet, CapacityNotLessSize) {
  constexpr std::size_t kNumInsert = 64;

  FlatSet<int> aFlatSet;

  for (std::size_t i = 0u; i < kNumInsert; ++i) {
    aFlatSet.insert(i);
    ASSERT_GE(aFlatSet.capacity(), aFlatSet.size());
  }
}

TEST(FlatSet, SetCapacity) {
  FlatSet<int> aFlatSet;
  aFlatSet.reserve(::kFixedNumber);

  ASSERT_EQ(aFlatSet.capacity(), ::kFixedNumber);
}

TEST(FlatSet, ForEachReadIncreasing) {
  const FlatSet<int> aFlatSet(::kSequence.cbegin(), ::kSequence.cend());

  int prev = std::numeric_limits<int>::min();
  for (const int n : aFlatSet) {
    ASSERT_GE(n, prev);
  }
}

TEST(FlatSet, ForEachWritePlusOne) {
  FlatSet<int> aFlatSet(::kSequence.cbegin(), ::kSequence.cend());
  const int aTotalSum = std::accumulate(aFlatSet.cbegin(), aFlatSet.cend(), 0);

  for (int& n : aFlatSet) {
    ++n;
  }

  const int aTotalSumAfter =
      std::accumulate(aFlatSet.cbegin(), aFlatSet.cend(), 0);

  ASSERT_EQ(aTotalSum + static_cast<int>(aFlatSet.size()), aTotalSumAfter);
}

}  // namespace algorithms::test
