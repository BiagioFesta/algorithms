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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__INTEGERB_REAK__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__INTEGERB_REAK__HPP

namespace algorithms {

/*! \brief Given a positive integer n, break it into the sum of at least two
 *  positive integers and maximize the product of those integers. Return the
 *  maximum product you can get.
 *  \note You may assume that n is not less than 2 and not larger than 58.
 *
 *  \note  Complexity ->  Time: O(N^2)    Space: O(N)
 *  \note https://leetcode.com/problems/integer-break/
 */
int IntegerBreak(const int n);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__INTEGERB_REAK__HPP
