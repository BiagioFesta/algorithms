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
#ifndef ALGORITHMS__BACKTRACKING__MAXCONCATUNIQUECHARS__HPP
#define ALGORITHMS__BACKTRACKING__MAXCONCATUNIQUECHARS__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given an array of strings arr. String s is a concatenation of a
 *  sub-sequence of arr which have unique characters.
 *  Return the maximum possible length of s.
 *
 *  \note  Complexity  -->  Time: O(2^N)   Space: O(N)
 *  \note
 * https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
 */
int MaxConcatUniqueChars(const std::vector<std::string>& arr);

}  // namespace algorithms

#endif  // ALGORITHMS__BACKTRACKING__MAXCONCATUNIQUECHARS__HPP
