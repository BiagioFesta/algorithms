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
#include <MinStack.hpp>

namespace algorithms::test {

static constexpr int kSize = 42;

TEST(MinStack, PushAndTop) {
  MinStack<int> mStack;
  for (int i = 0; i < kSize; ++i) {
    mStack.push(i);
    ASSERT_EQ(mStack.top(), i);
  }
}

TEST(MinStack, KeepMin) {
  MinStack<int> mStack;
  for (int i = 0; i < kSize; ++i) {
    mStack.push(i);
    if ((i + 1) % 3 == 0) mStack.pop();
    ASSERT_EQ(mStack.getMin(), 0);
  }
}

TEST(MinStack, GetMinOnEmpty) {
  MinStack<int> mStack;
  mStack.push(1);
  ASSERT_EQ(mStack.getMin(), 1);
  mStack.pop();
  ASSERT_THROW(mStack.getMin(), std::exception);
}

}  // namespace algorithms::test
