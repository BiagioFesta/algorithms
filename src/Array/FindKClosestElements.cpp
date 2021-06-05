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
#include <algorithms/Array/FindKClosestElements.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

std::vector<int> FindKClosestElements(const std::vector<int>& arr, const int k, const int x) {
  assert(k >= 0);
  assert(std::is_sorted(arr.cbegin(), arr.cend()));
  assert(static_cast<std::size_t>(k) <= arr.size());

  if (arr.empty()) {
    return {};
  }

  auto lo = std::lower_bound(arr.cbegin(), arr.cend(), x);  // O(logN);
  if (lo == arr.cend()) {
    lo = arr.cend() - k;
  } else if (lo != arr.cbegin() && (x - *(lo - 1) <= (*lo - x))) {
    --lo;
  }
  auto hi = lo + 1;

  while (std::distance(lo, hi) < k) {  // O(K)
    if (hi == arr.cend()) {
      assert(lo != arr.cbegin());
      --lo;
    } else {
      if (lo == arr.cbegin()) {
        ++hi;
      } else {
        const int di = x - *(lo - 1);
        const int dj = *hi - x;
        if (di <= dj) {
          --lo;
        } else {
          ++hi;
        }
      }
    }
  }

  std::vector<int> result(lo, hi);  // O(K)
  return result;
}

}  // namespace algorithms
