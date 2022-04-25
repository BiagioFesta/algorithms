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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__UNIQUEPATHS__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__UNIQUEPATHS__HPP

namespace algorithms {

/*! \brief A robot is located at the top-left corner of a m x n grid (marked
 *  'Start' in the diagram below).
 *  The robot can only move either down or right at any point in time. The robot
 *  is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 *  the diagram below).
 *  How many possible unique paths are there?
 *
 *  \note  Complexity  -->  Time: O(m x n)  Space: O(m x n)
 *  \note https://leetcode.com/problems/unique-paths/
 */
int UniquePaths(const int m, const int n);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__UNIQUEPATHS__HPP
