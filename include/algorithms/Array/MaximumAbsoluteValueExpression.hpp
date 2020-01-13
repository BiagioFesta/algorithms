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
#ifndef ALGORITHMS__ARRAY__MAXIMUMABSOLUTEVALUEEXPRESSION__HPP
#define ALGORITHMS__ARRAY__MAXIMUMABSOLUTEVALUEEXPRESSION__HPP
#include <vector>

namespace algorithms {

/*! \brief Given two arrays of integers with equal lengths, return the maximum
 *  value of:
 *        |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
 *  where the maximum is taken over all 0 <= i, j < arr1.length.
 *
 *  \note Complexity  -->  Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/problems/maximum-of-absolute-value-expression/
 */
int MaximumAbsoluteValueExpression(const std::vector<int>& arr1,
                                   const std::vector<int>& arr2);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__MAXIMUMABSOLUTEVALUEEXPRESSION__HPP
