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
#ifndef ALGORITHMS__ARRAY__RANKTRANSFORMARRAY__HPP
#define ALGORITHMS__ARRAY__RANKTRANSFORMARRAY__HPP
#include <algorithm>
#include <vector>

namespace algorithms {

/*! \brief Given an array of integers arr, replace each element with its rank.
 *  The rank represents how large the element is. The rank has the following
 *  rules:
 *    - Rank is an integer starting from 1.
 *    - The larger the element, the larger the rank. If two elements are equal,
 *      their rank must be the same.
 *    - Rank should be as small as possible.
 *
 *  \note  Complexity  -->  Time: O(NlogN)  Space: O(N)
 *  \note https://leetcode.com/problems/rank-transform-of-an-array/
 */
std::vector<int> RankTransformArray(const std::vector<int>& v);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__RANKTRANSFORMARRAY__HPP
