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
#ifndef ALGORITHMS__STRING__KMPSTRSTR__HPP
#define ALGORITHMS__STRING__KMPSTRSTR__HPP
#include <string>

namespace algorithms {

/*! \brief Return the index of the first occurrence of 'pattern' in 'str'.
 *  Returns -1 when the occurrence is not found.
 *
 *  \note  Complexity  -->  Time: O(N + M)   Space: O(M)
 *  \note
 * https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
 */
int KMPstrstr(const std::string& str, const std::string& pattern);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__KMPSTRSTR__HPP
