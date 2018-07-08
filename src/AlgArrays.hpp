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
#ifndef ALGORITHMS__ALG_ARRAYS__HPP
#define ALGORITHMS__ALG_ARRAYS__HPP
#include <vector>

namespace algorithms {

/*! \brief It checks if the array could become non-decreasing by modifying at
 *  most 1 element.
 */
bool isAlmostNonDecreasing(const int* iArray, const int iSize);

/*! \brief Given an array of n positive integers and a positive integer s, it
 *  finds the minimal length of a contiguous subarray of which the sum ≥ s. If
 *  there isn't one, it returns 0 instead.
 */
int minSizeSubArraySum(const int* iArray, const int iSize, int s);

/*! \brief Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 *  some elements appear twice and others appear once.
 *  It finds all the elements of [1, n] inclusive that do not appear in this
 *  array.
 */
std::vector<int> findDisappearedNumbers(const std::vector<int>& iVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ALG_ARRAYS__HPP
