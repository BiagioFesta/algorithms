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
#ifndef ALGORITHMS__DYNAMICPROGRAMMING__BUYSELLSTOCKWITHCOOLDOWN__HPP
#define ALGORITHMS__DYNAMICPROGRAMMING__BUYSELLSTOCKWITHCOOLDOWN__HPP
#include <vector>

namespace algorithms {

/*! \brief Say you have an array for which the ith element is the price of a
 *  given stock on day i.
 *  Design an algorithm to find the maximum profit. You may complete as many
 *  transactions as you like (ie, buy one and sell one share of the stock
 *  multiple times) with the following restrictions:
 *      - You may not engage in multiple transactions at the same time (ie, you
 *        must sell the stock before you buy again).
 *      - After you sell your stock, you cannot buy stock on next day. (ie,
 *        cooldown 1 day)
 *
 *  \note  Complexity  -->  Time: O(N)   Space: O(1)
 *  \note
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */
int BuySellStockWithCooldown(const std::vector<int>& prices);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMICPROGRAMMING__BUYSELLSTOCKWITHCOOLDOWN__HPP
