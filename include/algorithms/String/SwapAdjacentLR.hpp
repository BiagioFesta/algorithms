/*
  Copyright (C) 2019  Biagio Festa

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
#ifndef ALGORITHMS__STRING__SWAPADJACENTLR__HPP
#define ALGORITHMS__STRING__SWAPADJACENTLR__HPP
#include <string>

namespace algorithms {

/*! \brief In a string composed of 'L', 'R', and 'X' characters, like
 *  "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with
 *  "LX", or replacing one occurrence of "RX" with "XR". Given the starting
 *  string start and the ending string end, return True if and only if there
 *  exists a sequence of moves to transform one string to the other.
 *  \note len(start) = len(end)
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(1)
 *  \note https://leetcode.com/problems/swap-adjacent-in-lr-string/
 */
bool SwapAdjacentLR(const std::string& start, const std::string& end);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__SWAPADJACENTLR__HPP
