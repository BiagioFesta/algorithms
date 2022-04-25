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
#ifndef ALGORITHMS__STRING__DECODE_STRING__HPP
#define ALGORITHMS__STRING__DECODE_STRING__HPP
#include <string>

namespace algorithms {

/*! \brief  Given an encoded string, return it's decoded string.
 *  The encoding rule is: k[encoded_string], where the encoded_string inside the
 *  square brackets is being repeated exactly k times.
 *  Note that k is guaranteed to be a positive integer.
 *  You may assume that the input string is always valid; No extra white spaces,
 *  square brackets are well-formed, etc.
 *  Furthermore, you may assume that the original data does not contain any
 *  digits and that digits are only for those repeat numbers, k. For example,
 *  there won't be input like 3a or 2[4].
 *
 *  \note  Complexity:  Time: O(N)    Space: O(N)
 *  \note https://leetcode.com/problems/decode-string/
 */
std::string DecodeString(const std::string &encStr);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__DECODE_STRING__HPP
