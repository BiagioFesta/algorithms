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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__LONGESTARITHMETICSUBSEQUENCEDIFFERENCE__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__LONGESTARITHMETICSUBSEQUENCEDIFFERENCE__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an integer array arr and an integer difference, return the
 *  length of the longest subsequence in arr which is an arithmetic sequence
 *  such that the difference between adjacent elements in the subsequence equals
 *  difference.
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(N)
 *  \note
 * https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
 */
int LongestArithmeticSubsequenceDifference(const std::vector<int>& arr, const int difference);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__LONGESTARITHMETICSUBSEQUENCEDIFFERENCE__HPP
