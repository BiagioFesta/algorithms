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
#ifndef ALGORITHMS__ARRAY__CAPACITYSHIPPACKAGESWITHINDAYS__HPP
#define ALGORITHMS__ARRAY__CAPACITYSHIPPACKAGESWITHINDAYS__HPP
#include <vector>

namespace algorithms {

/*! \brief A conveyor belt has packages that must be shipped from one port to
 *  another within D days.
 *  The i-th package on the conveyor belt has a weight of weights[i].  Each day,
 *  we load the ship with packages on the conveyor belt (in the order given by
 *  weights). We may not load more weight than the maximum weight capacity of
 *  the ship.
 *  Return the least weight capacity of the ship that will result in all the
 *  packages on the conveyor belt being shipped within D days.
 *
 *  \note  Complexity  -->  Time: O(N logS)  Space: O(1)  where S is sum weights
 *  \note https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 */
int CapacityShipPackagesWithinDays(const std::vector<int>& weights, const int D);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__CAPACITYSHIPPACKAGESWITHINDAYS__HPP
