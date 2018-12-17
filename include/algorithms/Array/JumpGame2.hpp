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
#ifndef ALGORITHMS__ARRAY__JUMP_GAME_2__HPP
#define ALGORITHMS__ARRAY__JUMP_GAME_2__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array of non-negative integers, you are initially positioned
 *  at the first index of the array. Each element in the array represents your
 *  maximum jump length at that position. Your goal is to reach the last index
 *  in the minimum number of jumps.
 *  \note The input problem must always be solveable.
 *  \note Complexity ->  Time: O(N^2)   Space: O(1)
 *  \note https://leetcode.com/problems/jump-game-ii/
 */
int JumpGame2(const std::vector<int>& iNumbers);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__JUMP_GAME_2__HPP
