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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__PARTITION_EQUAL_SUB_SUM__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__PARTITION_EQUAL_SUB_SUM__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a non-empty array containing only positive integers, find if
 *  the array can be partitioned into two subsets such that the sum of elements
 *  in both subsets is equal.
 *  \note Each of the array element will not exceed 100.
 *  \note The array size will not exceed 200.
 *
 *  \note Complexity -> Time: O(N x M)  Space: O(N x M)    where M is the sum.
 *  \note https://leetcode.com/problems/partition-equal-subset-sum/
 */
bool PartitionEqualSubSum(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__PARTITION_EQUAL_SUB_SUM__HPP
