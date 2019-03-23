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
#ifndef ALGORITHMS__ARRAY__MINIMUM_SIZE_SUBARRAY_SUM__HPP
#define ALGORITHMS__ARRAY__MINIMUM_SIZE_SUBARRAY_SUM__HPP

namespace algorithms {

/*! \brief Given an array of n positive integers and a positive integer s, it
 *  finds the minimal length of a contiguous subarray of which the sum ≥ s. If
 *  there isn't one, it returns 0 instead.
 *  \note https://leetcode.com/problems/minimum-size-subarray-sum/description/
 */
int MinimumSizeSubarraySum(const int* iArray, const int iSize, int s);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__MINIMUM_SIZE_SUBARRAY_SUM__HPP
