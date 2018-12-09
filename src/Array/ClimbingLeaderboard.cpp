/*
  Copyright (C) 2018  Biagio Festa

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
#include <algorithms/Array/ClimbingLeaderboard.hpp>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

namespace algorithms {

std::vector<int> climbingLeaderboard(const std::vector<int>& iLeaderBoard,
                                     const std::vector<int>& iAliceScores) {
  const std::set<int> aLeaderBoardTree(iLeaderBoard.cbegin(),
                                       iLeaderBoard.cend());
  const std::vector<int> aLeaderBoardPurged(aLeaderBoardTree.cbegin(),
                                            aLeaderBoardTree.cend());
  const int aPosTotal = aLeaderBoardPurged.size();

  std::vector<int> aPositions;
  aPositions.reserve(iAliceScores.size());

  for (const int aGameScore : iAliceScores) {
    const auto aBoundIt = std::upper_bound(
        aLeaderBoardPurged.cbegin(), aLeaderBoardPurged.cend(), aGameScore);
    const auto aPos =
        aPosTotal + 1 - std::distance(aLeaderBoardPurged.cbegin(), aBoundIt);
    aPositions.push_back(aPos);
  }
  return aPositions;
}

}  // namespace algorithms
