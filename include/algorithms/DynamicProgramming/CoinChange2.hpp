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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__COINCHANGE2__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__COINCHANGE2__HPP
#include <vector>

namespace algorithms {

/*! \brief You are given coins of different denominations and a total amount of
 *  money. Write a function to compute the number of combinations that make up
 *  that amount. You may assume that you have infinite number of each kind of
 *  coin.
 *
 *  \note  Complexity  -->  Time: O(N x M)   Space: O(M)
 *                          where N = coins.size(); M = amount
 *  \note https://leetcode.com/problems/coin-change-2/
 */
int CoinChange2(const int amount, const std::vector<int>& coins);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__COINCHANGE2__HPP
