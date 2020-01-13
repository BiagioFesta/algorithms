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
#ifndef ALGORITHMS__ARRAY__INSERTINTERVAL__HPP
#define ALGORITHMS__ARRAY__INSERTINTERVAL__HPP
#include <vector>

namespace algorithms {

/*! \brief Given a set of non-overlapping intervals, insert a new interval into
 *  the intervals (merge if necessary).
 *  You may assume that the intervals were initially sorted according to their
 *  start times.
 *
 *  \note  Complexity  -->  Time: O(N)  Space: O(1)  // Not consider output
 *  \note https://leetcode.com/problems/insert-interval/
 */
std::vector<std::vector<int>> InsertInterval(
    const std::vector<std::vector<int>>& intervals,
    const std::vector<int>& newInterval);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__INSERTINTERVAL__HPP
