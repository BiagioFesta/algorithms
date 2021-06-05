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
#ifndef ALGORITHMS__ARRAY__GLOBAL_LOCAL_INVERSIONS__HPP
#define ALGORITHMS__ARRAY__GLOBAL_LOCAL_INVERSIONS__HPP
#include <vector>

namespace algorithms {

/*! \brief We have some permutation A of [0, 1, ..., N - 1], where N is the
 *  length of A.
 *  The number of (global) inversions is the number of i < j with
 *  0 <= i < j < N and A[i] > A[j].
 *  The number of local inversions is the number of i with 0 <= i < N
 *  and A[i] > A[i+1].
 *  Return true if and only if the number of global inversions is equal to the
 *  number of local inversions.
 *
 *  \note   Complexity  ->  Time: O(N)  Space: O(1)
 *  \note https://leetcode.com/problems/global-and-local-inversions/
 */
bool GlobalLocalInversions(const std::vector<int>& iVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__GLOBAL_LOCAL_INVERSIONS__HPP
