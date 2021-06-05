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
#include <algorithm>
#include <algorithms/DynamicProgramming/MinSwap.hpp>
#include <array>
#include <cassert>
#include <limits>
#include <utility>
#include <vector>

namespace algorithms {

int MinSwap(const std::vector<int>& A, const std::vector<int>& B) {
  constexpr std::size_t kMaxSize = 1000;
  constexpr auto kMaxInt = std::numeric_limits<int>::max();
  assert(A.size() == B.size());
  assert(A.size() <= kMaxSize);

  const auto kSize = A.size();
  const auto kSizeMinusOne = kSize - 1;

  if (kSize == 1) {
    return 0;
  }

  std::array<std::pair<int, int>, kMaxSize> table;
  for (auto i = kSizeMinusOne; i > 0; --i) {
    table[i].first = kMaxInt;
    table[i].second = kMaxInt;

    if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
      if (i != kSizeMinusOne) {
        table[i].first = table[i + 1].first;
        table[i].second = table[i + 1].second + 1;
      } else {
        table[i].first = 0;
        table[i].second = 1;
      }
    }

    if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
      if (i != kSizeMinusOne) {
        table[i].first = std::min(table[i].first, table[i + 1].second + 1);
        table[i].second = std::min(table[i].second, table[i + 1].first);
      } else {
        table[i].first = std::min(table[i].first, 1);
        table[i].second = std::min(table[i].second, 0);
      }
    }

    assert(table[i].first != kMaxInt);
    assert(table[i].second != kMaxInt);
  }

  return std::min(table[1].first, table[1].second + 1);
}

}  // namespace algorithms
