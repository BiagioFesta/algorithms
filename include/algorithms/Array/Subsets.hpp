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
#ifndef ALGORITHMS__ARRAY__SUBSETS__HPP
#define ALGORITHMS__ARRAY__SUBSETS__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a set of distinct integers, nums, return all possible subsets
 *  (the power set).
 *  Note: The solution set must not contain duplicate subsets.
 *
 *  \note  Complexity  -->  Time: O(2^N)   Space: O(1)
 *  \note https://leetcode.com/problems/subsets/
 */
std::vector<std::vector<int>> Subsets(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__SUBSETS__HPP
