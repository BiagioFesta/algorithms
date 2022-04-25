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
#ifndef ALGORITHMS__ARRAY__MINIMUMREMOVEVALIDPARENTHESES__HPP
#define ALGORITHMS__ARRAY__MINIMUMREMOVEVALIDPARENTHESES__HPP
#include <string>

namespace algorithms {

/*! \brief Given a string s of '(' , ')' and lowercase English characters.
 *  Your task is to remove the minimum number of parentheses ( '(' or ')', in
 *  any positions ) so that the resulting parentheses string is valid and return
 *  any valid string.
 *  Formally, a parentheses string is valid if and only if:
 *    - It is the empty string, contains only lowercase characters, or
 *    - It can be written as AB (A concatenated with B), where A and B are valid
 *      strings, or
 *    - It can be written as (A), where A is a valid string.
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(N)
 *  \note
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 */
std::string MinimumRemoveValidParentheses(const std::string& str);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__MINIMUMREMOVEVALIDPARENTHESES__HPP
