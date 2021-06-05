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
#ifndef ALGORITHMS__ARRAY__SORTCOLORS__HPP
#define ALGORITHMS__ARRAY__SORTCOLORS__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array with n objects colored red, white or blue, sort them
 *  in-place so that objects of the same color are adjacent, with the colors in
 *  the order red, white and blue.
 *  Here, we will use the integers 0, 1, and 2 to represent the color red,
 *  white, and blue respectively.
 *  Note: You are not suppose to use the library's sort function for this
 *  problem.
 *  A rather straight forward solution is a two-pass algorithm using counting
 *  sort.
 *  Could you come up with a one-pass algorithm using only constant space?
 *
 *  \note  Complexity  -->  Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/problems/sort-colors/
 */
void SortColors(std::vector<int>* nums);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__SORTCOLORS__HPP
