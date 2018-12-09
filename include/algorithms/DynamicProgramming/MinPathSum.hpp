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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__MIN_PATH_SUM__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__MIN_PATH_SUM__HPP

namespace algorithms {

/*! \brief Given a M x N grid filled with non-negative numbers, it finds a path
 *  from top left to bottom right which minimizes the sum of all numbers along
 *  its path.
 *  \note It assumes you can only move either down or right at any point in
 *  time.
 *  \note M and N must be positive (> 0).
 *  \note Complexity -> Time: (M x N)    Space: (M x N)
 */
int MinPathSum(const int* const iMatrix, const int M, const int N);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__MIN_PATH_SUM__HPP
