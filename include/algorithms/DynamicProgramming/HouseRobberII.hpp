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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__HOUSEROBBERII__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__HOUSEROBBERII__HPP
#include <vector>

namespace algorithms {

/*! \brief You are a professional robber planning to rob houses along a street.
 *  Each house has a certain amount of money stashed. All houses at this place
 *  are arranged in a circle. That means the first house is the neighbor of the
 *  last one. Meanwhile, adjacent houses have security system connected and it
 *  will automatically contact the police if two adjacent houses were broken
 *  into on the same night.
 *  Given a list of non-negative integers representing the amount of money of
 *  each house, determine the maximum amount of money you can rob tonight
 *  without alerting the police.
 *
 * \note  Complexity  -->  Time: O(N^2)   Space: O(N)
 *  \note https://leetcode.com/problems/house-robber-ii/
 */
int HouseRobberII(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__HOUSEROBBERII__HPP
