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
#ifndef ALGORITHMS__BACKTRACKING__BEAUTIFULARRANGEMENT__HPP
#define ALGORITHMS__BACKTRACKING__BEAUTIFULARRANGEMENT__HPP

namespace algorithms {

/*! \brief Suppose you have N integers from 1 to N. We define a beautiful
 *  arrangement as an array that is constructed by these N numbers successfully
 *  if one of the following is true for the ith position (1 <= i <= N) in this
 *  array:
 *      1. The number at the ith position is divisible by i.
 *      2. i is divisible by the number at the ith position.
 *  Now given N, how many beautiful arrangements can you construct?
 *
 *  \note  Complexity  -->  Time: O(N^N)  Space: O(N)
 *  \note https://leetcode.com/problems/beautiful-arrangement/
 */
int BeautifulArrangement(const int N);

}  // namespace algorithms

#endif  // ALGORITHMS__BACKTRACKING__BEAUTIFULARRANGEMENT__HPP
