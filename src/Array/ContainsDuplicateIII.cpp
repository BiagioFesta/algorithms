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
#include <algorithms/Array/ContainsDuplicateIII.hpp>
#include <cassert>
#include <set>
#include <vector>

namespace algorithms {

bool ContainsDuplicateIII(const std::vector<int>& nums,
                          const int k,
                          const int t) {
  std::set<long long> numsWindow;
  for (std::size_t i = 0; i < nums.size(); ++i) {
    const long long value = nums[i];
    const long long lb = value - t;
    const long long ub = value + t;

    const auto dupIt = numsWindow.lower_bound(lb);
    if (dupIt != numsWindow.cend() && *dupIt <= ub) {
      return true;
    }

    numsWindow.insert(value);
    if (numsWindow.size() > static_cast<std::size_t>(k)) {
      numsWindow.erase(nums[i - k]);
    }
  }
  return false;
}

}  // namespace algorithms
