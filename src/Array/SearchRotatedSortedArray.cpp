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
#include <algorithms/Array/SearchRotatedSortedArray.hpp>
#include <vector>

namespace algorithms {

int SearchRotatedSortedArray(const std::vector<int>& nums, const int target) {
  std::size_t lo = 0;
  std::size_t hi = nums.size();
  std::size_t mid;
  int midValue;

  while (lo < hi) {
    mid = (hi - lo) / 2 + lo;
    midValue = nums[mid];

    if (midValue == target) {
      return mid;
    }

    if (midValue < target) {
      if (midValue < nums[lo] && nums[lo] <= target) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    } else {
      if (nums[hi - 1] < midValue && target <= nums[hi - 1]) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
  }
  return -1;
}

}  // namespace algorithms
