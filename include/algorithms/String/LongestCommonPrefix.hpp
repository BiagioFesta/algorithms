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
#ifndef ALGORITHMS__STRING__LONGESTCOMMONPREFIX__HPP
#define ALGORITHMS__STRING__LONGESTCOMMONPREFIX__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Write a function to find the longest common prefix string amongst an
 *  array of strings.
 *  If there is no common prefix, return an empty string "".
 *
 *  \note  Complexity  -->  Time: O(N x M)  Space: O(M)
 *                   where N := strs.size() and M := min(s.size() | s in strs)
 *  \note https://leetcode.com/problems/longest-common-prefix/
 */
std::string LongestCommonPrefix(const std::vector<std::string>& strs);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__LONGESTCOMMONPREFIX__HPP
