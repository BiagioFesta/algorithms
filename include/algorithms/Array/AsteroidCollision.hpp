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
#ifndef ALGORITHMS__ARRAY__ASTEROID_COLLISION__HPP
#define ALGORITHMS__ARRAY__ASTEROID_COLLISION__HPP
#include <vector>

namespace algorithms {

/*! \brief We are given an array asteroids of integers representing asteroids in
 *  a row.
 *  For each asteroid, the absolute value represents its size, and the sign
 *  represents its direction (positive meaning right, negative meaning left).
 *  Each asteroid moves at the same speed.
 *  Find out the state of the asteroids after all collisions. If two asteroids
 *  meet, the smaller one will explode. If both are the same size, both will
 *  explode. Two asteroids moving in the same direction will never meet.
 *
 *  \note   Complexity -> Time: O(N^2)   Space: O(N)
 *  \note https://leetcode.com/problems/asteroid-collision/
 */
std::vector<int> AsteroidCollision(const std::vector<int>& asteroids);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__ASTEROID_COLLISION__HPP
