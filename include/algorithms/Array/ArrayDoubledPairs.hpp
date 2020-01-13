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
#ifndef ALGORITHMS__ARRAY__ARRAYDOUBLEDPAIRS__HPP
#define ALGORITHMS__ARRAY__ARRAYDOUBLEDPAIRS__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array of integers A with even length, return true if and
 *  only if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i]
 *  for every 0 <= i < len(A) / 2.
 *
 *  \note  Complexity  -->  Time: O(NlogN)   Space: O(N)
 *  \note https://leetcode.com/problems/array-of-doubled-pairs/
 */
bool ArrayDoubledPairs(const std::vector<int>& A);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__ARRAYDOUBLEDPAIRS__HPP
