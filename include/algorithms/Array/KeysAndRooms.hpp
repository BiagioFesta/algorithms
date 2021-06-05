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
#ifndef ALGORITHMS__ARRAY__KEYS_AND_ROOMS__HPP
#define ALGORITHMS__ARRAY__KEYS_AND_ROOMS__HPP
#include <vector>

namespace algorithms {

/*! \brief There are N rooms and you start in room 0.
 *  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have
 *  some keys to access the next room.
 *  Formally, each room i has a list of keys rooms[i], and each key rooms[i][j]
 *  is an integer in [0, 1, ..., N-1] where N = rooms.length.
 *  A key rooms[i][j] = v opens the room with number v.
 *  Initially, all the rooms start locked (except for room 0).
 *  You can walk back and forth between rooms freely.
 *  \return true if and only if you can enter every room.
 *
 *  \note    Complexity ->  Time: O(N)    Space: O(N)
 *  \note https://leetcode.com/problems/keys-and-rooms/
 */
bool KeysAndRooms(const std::vector<std::vector<int>>& iRooms);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__KEYS_AND_ROOMS__HPP
