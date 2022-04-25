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
#ifndef ALGORITHMS__GRAPH__SHORTESTPATHBINARYMATRIX__HPP
#define ALGORITHMS__GRAPH__SHORTESTPATHBINARYMATRIX__HPP
#include <vector>

namespace algorithms {

/*! \brief In an N by N square grid, each cell is either empty (0) or blocked
 *  (1).
 *  A clear path from top-left to bottom-right has length k if and only if it is
 *  composed of cells C_1, C_2, ..., C_k such that:
 *    - Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they
 *      are different and share an edge or corner);
 *    - C_1 is at location (0, 0) (ie. has value grid[0][0]);
 *    - C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1]);
 *    - If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] ==
 *      0).
 *  Return the length of the shortest such clear path from top-left to
 *  bottom-right.  If such a path does not exist, return -1.
 *
 *  \note  Complexity  -->  Time: O(N^2)   Space: O(N^2)  where N := grid.size()
 *  \note https://leetcode.com/problems/shortest-path-in-binary-matrix/
 */
int ShortestPathBinaryMatrix(const std::vector<std::vector<int>>& grid);

}  // namespace algorithms

#endif  // ALGORITHMS__GRAPH__SHORTESTPATHBINARYMATRIX__HPP
