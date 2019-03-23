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
#ifndef ALGORITHMS__STRING__MIN_ADD_PARENTHESES__HPP
#define ALGORITHMS__STRING__MIN_ADD_PARENTHESES__HPP
#include <string>

namespace algorithms {

/*! \brief Given a string S of '(' and ')' parentheses, we add the minimum
 *  number of parentheses ( '(' or ')', and in any positions ) so that the
 *  resulting parentheses string is valid.
 *
 *  Formally, a parentheses string is valid if and only if:
 *      - It is the empty string, or
 *      - It can be written as AB (A concatenated with B), where A and B are
 *        valid strings, or
 *      - It can be written as (A), where A is a valid string.
 *
 *  Given a parentheses string, return the minimum number of parentheses we must
 *  add to make the resulting string valid.
 *
 *  \note    Complexity  ->  Time: O(N)   Space: O(N)
 *  \note https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 */
int MinAddParentheses(const std::string& iString);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__MIN_ADD_PARENTHESES__HPP
