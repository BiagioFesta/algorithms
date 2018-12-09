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
#ifndef ALGORITHMS__STRING__LEN_LAST_WORD__HPP
#define ALGORITHMS__STRING__LEN_LAST_WORD__HPP

namespace algorithms {

/*! \brief Given a string s consists of upper/lower-case alphabets and empty
 * space characters ' ', it returns the length of last word in the string.
 * \note If the last word does not exist, it returns 0.
 */
int LenLastWord(const char* iStr);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__LEN_LAST_WORD__HPP
