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
#ifndef ALGORITHMS__ARRAY__STOCK_MAXIMIZE__HPP
#define ALGORITHMS__ARRAY__STOCK_MAXIMIZE__HPP
#include <vector>

namespace algorithms {

/*! \brief Your algorithms have become so good at predicting the market that you
 *  now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be
 *  for the next number of days.
 *  Each day, you can either buy one share of WOT, sell any number of shares of
 *  WOT that you own, or not make any transaction at all. What is the maximum
 *  profit you can obtain with an optimum trading strategy?
 *  \note   Complexity  ->  Time: O(N)      Space: O(1)
 *  \note https://www.hackerrank.com/challenges/stockmax/problem
 */
int StockMaximize(const std::vector<int>& iPrices);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__STOCK_MAXIMIZE__HPP
