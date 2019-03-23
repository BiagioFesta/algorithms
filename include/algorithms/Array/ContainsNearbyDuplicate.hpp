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
#ifndef ALGORITHMS__ARRAY__CONTAINS_NEARBY_DUPLICATE__HPP
#define ALGORITHMS__ARRAY__CONTAINS_NEARBY_DUPLICATE__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array of integers and an integer k, it finds out whether
 *  there are two distinct indices i and j in the array such that iNums[i] =
 *  iNums[j] and the absolute difference between i and j is at most k.
 *  \note  Complexity ->  Time: O(N)        Space: O(N)
 *  \note https://leetcode.com/problems/contains-duplicate-ii/description/
 */
bool ContainsNearbyDuplicate(const std::vector<int>& iNums, const int k);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__CONTAINS_NEARBY_DUPLICATE__HPP
