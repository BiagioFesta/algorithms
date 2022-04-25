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
#ifndef ALGORITHMS__ARRAY__LONGESTMOUNTAINARRAY__HPP
#define ALGORITHMS__ARRAY__LONGESTMOUNTAINARRAY__HPP
#include <vector>

namespace algorithms {

/*! \brief Let's call any (contiguous) subarray B (of A) a mountain if the
 *  following properties hold:
 *     - B.length >= 3
 *     - There exists some 0 < i < B.length - 1 such that
 *       B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
 *  (Note that B could be any subarray of A, including the entire array A.)
 *  Given an array A of integers, return the length of the longest mountain.
 *  Return 0 if there is no mountain.
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(1)
 *  \note https://leetcode.com/problems/longest-mountain-in-array/
 */
int LongestMountainArray(const std::vector<int>& A);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__LONGESTMOUNTAINARRAY__HPP
