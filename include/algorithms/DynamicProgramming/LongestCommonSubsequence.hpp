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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__LONGEST_COMMON_SUBSEQUENCE__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__LONGEST_COMMON_SUBSEQUENCE__HPP
#include <string>

namespace algorithms {

/*! \brief It returns the longest common subsequence among two strings.
 *  \note Complexity -> Time: (N x M)   Space: (N x M)
 *  \note https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
 */
int LongestCommonSubsequence(const std::string& iStr1, const std::string& iStr2);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__LONGEST_COMMON_SUBSEQUENCE__HPP
