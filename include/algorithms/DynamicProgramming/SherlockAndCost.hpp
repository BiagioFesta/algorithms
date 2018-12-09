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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__SHERLOCK_AND_COST__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__SHERLOCK_AND_COST__HPP
#include <vector>

namespace algorithms {

/*! \brief The algorithm has to create an array A such that:
 *              1 <= A[i] <= iUpperBounds[i]
 *  For each possible array A, the algorithm will return the "best A".
 *  The "best A" is that the sum of the absolute difference of consecutive pairs
 *  is maximized.
 *   I.e.     S = sum_i |A[i] - A[i - 1]|
 *  \return S
 *  \note Complexity -> Time: O(N)    Space: O(1)
 */
int SherlockAndCost(const std::vector<int>& iUpperBounds);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__SHERLOCK_AND_COST__HPP
