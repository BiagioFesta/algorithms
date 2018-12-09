/*
  Copyright (C) 2018  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__THREE_SUM__HPP
#define ALGORITHMS__ARRAY__THREE_SUM__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array nums of n integers, are there elements a, b, c in nums
 *  such that a + b + c = 0? Find all unique triplets in the array which gives
 *  the sum of zero.
 *  \note The solution set must not contain duplicate triplets.
 *  \Complexity      Time: O(N^2)    Space: O(1)
 *  \url https://leetcode.com/problems/3sum/description/
 */
std::vector<std::vector<int>> ThreeSum(std::vector<int>* iNumbers);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__THREE_SUM__HPP
