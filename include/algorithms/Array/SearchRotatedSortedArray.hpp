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
#ifndef ALGORITHMS__ARRAY__SEARCHROTATEDSORTEDARRAY__HPP
#define ALGORITHMS__ARRAY__SEARCHROTATEDSORTEDARRAY__HPP
#include <vector>

namespace algorithms {

/*! \brief Suppose an array sorted in ascending order is rotated at some pivot
 *  unknown to you beforehand.
 *      (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *  You are given a target value to search. If found in the array return its
 *  index, otherwise return -1.
 *  You may assume no duplicate exists in the array.
 *  Your algorithm's runtime complexity must be in the order of O(log n).
 *
 *  \note  Complexity  ->  Time: O(logN)   Space: O(1)
 *  \note https://leetcode.com/problems/search-in-rotated-sorted-array/
 */
int SearchRotatedSortedArray(const std::vector<int>& nums, const int target);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__SEARCHROTATEDSORTEDARRAY__HPP
