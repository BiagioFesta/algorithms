/*
  Copyright (C) 2018  Biagio Festa

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
#ifndef ALGORITHMS__STRING__FIND_THE_DIFFERENCE__HPP
#define ALGORITHMS__STRING__FIND_THE_DIFFERENCE__HPP
#include <string>

namespace algorithms {

/*! \brief Given two strings 's' and 't' which consist of only lowercase
 *  letters.
 *  String 't' is generated by random shuffling string s and then add one
 *  more letter at a random position.
 *  It finds the letter that was added in t.
 *  \return the added letter, otherwise '\0'.
 *  \note   Complexity -> Time: O(N + M)    Space: O(1)
 *  \note https://leetcode.com/problems/find-the-difference/
 */
char FindTheDifference(const std::string& iStringS,
                       const std::string& iStringT);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__FIND_THE_DIFFERENCE__HPP
