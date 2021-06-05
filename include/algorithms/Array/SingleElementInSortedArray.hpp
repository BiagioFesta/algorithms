/*
  Copyright (C) 2021  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__SINGLEELEMENTINSORTEDARRAY__HPP
#define ALGORITHMS__ARRAY__SINGLEELEMENTINSORTEDARRAY__HPP
#include <vector>

namespace algorithms {

/*! \brief You are given a sorted array consisting of only integers where every
 *  element appears exactly twice, except for one element which appears exactly
 *  once. Find this single element that appears only once.
 *  \note Your solution should run in O(log n) time and O(1) space.
 *
 *  \note  Complexity  ->  Time: O(logN)  Space: O(N)
 *  \note https://leetcode.com/problems/single-element-in-a-sorted-array/
 */
int SingleElementInSortedArray(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__SINGLEELEMENTINSORTEDARRAY__HPP
