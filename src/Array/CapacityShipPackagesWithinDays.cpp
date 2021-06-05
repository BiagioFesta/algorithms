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
#include <algorithms/Array/CapacityShipPackagesWithinDays.hpp>
#include <vector>

namespace {

//! \note  Complexity  -->  Time: O(N)  Space: O(1)
bool IsSolvable(const std::vector<int>& weights, const int D, const int C) noexcept {
  int c = 0;
  int d = 1;
  for (const int w : weights) {
    if (C < c + w) {
      c = w;
      if (D < ++d) {
        return false;
      }
    } else {
      c += w;
    }
  }
  return true;
}

}  // anonymous namespace

namespace algorithms {

int CapacityShipPackagesWithinDays(const std::vector<int>& weights, const int D) {
  int lo = 0, hi = 0, mid;

  for (const int w : weights) {  // O(N)
    hi += w;
    lo = std::max(lo, w);
  }

  while (lo < hi) {  // O(logS)
    mid = (lo + hi) / 2;
    if (::IsSolvable(weights, D, mid)) {  // O(N)
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  return lo;
}

}  // namespace algorithms
