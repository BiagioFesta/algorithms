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
#ifndef ALGORITHMS__STRING__URLIFY__HPP
#define ALGORITHMS__STRING__URLIFY__HPP

namespace algorithms {

/*! \brief It replaces all spaces in a string with '%20'.
 *  \note It assumes that the string has sufficient space at the end to hold the
 *  additional characters, and that you are given the "true" length of the
 *  string.
 *  \note  Complexity ->  Time: O(N^2)    Space: O(1)
 */
void URLify(char* iStr, int iLenString);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__URLIFY__HPP
