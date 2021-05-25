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
#include <algorithms/CTCI/Chapter2/RemoveDuplicates.hpp>
#include <list>
#include <unordered_set>
#include <vector>

namespace {

bool DoesNotHaveDuplicates(const std::list<int>& iList) {
  std::unordered_set<int> set(iList.cbegin(), iList.cend());
  return iList.size() == set.size();
}

using Test = std::vector<int>;
const std::vector<Test> testCases = {{1, 2, 3, 4, 5, 6, 7},
                                     {1, 1, 2, 2, 3, 3, 4, 4, 5, 5},
                                     {1, 2, 1, 2, 3, 4, 3, 4, 5, 6, 5, 6}};

}  // anonymous namespace

namespace algorithms::test {

TEST(CTCIChapter2, RemoveDuplicates) {
  for (const auto& test : testCases) {
    std::list<int> list(test.cbegin(), test.cend());

    RemoveDuplicates(&list);
    ASSERT_TRUE(::DoesNotHaveDuplicates(list));
  }
}

TEST(CTCIChapter2, RemoveDuplicatesSpaceOptimized) {
  for (const auto& test : testCases) {
    std::list<int> list(test.cbegin(), test.cend());

    RemoveDuplicatesSpaceOptimized(&list);
    ASSERT_TRUE(::DoesNotHaveDuplicates(list));
  }
}

}  // namespace algorithms::test
