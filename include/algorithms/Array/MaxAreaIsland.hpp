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
#ifndef ALGORITHMS__ARRAY__MAXAREAISLAND__HPP
#define ALGORITHMS__ARRAY__MAXAREAISLAND__HPP
#include <vector>

namespace algorithms {

/*! \brief You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected
 *  4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 *  The area of an island is the number of cells with a value 1 in the island.
 *  Return the maximum area of an island in grid. If there is no island, return 0.
 *
 *  \note    Complexity   -->  Time: O(N)     Space: O(N)
 *  \note https://leetcode.com/problems/max-area-of-island/
 */
int MaxAreaIsland(const std::vector<std::vector<int>>& grid);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__MAXAREAISLAND__HPP
