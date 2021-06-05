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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__CHEAPEST_JUMP__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__CHEAPEST_JUMP__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array A (index starts at 1) consisting of N integers and an
 *  integer `iMaxJump`. The integer `iMaxJump` denotes that from any place
 *  (suppose the index is i) in the array, you can jump to any one of the place
 *  in the array A indexed i+1, i+2, ,,,, i+B if this place can be jumped to.
 *  Also, if you step on the index i, you have to pay A[i] coins. If A[i] is -1,
 *  it means you can’t jump to the place indexed i in the array.
 *
 *  Now, you start from the place indexed 1 in the array, and your aim is to
 *  reach the place indexed N using the minimum coins. You need to return the
 *  path of indexes (starting from 1 to N) in the array you should take to get
 *  to the place indexed N using minimum coins.
 *
 *  If there are multiple paths with the same cost, return the lexicographically
 *  smallest such path.
 *
 *  If it's not possible to reach the place indexed N then you need to return an
 *  empty array.
 *
 *  \note  Complexity ->  Time: O(N x min(iMaxJump, N))     Space: O(N)
 *  \note https://www.leetfree.com/problems/coin-path.html
 */
std::vector<int> CheapestJump(const std::vector<int>& iVector, const int iMaxJump);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__CHEAPEST_JUMP__HPP
