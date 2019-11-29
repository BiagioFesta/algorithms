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
#ifndef ALGORITHMS__ARRAY__FINDDUPLICATENUMBER__HPP
#define ALGORITHMS__ARRAY__FINDDUPLICATENUMBER__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array nums containing n + 1 integers where each integer is
 *  between 1 and n (inclusive), prove that at least one duplicate number must
 *  exist. Assume that there is only one duplicate number, find the duplicate
 *  one.
 *  Note: You must not modify the array (assume the array is read only).
 *  Note: You must use only constant, O(1) extra space.
 *  Note: Your runtime complexity should be less than O(n^2).
 *  Note: There is only one duplicate number in the array, but it could be
 *        repeated more than once.
 *
 *  \note  Complexity  -->  Time: O(NlogN)  Space: O(1)
 *  \note https://leetcode.com/problems/find-the-duplicate-number/
 */
int FindDuplicateNumber(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FINDDUPLICATENUMBER__HPP
