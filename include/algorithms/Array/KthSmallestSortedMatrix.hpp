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
#ifndef ALGORITHMS__ARRAY__KTHSMALLESTSORTEDMATRIX__HPP
#define ALGORITHMS__ARRAY__KTHSMALLESTSORTEDMATRIX__HPP
#include <vector>

namespace algorithms {

/*1 \brief Given a n x n matrix where each of the rows and columns are sorted in
 *  ascending order, find the kth smallest element in the matrix.
 *  Note that it is the kth smallest element in the sorted order, not the kth
 *  distinct element.
 *
 *  \note  Complexity  -->  Time: O(NlogN)  Space: O(N)
 *  \note https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 */
int KthSmallestSortedMatrix(const std::vector<std::vector<int>>& matrix, const int k);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__KTHSMALLESTSORTEDMATRIX__HPP
