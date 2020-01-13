/*
  Copyright (C) 2020  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__IS_ONE_BIT_CHARACTER__HPP
#define ALGORITHMS__ARRAY__IS_ONE_BIT_CHARACTER__HPP
#include <vector>

namespace algorithms {

/*! \brief We have two special characters. The first character can be
 *  represented by one bit 0. The second character can be represented by two
 *  bits (10 or 11).
 *  Now given a string represented by several bits.
 *  It returns whether the last character must be a one-bit character or not.
 *  The given string will always end with a zero.
 *  \note  Complexity -> Time: O(N)     Space: O(1)
 *  \note https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
 */
bool IsOneBitCharacter(const std::vector<int>& iBits);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__IS_ONE_BIT_CHARACTER__HPP
