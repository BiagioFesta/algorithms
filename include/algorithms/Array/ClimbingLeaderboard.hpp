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
#ifndef ALGORITHMS__ARRAY__CLIMBING_LEADERBOARD__HPP
#define ALGORITHMS__ARRAY__CLIMBING_LEADERBOARD__HPP
#include <vector>

namespace algorithms {

/*! \brief Alice is playing an arcade game and wants to climb to the top of the
 *  leaderboard.
 *  The game uses Dense Ranking (see wikipedia),
 *  We want to determine Alice's rank as she progresses up the leaderboard.
 *  \param [in] iLeaderBoard   The score-leaderboard of the game (other
 *                             players).
 *                                 Size: M
 *  \param [in] iAliceScores   The final score of each game of Alice.
 *                                 Size: N
 *  \return The position in the leaderboard of Alice after each game (the score
 *  obtained by Alice is identified by the param 'iAliceScores').
 *  \note  Complexity ->  Time: O(NlogM)    Space: O(M + N)
 *  \note https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
 */
std::vector<int> climbingLeaderboard(const std::vector<int>& iLeaderBoard,
                                     const std::vector<int>& iAliceScores);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__CLIMBING_LEADERBOARD__HPP
