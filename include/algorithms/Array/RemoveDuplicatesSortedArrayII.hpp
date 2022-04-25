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
#ifndef ALGORITHMS__ARRAY__REMOVEDUPLICATESSORTEDARRAYII__HPP
#define ALGORITHMS__ARRAY__REMOVEDUPLICATESSORTEDARRAYII__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a sorted array nums, remove the duplicates in-place such that
 *  duplicates appeared at most twice and return the new length.
 *  Do not allocate extra space for another array, you must do this by modifying
 *  the input array in-place with O(1) extra memory.
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(1)
 *  \note https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 */
int RemoveDuplicatesSortedArrayII(std::vector<int>* nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__REMOVEDUPLICATESSORTEDARRAYII__HPP
