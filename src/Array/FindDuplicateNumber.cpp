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
    if (std::count_if(nums.cbegin(), nums.cend(), [isDup](const int n) { return n <= isDup; }) <= isDup) {
      lo = isDup + 1;
    } else {
      hi = isDup;
    }
  }

  return lo;
}

int FindDuplicateNumberFloydLoop(const std::vector<int>& nums) {
  /*
      Brief Explanation:
          We can think the array `nums` as a linked list, with the following
          structure interpretation:

          Let us assume, for instance, the array is:

                        0  1  2  3  4  5   (indices)
             nums :=   [2  3  4  2  5  1]

          Each value in the array represent the index associate with the
          following node in the list. Therefore, we obtain:

               [2]  ->  [4]  ->  [5]  ->  [1]  -> [3]  -> [2] -> ...

          If we reason with that approach, we can apply Floyd's algorithm
          for loop detection (or Tortoise-Hare).

          Another example:

                        0  1  2  3  4  5
             nums :=   [1  2  4  3  5  1]

               [1]  ->  [2]  ->  [4]  ->  [5]  ->  [2]  -> ...

          The duplicate number always is the "starting node" of the loop.

      See also:
      https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare
   */

  assert(nums.size() > 0);

  int p, q;

  p = nums[0];
  q = nums[p];

  while (p != q) {
    p = nums[p];
    q = nums[nums[q]];
  }

  q = 0;
  while (p != q) {
    q = nums[q];
    p = nums[p];
  }

  return p;
}

}  // namespace algorithms
