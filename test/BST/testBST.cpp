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
#include <algorithms/BST/BST.hpp>

namespace algorithms::test {

TEST(BST, InsertValue) {
  static constexpr int kNumToInsert = 10;
  BST<int> aBST;

  ASSERT_EQ(aBST.getSize(), 0);

  for (int i = 0; i < kNumToInsert; ++i) {
    aBST.insertValue(i);
    ASSERT_EQ(aBST.getSize(), i + 1);
  }
}

TEST(BST, IsStored) {
  static constexpr int kNumToInsert = 10;
  BST<int> aBST;

  for (int i = 0; i < kNumToInsert; ++i) {
    ASSERT_FALSE(aBST.isStored(i));
    aBST.insertValue(i);
    ASSERT_TRUE(aBST.isStored(i));
  }
}

TEST(BST, CleanAll) {
  static constexpr int kNumToInsert = 10;
  BST<int> aBST;

  for (int i = 0; i < kNumToInsert; ++i) {
    aBST.insertValue(i);
  }
  ASSERT_GT(aBST.getSize(), 0);

  aBST.clean();
  ASSERT_EQ(aBST.getSize(), 0);
}

}  // namespace algorithms::test
