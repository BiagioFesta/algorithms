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
#include <algorithms/MinStack/MinStack.hpp>

namespace algorithms::test {

TEST(MinStack, PushAndTop) {
  const int kSize = 42;

  MinStack<int> mStack;
  for (int i = 0; i < kSize; ++i) {
    mStack.push(i);
    ASSERT_EQ(mStack.top(), i);
  }
}

TEST(MinStack, KeepMin) {
  const std::vector<int> aNumsSequence = {10, 20, 30, 5, 15, 25, 2, 9, 18};

  MinStack<int> mStack;
  for (std::size_t i = 0; i < aNumsSequence.size(); ++i) {
    mStack.push(aNumsSequence[i]);

    ASSERT_EQ(*std::min_element(aNumsSequence.cbegin(),
                                aNumsSequence.cbegin() + i + 1),
              mStack.getMin());
  }
}

TEST(MinStack, PushAndSize) {
  const int kSize = 42;

  MinStack<int> mStack;
  for (int i = 0; i < kSize; ++i) {
    ASSERT_EQ(mStack.size(), static_cast<std::size_t>(i));
    mStack.push(i);
  }

  ASSERT_EQ(mStack.size(), static_cast<std::size_t>(kSize));
}

TEST(MinStack, PushAndPop) {
  const int kSize = 42;

  MinStack<int> mStack;
  for (int i = 0; i < kSize; ++i) {
    mStack.push(i);
  }

  for (int i = 0; i < kSize; ++i) {
    ASSERT_EQ(mStack.size(), static_cast<std::size_t>(kSize - i));
    mStack.pop();
  }

  ASSERT_EQ(mStack.size(), 0ull);
}

}  // namespace algorithms::test
