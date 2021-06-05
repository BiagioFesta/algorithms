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
#include <algorithms/CTCI/Chapter2/KthToLast.hpp>
#include <forward_list>
#include <numeric>
#include <tuple>
#include <vector>

namespace {

std::forward_list<int> generateNaturalSequence(const int size) {
  std::forward_list<int> seq(size);
  std::iota(seq.begin(), seq.end(), 1);
  return seq;
}

}  // anonymous namespace

namespace algorithms::test {

TEST(CTCIChapter2, KthToLast) {
  constexpr int kNumTests = 32;

  for (int i = 0; i < kNumTests; ++i) {
    const auto size = i + 1;
    const auto seq = ::generateNaturalSequence(size);

    for (int j = 0; j < size; ++j) {
      ASSERT_EQ(KthToLast(seq, j), size - j);
    }
  }
}

}  // namespace algorithms::test
