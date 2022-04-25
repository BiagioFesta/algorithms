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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__TARGET_SUM__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__TARGET_SUM__HPP
#include <vector>

namespace algorithms {

/*! \brief  You are given a list of non-negative integers, a1, a2, ..., an, and
 *  a target, S. Now you have 2 symbols + and -. For each integer, you should
 *  choose one from + and - as its new symbol. Find out how many ways to assign
 *  symbols to make sum of integers equal to target S.
 *  \note The length of the given array is positive and will not exceed 20.
 *  \note The sum of elements in the given array will not exceed 1000.
 *
 *  \note  Complexity -> Time:  O(N)  Space: O(N)   Considering Max Sum Constant
 *  \note https://leetcode.com/problems/target-sum/
 */
int TargetSum(const std::vector<int>& nums, const int S);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__TARGET_SUM__HPP
