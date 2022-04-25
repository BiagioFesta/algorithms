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
#ifndef ALGORITHMS__STRING__BIGGER_IS_GREATER__HPP
#define ALGORITHMS__STRING__BIGGER_IS_GREATER__HPP
#include <string>

namespace algorithms {

/*! \brief Given a word, create a new word by swapping some or all of its
 *  characters. This new word must meet two criteria:
 *          - It must be greater than the original word.
 *          - It must be the smallest word that meets the first condition.
 *  Order for string is given by Lexicographical order.
 *  \return the new string meeting the criteria. If it is not possible, return
 *  no answer.
 *  \note Complexity ->  Time: O(N)   Space: O(N) (Considering the input)
 *  \note https://www.hackerrank.com/challenges/bigger-is-greater/problem
 */
std::string BiggerIsGreater(std::string iString);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__BIGGER_IS_GREATER__HPP
