/*
  Copyright (C) 2020  Biagio Festa

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
#ifndef ALGORITHMS__ARRAY__DAILYTEMPERATURES__HPP
#define ALGORITHMS__ARRAY__DAILYTEMPERATURES__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a list of daily temperatures T, return a list such that, for
 *  each day in the input, tells you how many days you would have to wait until
 *  a warmer temperature. If there is no future day for which this is possible,
 *  put 0 instead.
 *  For example:
 *     given the list of temperatures
 *              T = [73, 74, 75, 71, 69, 72, 76, 73],
 *     your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *  The length of temperatures will be in the range [1, 30000].
 *  Each temperature will be an integer in the range [30, 100].
 *
 *  \note  Complexity  -->  Time: O(N^2)  Space: O(N)
 *  \note https://leetcode.com/problems/daily-temperatures/
 */
std::vector<int> DailyTemperatures(const std::vector<int>& temps);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__DAILYTEMPERATURES__HPP
