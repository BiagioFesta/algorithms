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
#ifndef ALGORITHMS__STRING__STRING_COMPRESSION__HPP
#define ALGORITHMS__STRING__STRING_COMPRESSION__HPP

namespace algorithms {

/*! \brief It performs basic string compression using the counts
 *  of repeated characters. For example, the string aabcccccaaa would become
 *  2ab5c3a.
 *  \note If the "compressed" string does not fit the buffer in output, the
 *  method should return false and output will be trash data.
 *  \note It assumes the string contains only [A-Za-z] (no digits), otherwise
 *  the result is ambiguos.
 */
bool StringCompression(const char* iStr, char* oBuffer, const int iSizeBuffer);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__STRING_COMPRESSION__HPP
