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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__DELETEANDEARN__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__DELETEANDEARN__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array nums of integers, you can perform operations on the
 *  array.
 *  In each operation, you pick any nums[i] and delete it to earn nums[i]
 *  points. After, you must delete every element equal to nums[i] - 1 or
 *  nums[i] + 1.
 *  You start with 0 points. Return the maximum number of points you can earn by
 *  applying such operations.
 *  Note that, each element nums[i] is an integer in the range [1, 10000].
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(1)
 *  \note https://leetcode.com/problems/delete-and-earn/
 */
int DeleteAndEarn(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__DELETEANDEARN__HPP
