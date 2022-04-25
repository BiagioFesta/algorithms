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
#ifndef ALGORITHMS__MISC__SUMSQUARENUMBERS__HPP
#define ALGORITHMS__MISC__SUMSQUARENUMBERS__HPP

namespace algorithms {

/*! \brief Given a non-negative integer c, your task is to decide whether
 *  there're two integers a and b such that a^2 + b^2 = c.
 *
 *  \note  Complexity  -->  Time: O(c)  Space: O(1)
 *  \note https://leetcode.com/problems/sum-of-square-numbers/
 */
bool SumSquareNumbers(const int c);

}  // namespace algorithms

#endif  // ALGORITHMS__MISC__SUMSQUARENUMBERS__HPP
