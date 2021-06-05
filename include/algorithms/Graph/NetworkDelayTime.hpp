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
#ifndef ALGORITHMS__GRAPH__NETWORKDELAYTIME__HPP
#define ALGORITHMS__GRAPH__NETWORKDELAYTIME__HPP
#include <vector>

namespace algorithms {

/*! \brief There are N network nodes, labelled 1 to N.
 *  Given times, a list of travel times as directed edges times[i] = (u, v, w),
 *  where u is the source node, v is the target node, and w is the time it takes
 *  for a signal to travel from source to target.
 *  Now, we send a signal from a certain node K. How long will it take for all
 *  nodes to receive the signal? If it is impossible, return -1.
 *
 *  \note https://leetcode.com/problems/network-delay-time/
 */
int NetworkDelayTime(const std::vector<std::vector<int>>& times, const int N, const int K);

}  // namespace algorithms

#endif  // ALGORITHMS__GRAPH__NETWORKDELAYTIME__HPP
