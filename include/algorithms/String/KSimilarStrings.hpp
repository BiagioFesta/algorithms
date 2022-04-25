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
#ifndef ALGORITHMS__STRING__KSIMILARSTRINGS__HPP
#define ALGORITHMS__STRING__KSIMILARSTRINGS__HPP
#include <string>

namespace algorithms {

/*! \brief Strings A and B are K-similar (for some non-negative integer K) if we
 *  can swap the positions of two letters in A exactly K times so that the
 *  resulting string equals B.
 *  Given two anagrams A and B, return the smallest K for which A and B are
 *  K-similar.
 *
 *  \note https://leetcode.com/problems/k-similar-strings/
 */
int KSimilarStrings(const std::string& A, const std::string& B);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__KSIMILARSTRINGS__HPP
