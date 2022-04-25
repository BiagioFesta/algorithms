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
#ifndef ALGORITHMS__ARRAY__FIND_K_LARGEST__HPP
#define ALGORITHMS__ARRAY__FIND_K_LARGEST__HPP
#include <vector>

namespace algorithms {

/*! Find the kth largest element in an unsorted array.
 *  \note that it is the kth largest element in the sorted order, not the kth
 *  distinct element.
 *  \note k must be valid: 1 <= k <= nums.size()
 *
 *  \note  Complexity  ->  Time: O(N)    Space: O(N)
 *  \note https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
int FindKLargest(std::vector<int> nums, const int k);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FIND_K_LARGEST__HPP
