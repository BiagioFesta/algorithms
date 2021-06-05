/*
  Copyright (C) 2021  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__CONTIGUOUS_ARRAY__HPP
#define ALGORITHMS__ARRAY__CONTIGUOUS_ARRAY__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a binary array, it finds the maximum length of a contiguous
 *  subarray with equal number of 0 and 1.
 *  \note It returns 0 in case no solution.
 *  \note  Complexity ->     Time: O(N)    Space: O(N)
 *  \note https://leetcode.com/problems/contiguous-array/description/
 */
int ContiguousArray(const std::vector<int>& iBits);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__CONTIGUOUS_ARRAY__HPP
