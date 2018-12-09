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
#ifndef ALGORITHMS__ARRAY__PAIRS__HPP
#define ALGORITHMS__ARRAY__PAIRS__HPP
#include <vector>

namespace algorithms {

/*! \brief You will be given an array of integers and a target value. It
 *  determines the number of pairs of array elements that have a difference
 *  equal to a target value.
 *  \return The number of pairs.
 *  \Complexity    Time: O(NlogN)    Space: O(N)
 *  \url https://www.hackerrank.com/challenges/pairs/problem
 */
int Pairs(std::vector<int> iNums, int iTarget);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__PAIRS__HPP
