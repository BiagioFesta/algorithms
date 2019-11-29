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
#include <algorithms/Array/FindDuplicateNumber.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

int FindDuplicateNumber(const std::vector<int>& nums) {
  assert(nums.size() > 0);

  int lo = 1;
  int hi = nums.size() - 1;

  while (lo < hi) {
    const int isDup = (lo + hi) / 2;
    if (std::count_if(nums.cbegin(), nums.cend(), [isDup](const int n) {
          return n <= isDup;
        }) <= isDup) {
      lo = isDup + 1;
    } else {
      hi = isDup;
    }
  }

  return lo;
}

}  // namespace algorithms
