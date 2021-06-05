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
#ifndef ALGORITHMS__ARRAY__BEST_SIGHTSEEING_PAIR__HPP
#define ALGORITHMS__ARRAY__BEST_SIGHTSEEING_PAIR__HPP
#include <vector>

namespace algorithms {

/*! \brief Given an array A of positive integers, A[i] represents the value of
 *  the i-th sightseeing spot, and two sightseeing spots i and j have
 *  distance j - i between them.
 *  The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) :
 *  the sum of the values of the sightseeing spots, minus the distance between
 *  them.
 *  Return the maximum score of a pair of sightseeing spots.
 *  \note    2 <= A.length <= 50000
 *  \note    1 <= A[i] <= 1000
 *
 *  \note  Complexity  ->   Time: O(N)   Space: O(1)
 *  \note https://leetcode.com/problems/best-sightseeing-pair/
 */
int BestSightseeingPair(const std::vector<int>& data);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__BEST_SIGHTSEEING_PAIR__HPP
