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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__TALLESTBILLBOARD__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__TALLESTBILLBOARD__HPP
#include <vector>

namespace algorithms {

/*! \brief You are installing a billboard and want it to have the largest
 *  eight. The billboard will have two steel supports, one on each side. Each
 *  steel support must be an equal height.
 *  You have a collection of rods which can be welded together. For example, if
 *  you have rods of lengths 1, 2, and 3, you can weld them together to make a
 *  support of length 6.
 *  Return the largest possible height of your billboard installation. If you
 *  cannot support the billboard, return 0.
 *
 *  \note  Complexity  --> Time: O(N x S); Space: O(S)  S = sum all rods' values
 *  \note https://leetcode.com/problems/tallest-billboard/
 */
int TallestBillboard(const std::vector<int>& rods);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__TALLESTBILLBOARD__HPP
