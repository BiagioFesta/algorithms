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
#ifndef ALGORITHMS__STRING__FIND_AND_REPLACE_PATTERN__HPP
#define ALGORITHMS__STRING__FIND_AND_REPLACE_PATTERN__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief You have a list of words and a pattern, and you want to know which
 *  words in words matches the pattern. A word matches the pattern if there
 *  exists a permutation of letters p so that after replacing every letter x in
 *  the pattern with p(x), we get the desired word.
 *  \return a list of the words in words that match the given pattern.
 *  \note Complexity -> Time: O(NM) Space: (1)  N size of iWords; M size Pattern
 */
std::vector<std::string> FindAndReplacePattern(const std::vector<std::string>& iWords, const std::string& iPattern);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__FIND_AND_REPLACE_PATTERN__HPP
