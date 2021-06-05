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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__UNIQUE_PATHS_II__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__UNIQUE_PATHS_II__HPP
#include <vector>

namespace algorithms {

/*! \brief A robot is located at the top-left corner of a m x n grid.
 *  The robot can only move either down or right at any point in time. The robot
 *  is trying to reach the bottom-right corner of the grid.
 *  Now consider if some obstacles are added to the grids. How many unique paths
 *  would there be?
 *  An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 *  \note Complexity -> Time: O(N x M)   Space: O(N x M)
 *  \note https://leetcode.com/problems/unique-paths-ii/
 */
int UniquePathsWithObstacles(const std::vector<std::vector<int>>& iObstacleGrid);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__UNIQUE_PATHS_II__HPP
