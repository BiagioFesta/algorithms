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
#include <algorithms/Array/MaxWidthRamp.hpp>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithms {

int MaxWidthRamp(const std::vector<int>& A) {
  if (A.size() < 2) return 0;

  std::vector<std::pair<int, int>> meta;
  meta.reserve(A.size());
  for (std::size_t i = 0; i < A.size(); ++i) {  // O(N)
    meta.emplace_back(A[i], i);
  }
  std::sort(meta.begin(), meta.end());  // O(NlogN)

  int max = 0;
  int minIndex = meta[0].second;
  for (auto [_, index] : meta) {  // O(N)
    max = std::max(max, index - minIndex);
    minIndex = std::min(minIndex, index);
  }

  return max;
}

}  // namespace algorithms
