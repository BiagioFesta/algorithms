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
#ifndef ALGORITHMS__ARRAY__NEXTPERMUTATION__HPP
#define ALGORITHMS__ARRAY__NEXTPERMUTATION__HPP
#include <vector>

namespace algorithms {

/*! \brief Implement next permutation, which rearranges numbers into the
 *  lexicographically next greater permutation of numbers.
 *  If such arrangement is not possible, it must rearrange it as the lowest
 *  possible order (ie, sorted in ascending order).
 *  The replacement must be in-place and use only constant extra memory.
 *
 *  \note  Complexity  -->  Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/problems/next-permutation/
 */
void NextPermutation(std::vector<int>* nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__NEXTPERMUTATION__HPP
