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
#ifndef ALGORITHMS__STRING__FIND_LONGEST_WORD__HPP
#define ALGORITHMS__STRING__FIND_LONGEST_WORD__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a string and a string dictionary, it finds the longest string
 *  in the dictionary that can be formed by deleting some characters of the
 *  given string. If there are more than one possible results, it returns the
 *  longest word with the smallest lexicographical order.
 *  \return the index of longest string in the dictionary. It returns -1 if
 *  there is no possible result.
 *  \note Complexity ->   Time: O(N^2 + NM)      Space: O(1)
 *  \note
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
 */
int FindLongestWord(const std::string& iString,
                    const std::vector<std::string>& iStringDict);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__FIND_LONGEST_WORD__HPP
