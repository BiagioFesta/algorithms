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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__MAX_PROFIT__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__MAX_PROFIT__HPP
#include <vector>

namespace algorithms {

/*! \brief Say you have an array for which the i-th element is the price of a
 *  given stock on day i.
 *  Design an algorithm to find the maximum profit. You may complete at most two
 *  transactions.
 *  \note You may not engage in multiple transactions at the same time (i.e.,
 *  you must sell the stock before you buy again).
 *  \note
 *  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *  \note  Complexity ->  Time: O(N)      Space: O(N)
 */
int MaxProfit(const std::vector<int>& iPrices);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__MAX_PROFIT__HPP
