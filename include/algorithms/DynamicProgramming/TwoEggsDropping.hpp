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
#ifndef ALGORITHMS__DYNAMIC_PROGRAMMING__TWO_EGGS_DROPPING__HPP
#define ALGORITHMS__DYNAMIC_PROGRAMMING__TWO_EGGS_DROPPING__HPP
#include <utility>

namespace algorithms {

/*! \brief The following is a description of the instance of this famous puzzle
 *  involving 2 eggs and a building with `iNumFloors` floors.
 *
 *  Suppose that we wish to know which stories in a `iNumFloots`-story building
 *  are safe to drop eggs from, and which will cause the eggs to break on
 *  landing. What strategy should be used to drop eggs such that total number of
 *  drops in worst case is minimized and we find the required floor.
 *
 *  We may make a few assumptions:
 *      - An egg that survives a fall can be used again.
 *      - A broken egg must be discarded.
 *      - The effect of a fall is the same for all eggs.
 *      - If an egg breaks when dropped, then it would break if dropped from a
 *        higher floor.
 *      - If an egg survives a fall then it would survive a shorter fall.
 *
 *  \note   Complexity ->  Time: O(N^2)      Space: O(N)
 *  \note https://www.geeksforgeeks.org/puzzle-set-35-2-eggs-and-100-floors/
 *
 *  \return a pair. The first is the number of attempts of the worst case of the
 *  optimal strategy required in order to find the floor.
 *  The second is the index (0-based) of the floor where the first attempt
 *  should be performed in the optimal strategy (in case of multiple choise for
 *  the floor to select, then the smallest index will be returned).
 *
 *  \note You can compute the entire sequence of floors to select in the optimal
 *  strategy (considering the worst case) calling this function recursively on a
 *  remaing number of floors having the first attempt.
 *  \note `iNumFloors` has to be a non-negative integer.
 */
std::pair<int, int> TwoEggsDropping(const int iNumFloors);

}  // namespace algorithms

#endif  // ALGORITHMS__DYNAMIC_PROGRAMMING__TWO_EGGS_DROPPING__HPP
