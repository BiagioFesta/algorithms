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
#ifndef ALGORITHMS__ARRAY__INCREASINGTRIPLETSUBSEQUENCE__HPP
#define ALGORITHMS__ARRAY__INCREASINGTRIPLETSUBSEQUENCE__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an unsorted array return whether an increasing subsequence of
 *  length 3 exists or not in the array.
 *  Formally the function should:
 *        Return true if there exists i, j, k
 *        such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1
 *        else return false.
 *  Note: Your algorithm should run in O(n) time complexity and O(1) space
 *  complexity.
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(1)
 *  \note https://leetcode.com/problems/increasing-triplet-subsequence/
 */
bool IncreasingTripletSubsequence(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__INCREASINGTRIPLETSUBSEQUENCE__HPP
