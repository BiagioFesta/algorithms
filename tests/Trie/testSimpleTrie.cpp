/*
  Copyright (C) 2021  Biagio Festa

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
#include <algorithms/Trie/SimpleTrie.hpp>
#include <utility>

namespace {

const char* kStr1 = "foo";
const char* kStr2 = "bar";
const char* kStr3 = "baz";
const char* kStr4 = "aaabbb";
const char* kStr5 = "aaa";
const char* kStr6 = "a";

}  // anonymous namespace

namespace algorithms::test {

TEST(SimpleTrie, NoFindWhenEmpty) {
  SimpleTrie trie;
  ASSERT_FALSE(trie.find(::kStr1));
}

TEST(SimpleTrie, InsertAndFind) {
  SimpleTrie trie;

  ASSERT_FALSE(trie.find(::kStr1));
  trie.insert(::kStr1);

  ASSERT_TRUE(trie.find(::kStr1));
  ASSERT_FALSE(trie.find(::kStr2));
}

TEST(SimpleTrie, TwoInsertAndFind) {
  SimpleTrie trie;

  ASSERT_FALSE(trie.find(::kStr1));
  ASSERT_FALSE(trie.find(::kStr2));
  trie.insert(::kStr1);
  trie.insert(::kStr2);

  ASSERT_TRUE(trie.find(::kStr1));
  ASSERT_TRUE(trie.find(::kStr2));
  ASSERT_FALSE(trie.find(::kStr3));
}

TEST(SimpleTrie, DuplicateInsertAndFind) {
  SimpleTrie trie;

  trie.insert(::kStr1);
  ASSERT_TRUE(trie.find(::kStr1));

  trie.insert(::kStr1);
  ASSERT_TRUE(trie.find(::kStr1));
}

TEST(SimpleTrie, InsertComposer) {
  SimpleTrie trie;

  trie.insert(::kStr4);
  ASSERT_FALSE(trie.find(::kStr5));
}

TEST(SimpleTrie, InsertComposerAndPrefix) {
  SimpleTrie trie;

  trie.insert(::kStr4);
  trie.insert(::kStr5);
  ASSERT_TRUE(trie.find(::kStr5));
}

TEST(SimpleTrie, OneCharLen) {
  SimpleTrie trie;

  trie.insert(::kStr6);
  ASSERT_TRUE(trie.find(::kStr6));
}

}  // namespace algorithms::test
