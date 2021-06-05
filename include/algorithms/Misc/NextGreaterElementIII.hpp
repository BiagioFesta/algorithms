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
#ifndef ALGORITHMS__MISC__NEXTGREATERELEMENTIII__HPP
#define ALGORITHMS__MISC__NEXTGREATERELEMENTIII__HPP

namespace algorithms {

/*! \brief Given a positive 32-bit integer n, you need to find the smallest
 *  32-bit integer which has exactly the same digits existing in the integer n
 *  and is greater in value than n. If no such positive 32-bit integer exists,
 *  you need to return -1.
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(N) with N num digits (10 base).
 *  \note https://leetcode.com/problems/next-greater-element-iii/
 */
int NextGreaterElementIII(const int n);

}  // namespace algorithms

#endif  // ALGORITHMS__MISC__NEXTGREATERELEMENTIII__HPP
