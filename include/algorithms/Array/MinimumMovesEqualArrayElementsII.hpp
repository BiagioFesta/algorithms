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
#ifndef ALGORITHMS__ARRAY__MINIMUMMOVESEQUALARRAYELEMENTSII__HPP
#define ALGORITHMS__ARRAY__MINIMUMMOVESEQUALARRAYELEMENTSII__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a non-empty integer array, find the minimum number of moves
 *  required to make all array elements equal, where a move is incrementing a
 *  selected element by 1 or decrementing a selected element by 1.
 *  You may assume the array's length is at most 10,000.
 *  \note The array is not empty!
 *
 *  \note  Complexity  -->  Time: O(N)   Space: O(N)
 *  \note
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 */
int MinimumMovesEqualArrayElementsII(const std::vector<int>& nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__MINIMUMMOVESEQUALARRAYELEMENTSII__HPP
