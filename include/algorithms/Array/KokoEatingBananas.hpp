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
#ifndef ALGORITHMS__ARRAY__KOKO_EATING_BANANAS__HPP
#define ALGORITHMS__ARRAY__KOKO_EATING_BANANAS__HPP
#include <vector>

namespace algorithms {

/*! \brief Koko loves to eat bananas.  There are N piles of bananas, the i-th
 *  pile has piles[i] bananas.
 *  The guards have gone and will come back in H hours. Koko can decide her
 *  bananas-per-hour eating speed of K.  Each hour, she chooses some pile of
 *  bananas, and eats K bananas from that pile.
 *  If the pile has less than K bananas, she eats all of them instead, and won't
 *  eat any more bananas during this hour.
 *  Koko likes to eat slowly, but still wants to finish eating all the bananas
 *  before the guards come back. Return the minimum integer K such that she can
 *  eat all the bananas within H hours.
 *
 *  \note The input parameters should always lead to a feasible solution.
 *  In other words, ensure that: H >= piles.size()
 *
 *  \note   Complexity -> Time: O(NlogN)    Space: O(1)
 *  \note https://leetcode.com/problems/koko-eating-bananas/
 */
int KokoEatingBananas(const std::vector<int>& piles, const int H);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__KOKO_EATING_BANANAS__HPP
