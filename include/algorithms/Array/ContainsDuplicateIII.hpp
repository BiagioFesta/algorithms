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
#ifndef ALGORITHMS__ARRAY__CONTAINS_DUPLICATE_III__HPP
#define ALGORITHMS__ARRAY__CONTAINS_DUPLICATE_III__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array of integers, find out whether there are two distinct
 *         indices i and j in the array such that the absolute difference
 *         between nums[i] and nums[j] is at most t and the absolute difference
 *         between i and j is at most k.
 *
 *  \note  Complexity  ->  Time: O(NlogK)   Space: O(K)
 *  \note https://leetcode.com/problems/contains-duplicate-iii/
 */
bool ContainsDuplicateIII(const std::vector<int>& nums, const int k, const int t);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__CONTAINS_DUPLICATE_III__HPP
