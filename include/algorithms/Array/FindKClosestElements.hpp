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
#ifndef ALGORITHMS__ARRAY__FINDKCLOSESTELEMENTS__HPP
#define ALGORITHMS__ARRAY__FINDKCLOSESTELEMENTS__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a sorted array, two integers k and x, find the k closest
 *  elements to x in the array. The result should also be sorted in ascending
 *  order. If there is a tie, the smaller elements are always preferred.
 *
 *  \note  Complexity  -->  Time: O(K + logN)   Space: O(1)  without output
 *  \note https://leetcode.com/problems/find-k-closest-elements/
 */
std::vector<int> FindKClosestElements(const std::vector<int>& arr, const int k, const int x);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__FINDKCLOSESTELEMENTS__HPP
