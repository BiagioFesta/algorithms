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
#ifndef ALGORITHMS__STRING__DETECT_CAPITAL_USE__HPP
#define ALGORITHMS__STRING__DETECT_CAPITAL_USE__HPP
#include <string>

namespace algorithms {

/*! \brief Given a word, you need to judge whether the usage of capitals in it
 *  is right or not.
 *  We define the usage of capitals in a word to be right when one of the
 *  following cases holds:
 *    1) All letters in this word are capitals, like "USA".
 *    2) All letters in this word are not capitals, like "leetcode".
 *    3) Only the first letter in this word is capital if it has more than one
 *       letter, like "Google".
 *  Otherwise, we define that this word doesn't use capitals in a right way.
 *  \return Whether the string use capital in right way or not.
 *  \note The string must not be empty.
 *  \note  Complexity ->   Time: O(N)    Space: O(1)
 */
bool DetectCapitalUse(const std::string& iString);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__DETECT_CAPITAL_USE__HPP
