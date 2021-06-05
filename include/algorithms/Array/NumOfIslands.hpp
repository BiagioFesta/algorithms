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
#ifndef ALGORITHMS__ARRAY__NUM_OF_ISLANDS__HPP
#define ALGORITHMS__ARRAY__NUM_OF_ISLANDS__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a 2d grid map of '1's (land) and '0's (water), count the number
 *         of islands. An island is surrounded by water and is formed by
 *         connecting adjacent lands horizontally or vertically. You may assume
 *         all four edges of the grid are all surrounded by water.
 *
 *  \note  https://leetcode.com/problems/number-of-islands/
 */
int NumIslands(const std::vector<std::vector<char>>& iGrid);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__NUM_OF_ISLANDS__HPP
