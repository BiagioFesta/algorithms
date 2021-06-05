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
#ifndef ALGORITHMS__ARRAY__COUNTSMALLERAFTERSELF__HPP
#define ALGORITHMS__ARRAY__COUNTSMALLERAFTERSELF__HPP
#include <vector>

namespace algorithms {

/*! \brief You are given an integer array nums and you have to return a new
 *  counts array. The counts array has the property where counts[i] is the
 *  number of smaller elements to the right of nums[i].
 *
 *  \note  Complexity  -->  Time: O(NlogN)  Space: O(N)
 *  \note https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 */
std::vector<int> CountSmallerAfterSelf(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__COUNTSMALLERAFTERSELF__HPP
