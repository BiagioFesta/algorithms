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
#ifndef ALGORITHMS__STRING__FREQUENCYSORT__HPP
#define ALGORITHMS__STRING__FREQUENCYSORT__HPP
#include <string>

namespace algorithms {

/*! \brief Given a string, sort it in decreasing order based on the frequency of
 *  characters.
 *
 *  \note Complexity  ->  Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/problems/sort-characters-by-frequency/
 */
std::string FrequencySort(const std::string& s);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__FREQUENCYSORT__HPP
