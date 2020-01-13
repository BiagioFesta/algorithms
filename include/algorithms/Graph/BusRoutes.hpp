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
#ifndef ALGORITHMS__GRAPH__BUSROUTES__HPP
#define ALGORITHMS__GRAPH__BUSROUTES__HPP
#include <vector>

namespace algorithms {

/*! \brief We have a list of bus routes. Each routes[i] is a bus route that the
 *  i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means
 *  that the first bus (0-th indexed) travels in the sequence
 *  1->5->7->1->5->7->1->... forever.
 *  We start at bus stop S (initially not on a bus), and we want to go to bus
 *  stop T. Travelling by buses only, what is the least number of buses we must
 *  take to reach our destination? Return -1 if it is not possible.
 *
 *  \note https://leetcode.com/problems/bus-routes/
 */
int BusRoutes(const std::vector<std::vector<int>>& routes,
              const int S,
              const int T);

}  // namespace algorithms

#endif  // ALGORITHMS__GRAPH__BUSROUTES__HPP
