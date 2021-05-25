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
#ifndef ALGORITHMS__ARRAY__FIRST_MISSING_POSITIVE__HPP
#define ALGORITHMS__ARRAY__FIRST_MISSING_POSITIVE__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an unsorted integer array, find the smallest missing positive
 *  integer.
 *  \note  Complexity  -> Time: O(N)   Space: O(1) - it exploits the input.
 *  \note https://leetcode.com/problems/first-missing-positive/description/
 */
int FirstMissingPositive(std::vector<int>* iVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FIRST_MISSING_POSITIVE__HPP
