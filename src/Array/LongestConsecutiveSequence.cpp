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
#include <algorithms/Array/LongestConsecutiveSequence.hpp>
#include <unordered_set>
#include <vector>

namespace algorithms {

int LongestConsecutiveSequence(const std::vector<int>& nums) {
  std::unordered_set<int> set(nums.cbegin(), nums.cend());  // O(N)

  int next, ans = 0;

  for (const int n : nums) {  // O(N)
    if (!set.count(n - 1)) {  // O(1)
      next = n;
      while (set.count(next)) {  // O(~~~N~~~)
        set.erase(next);         // // O(1)
        ++next;
      }
      ans = std::max(ans, next - n);
    }
  }

  return ans;
}

}  // namespace algorithms
