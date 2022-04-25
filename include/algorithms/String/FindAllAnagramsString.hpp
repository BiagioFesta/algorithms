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
#ifndef ALGORITHMS__STRING__FINDALLANAGRAMSSTRING__HPP
#define ALGORITHMS__STRING__FINDALLANAGRAMSSTRING__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a string s and a non-empty string p, find all the start indices
 *  of p's anagrams in s.
 *  Strings consists of lowercase English letters only and the length of both
 *  strings s and p will not be larger than 20,100.
 *  The order of output does not matter.
 *
 *  \note  Complexity  -->  Time: O(S + P)  Space: O(1)
 *  \note https://leetcode.com/problems/find-all-anagrams-in-a-string/
 */
std::vector<int> FindAllAnagramsString(const std::string& s, const std::string& p);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__FINDALLANAGRAMSSTRING__HPP
