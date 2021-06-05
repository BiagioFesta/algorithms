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
#ifndef ALGORITHMS__ARRAY__FOUR_SUM__HPP
#define ALGORITHMS__ARRAY__FOUR_SUM__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array nums of n integers and an integer target, are there
 *  elements a, b, c, and d in nums such that a + b + c + d = target? Find all
 *  unique quadruplets in the array which gives the sum of target.
 *  \note The solution set must not contain duplicate quadruplets.
 *
 *  \note   Complexity  ->   Time: O(N^3)    Space: O(1)
 *  \note https://leetcode.com/problems/4sum/
 */
std::vector<std::vector<int>> FourSum(std::vector<int>* iNumbers, const int iTarget);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FOUR_SUM__HPP
