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
#ifndef ALGORITHMS__ARRAY__MAXIMUM_GAP__HPP
#define ALGORITHMS__ARRAY__MAXIMUM_GAP__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array A of integers, it finds the maximum of j - i subjected
 *  to the constraint of A[i] <= A[j].
 *  \return the maximum the solution. -1 if vector is empty.
 *  \note  Complexity ->   Time: O(NlogN)     Space: O(N)
 *  \note https://leetcode.com/problems/maximum-gap/description/
 */
int MaximumGap(const std::vector<int>& iVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__MAXIMUM_GAP__HPP
