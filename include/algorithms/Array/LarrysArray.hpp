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
#ifndef ALGORITHMS__ARRAY__LARRYS_ARRAY__HPP
#define ALGORITHMS__ARRAY__LARRYS_ARRAY__HPP
#include <vector>

namespace algorithms {

/*! \brief Larry has been given a permutation of a sequence of natural numbers
 *  incrementing from  1 as an array.
 *  He must determine whether the array can be sorted using the following
 *  operation any number of times:
 *    - Choose any  consecutive indices and rotate their elements in such a way
 *      that:
 *         ABC -> BCA -> CAB -> ABC
 *  \return 'true' if the array can be sorted with rotation operation, 'false'
 *  otherise.
 *  \note   Complexity ->  Time: O(N)     Space: O(N)
 *  \note https://www.hackerrank.com/challenges/larrys-array/problem
 */
bool LarrysArray(const std::vector<int>& iVector);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__LARRYS_ARRAY__HPP
