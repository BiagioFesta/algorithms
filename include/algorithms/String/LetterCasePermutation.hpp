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
#ifndef ALGORITHMS__STRING__LETTER_CASE_PERMUTATION__HPP
#define ALGORITHMS__STRING__LETTER_CASE_PERMUTATION__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief Given a string S, we can transform every letter individually to be
 *  lowercase or uppercase to create another string.
 *  \return a list of all possible strings we could create.
 *  \note https://leetcode.com/problems/letter-case-permutation/description/
 */
void LetterCasePermutation(const std::string& iStr,
                           std::vector<std::string>* oPermutations);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__LETTER_CASE_PERMUTATION__HPP
