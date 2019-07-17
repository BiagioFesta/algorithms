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
#include <algorithm>
#include <algorithms/Array/FindKClosestElements.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

std::vector<int> FindKClosestElements(const std::vector<int>& arr,
                                      const int k,
                                      const int x) {
  assert(k >= 0);
  assert(std::is_sorted(arr.cbegin(), arr.cend()));
  assert(static_cast<std::size_t>(k) <= arr.size());

  std::vector<int> result;
  result.reserve(k);

  const auto lb = arr.cbegin() - 1;
  auto j = std::lower_bound(arr.cbegin(), arr.cend(), x);  // O(logN)
  auto i = j - 1;                                          // O(1)

  while (result.size() < static_cast<std::size_t>(k)) {  // O(K)
    if (i == lb) {
      assert(j != arr.cend());
      result.push_back(*(j++));
    } else if (j == arr.cend()) {
      assert(i != arr.cend());
      result.push_back(*(i--));
    } else {
      const int di = x - *i;
      const int dj = *j - x;
      if (di <= dj) {
        result.push_back(*(i--));
      } else {
        result.push_back(*(j++));
      }
    }
  }

  std::sort(result.begin(), result.end());  // O(KlogK)
  return result;
}

}  // namespace algorithms
