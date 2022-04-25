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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__ONESANDZEROES__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__ONESANDZEROES__HPP
#include <string>
#include <vector>

namespace algorithms {

/*! \brief In the computer world, use restricted resource you have to generate
 *  maximum benefit is what we always want to pursue.
 *  For now, suppose you are a dominator of m '0s' and n '1s' respectively. On
 *  the other hand, there is an array with strings consisting of only 0s and 1s.
 *  Now your task is to find the maximum number of strings that you can form
 *  with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 *
 *  \note  Complexity  -->  Time: O(S x M x N)   Space: O(M x N)
 *  \note https://leetcode.com/problems/ones-and-zeroes/
 */
int OnesAndZeroes(const std::vector<std::string>& strs, const int m, const int n);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__ONESANDZEROES__HPP
