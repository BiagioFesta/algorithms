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
#ifndef ALGORITHMS__STRING__IS_PERMUTATION__HPP
#define ALGORITHMS__STRING__IS_PERMUTATION__HPP

namespace algorithms {

/*! \brief  Given two strings, write a method to decide if one is a permutation
 *  of the other.
 *  \note Assumptions: case sensitive, white spaces make difference, ASCII
 *  coding.
 *  \note   Complexity -> Time: O(N + M)   Space: O(1)
 */
bool IsPermutation(const char* iStr1, const char* iStr2);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__IS_PERMUTATION__HPP
