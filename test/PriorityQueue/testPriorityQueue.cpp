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
#include <algorithms/PriorityQueue/PriorityQueue.hpp>
#include <vector>

namespace algorithms::test {

class PriorityQueueTest : public ::testing::Test {
 public:
  static constexpr int kExampleValue = 42;

  PriorityQueue<int> _priorityQueue;
};

TEST_F(PriorityQueueTest, NewQueueIsEmpty) {
  ASSERT_EQ(_priorityQueue.size(), 0);
  ASSERT_TRUE(_priorityQueue.empty());
}

TEST_F(PriorityQueueTest, OneElement) {
  _priorityQueue.push(kExampleValue);

  ASSERT_EQ(_priorityQueue.top(), kExampleValue);
  ASSERT_EQ(_priorityQueue.size(), 1u);
  ASSERT_FALSE(_priorityQueue.empty());
}

TEST_F(PriorityQueueTest, MaxElement) {
  constexpr int kValues[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
  constexpr int kMaxValue =
      *std::max_element(std::cbegin(kValues), std::cend(kValues));

  for (const int aValue : kValues) {
    _priorityQueue.push(aValue);
  }

  ASSERT_EQ(_priorityQueue.top(), kMaxValue);
}

TEST_F(PriorityQueueTest, PopMax) {
  constexpr int kValues[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
  constexpr int kMaxValue =
      *std::max_element(std::cbegin(kValues), std::cend(kValues));

  for (const int aValue : kValues) {
    _priorityQueue.push(aValue);
  }

  ASSERT_EQ(_priorityQueue.top(), kMaxValue);
  _priorityQueue.pop();
  ASSERT_NE(_priorityQueue.top(), kMaxValue);
}

TEST_F(PriorityQueueTest, PopAll) {
  std::vector<int> aValues = {1, 2, 3, 4, 5, 6, 4, 3, 2, 0, 1};
  for (const int aValue : aValues) {
    _priorityQueue.push(aValue);
  }

  while (!aValues.empty()) {
    const auto aRefMaxValue =
        std::max_element(aValues.cbegin(), aValues.cend());

    ASSERT_EQ(_priorityQueue.top(), *aRefMaxValue);
    _priorityQueue.pop();
    aValues.erase(aRefMaxValue);
  }
}

}  // namespace algorithms::test
