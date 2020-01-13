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
#ifndef ALGORITHMS__STRING__ENCRYPTION_STR__HPP
#define ALGORITHMS__STRING__ENCRYPTION_STR__HPP
#include <string>

namespace algorithms {

/*! \brief An English text needs to be encrypted using the following encryption
 *  scheme.
 *  First, the spaces are removed from the text. Let 'L'  be the length of this
 *  text.
 *  Then, characters are written into a grid, whose rows and columns have the
 *  following constraints:
 *     floor(L) <= #rows <= #cols <= ceil(L)
 *  Ensure #rows * #cols >= L
 *  In case of multiple grids with the above conditions, pick the minimum area.
 *  The encoded message is obtained by displaying the characters in a column,
 *  inserting a space, and then displaying the next column and inserting a
 *  space, and so on.
 *
 *  Eg.   chillout
 *    c h i
 *    l l o
 *    u t
 *           ---> clu hlt io
 *
 *  \note Complexity ->  Time:  O(N)     Space: O(N)
 */
std::string EncryptionStr(const std::string& iString);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__ENCRYPTION_STR__HPP
