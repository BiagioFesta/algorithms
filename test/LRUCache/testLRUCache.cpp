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
#include <algorithms/LRUCache/LRUCache.hpp>
#include <utility>

namespace algorithms::test {

TEST(LRUCache, SetAndGet) {
  static constexpr std::pair<int, int> p = {1, 2};

  LRUCache cache(1);
  cache.set(p.first, p.second);

  ASSERT_EQ(cache.get(p.first), p.second);
}

TEST(LRUCache, OverflowCapacity) {
  static constexpr std::pair<int, int> p1 = {1, 1};
  static constexpr std::pair<int, int> p2 = {2, 2};
  static constexpr std::pair<int, int> p3 = {3, 3};

  LRUCache cache(2);

  cache.set(p1.first, p1.second);
  ASSERT_EQ(cache.get(p1.first), p1.second);

  cache.set(p2.first, p2.second);
  ASSERT_EQ(cache.get(p2.first), p2.second);

  cache.set(p3.first, p3.second);
  ASSERT_EQ(cache.get(p3.first), p3.second);

  ASSERT_EQ(cache.get(p1.first), -1);
  ASSERT_EQ(cache.get(p2.first), p2.second);
}

TEST(LRUCache, ZeroCapacity) {
  static constexpr std::pair<int, int> p1 = {1, 1};
  LRUCache cache(0);

  cache.set(p1.first, p1.second);
  ASSERT_EQ(cache.get(p1.first), -1);
}

TEST(LRUCache, SetOverride) {
  LRUCache cache(1);

  cache.set(1, 1);
  ASSERT_EQ(cache.get(1), 1);

  cache.set(1, 2);
  ASSERT_EQ(cache.get(1), 2);
}

TEST(LRUCache, RefreshInMiddle) {
  static constexpr std::pair<int, int> p1 = {1, 1};
  static constexpr std::pair<int, int> p2 = {2, 2};
  static constexpr std::pair<int, int> p3 = {3, 3};

  LRUCache cache(3);

  cache.set(p1.first, p1.second);
  ASSERT_EQ(cache.get(p1.first), p1.second);

  cache.set(p2.first, p2.second);
  ASSERT_EQ(cache.get(p2.first), p2.second);

  cache.set(p3.first, p3.second);
  ASSERT_EQ(cache.get(p3.first), p3.second);

  cache.set(p2.first, p2.second + 1);
  ASSERT_EQ(cache.get(p2.first), p2.second + 1);
}

}  // namespace algorithms::test
