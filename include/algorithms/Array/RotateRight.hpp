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
#ifndef ALGORITHMS__ARRAY__ROTATE_RIGHT__HPP
#define ALGORITHMS__ARRAY__ROTATE_RIGHT__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array, rotate the array to the right by k steps.
 *  \url https://leetcode.com/problems/rotate-array/
 *  \Complexity        Time: O(N)     Space: O(1)
 *  \note This implementation of the algorithm is less restrictive than the
 *  original assignment. The number of steps to rotate can even be negative
 *  allowing left rotations. Moreover, this solution does not use additional
 *  space.
 */
void RotateRight(std::vector<int>* ioVector, int k);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__ROTATE_RIGHT__HPP
