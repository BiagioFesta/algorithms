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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__SUBSTRINGS_SUM__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__SUBSTRINGS_SUM__HPP
#include <string>

namespace algorithms {

/*! \brief Given a number as a string, no leading zeros, it determines the sum
 *  of all integer values of substrings of the string.
 *  \note As the number may become large, return the value modulo (10^9 + 7).
 *  \note  Complexity ->   Time: O(N)    Space: O(1)
 *  \note https://www.hackerrank.com/challenges/sam-and-substrings/problem
 */
int SubstringsSum(const std::string& iStr);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__SUBSTRINGS_SUM__HPP
