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
#ifndef ALGORITHMS__STRING__ORIGINAL_DIGITS__HPP
#define ALGORITHMS__STRING__ORIGINAL_DIGITS__HPP
#include <string>

namespace algorithms {

/*! \brief Given a non-empty string containing an out-of-order English
 *  representation of digits 0-9, it outputs the digits in ascending order.
 *  E.g.
 *          "zerozero"   = "00"
 *          "owoztneoer" = "012"
 *
 *  \note Input must contains only lowercase English letters.
 *  \note Input must be guaranteed to be valid and can be transformed to its
 *  original digits. That means invalid inputs such as "abc" or "zerone" are not
 *  permitted.
 *  \note Complexity ->   Time: O(N)    Space: O(1)
 *  \note http://www.cnblogs.com/grandyang/p/5996239.html
 */
std::string OriginalDigits(const std::string& iString);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__ORIGINAL_DIGITS__HPP
