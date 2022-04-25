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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__COINCHANGE__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__COINCHANGE__HPP
#include <vector>

namespace algorithms {

/*! \brief You are given coins of different denominations and a total amount of
 *  money amount. Write a function to compute the fewest number of coins that
 *  you need to make up that amount. If that amount of money cannot be made up
 *  by any combination of the coins, return -1.
 *
 *  \note  Complexity --> Time: O(N * K) Space: O(K)  N := no coins K := amount
 *  \note https://leetcode.com/problems/coin-change/
 */
int CoinChange(const std::vector<int>& coins, const int amount);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__COINCHANGE__HPP
