/*
  Copyright (C) 2020  Biagio Festa

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
#include <algorithms/Array/NextPermutation.hpp>
#include <cstdint>
#include <utility>
#include <vector>

namespace algorithms {

void NextPermutation(std::vector<int>* nums) {
  using IndexT = std::int64_t;

  if (const IndexT size = static_cast<IndexT>(nums->size()); size > 1) {
    IndexT i, j;

    i = j = size - 1;

    while (i > 0 && (*nums)[i] <= (*nums)[i - 1]) --i;  // O(N)
    if (i) {
      while ((*nums)[j] <= (*nums)[i - 1]) --j;  // O(N)
      std::swap((*nums)[i - 1], (*nums)[j]);     // O(1)
    }
    std::reverse(nums->begin() + i, nums->end());  // O(N)
  }
}

}  // namespace algorithms
