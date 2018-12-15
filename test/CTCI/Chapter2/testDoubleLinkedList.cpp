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
#include <algorithms/CTCI/Chapter2/DoubleLinkedList.hpp>
#include <string>
#include <utility>
#include <vector>

namespace {

class DoubleLinkedListTest : public ::testing::Test {
 public:
  using value_type = std::string;
  using DoubleLinkedList = ::algorithms::DoubleLinkedList<value_type>;

  const value_type kValue = "This is a string";
  const std::vector<value_type> kSequence{"String Index 0",
                                          "String Index 1",
                                          "String Index 2",
                                          "String Index 3",
                                          "String Index 4",
                                          "String Index 5",
                                          "String Index 6"};

  DoubleLinkedList _list;
};

}  // anonymous namespace

namespace algorithms::test {

TEST_F(DoubleLinkedListTest, StartFromEmpty) { ASSERT_EQ(_list.size(), 0ull); }

TEST_F(DoubleLinkedListTest, PushOneValue) {
  _list.push_back(kValue);
  ASSERT_EQ(_list.size(), 1ull);
  ASSERT_EQ(_list.getByIndex(0), kValue);
  ASSERT_FALSE(kValue.empty());
}

TEST_F(DoubleLinkedListTest, MoveOneValue) {
  value_type movValue = kValue;

  _list.push_back(std::move(movValue));
  ASSERT_EQ(_list.size(), 1ull);
  ASSERT_EQ(_list.getByIndex(0), kValue);
  ASSERT_TRUE(movValue.empty());
}

TEST_F(DoubleLinkedListTest, PushSequence) {
  for (const auto& value : kSequence) {
    const auto sizeBeforePush = _list.size();

    _list.push_back(value);
    ASSERT_TRUE(_list.size() == sizeBeforePush + 1ull);
    ASSERT_EQ(_list.getByIndex(sizeBeforePush), value);
  }
}

TEST_F(DoubleLinkedListTest, ConstructFromSequence) {
  DoubleLinkedList initList(kSequence.cbegin(), kSequence.cend());
  ASSERT_EQ(initList.size(), kSequence.size());

  for (std::size_t i = 0ll; i < kSequence.size(); ++i) {
    ASSERT_EQ(initList.getByIndex(i), kSequence[i]);
  }
}

TEST_F(DoubleLinkedListTest, AssignmentOperator) {
  DoubleLinkedList initList(kSequence.cbegin(), kSequence.cend());
  _list = initList;

  ASSERT_EQ(_list.size(), initList.size());

  for (std::size_t i = 0ll; i < _list.size(); ++i) {
    ASSERT_EQ(_list.getByIndex(i), initList.getByIndex(i));
  }
}

TEST_F(DoubleLinkedListTest, MoveOperator) {
  DoubleLinkedList initList(kSequence.cbegin(), kSequence.cend());
  _list = std::move(initList);

  ASSERT_EQ(initList.size(), 0ull);
  ASSERT_EQ(_list.size(), kSequence.size());

  for (std::size_t i = 0ll; i < _list.size(); ++i) {
    ASSERT_EQ(_list.getByIndex(i), kSequence[i]);
  }
}

}  // namespace algorithms::test
