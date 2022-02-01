/*
  Copyright (C) 2022  Biagio Festa

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
#include <algorithms/Array/SmallestDivisorThreshold.hpp>
#include <cassert>
#include <cmath>
#include <numeric>

namespace algorithms {

int SmallestDivisorThreshold(const std::vector<int>& nums, const int threshold) {
  assert(!nums.empty());

  int mid, sum;
  int ub = *std::max_element(nums.cbegin(), nums.cend());
  int lb = 1;

  while (ub != lb) {
    mid = lb + (ub - lb) / 2;
    sum = std::accumulate(nums.cbegin(), nums.cend(), 0, [mid](const int sum, const int num) {
      return sum + (int)std::ceil((float)num / (float)mid);
    });

    if (sum <= threshold) {
      ub = mid;
    } else {
      lb = mid + 1;
    }
  }

  return lb;
}

}  // namespace algorithms
