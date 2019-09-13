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
#ifndef ALGORITHMS__STRING__MINIMUMWINDOWSUBSTRING__HPP
#define ALGORITHMS__STRING__MINIMUMWINDOWSUBSTRING__HPP
#include <string>

namespace algorithms {

/*! \brief Given a string S and a string T, find the minimum window in S which
 *  will contain all the characters in T in complexity O(n).
 *  \note If there is no such window in S that covers all characters in T,
 *  return the empty string "".
 *  \note If there is such window, you are guaranteed that there will always be
 *  only one unique minimum window in S.
 *
 *  \note  Complexity  -->  Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/problems/minimum-window-substring/
 */
std::string MinimumWindowSubstring(const std::string& s, const std::string& t);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__MINIMUMWINDOWSUBSTRING__HPP
