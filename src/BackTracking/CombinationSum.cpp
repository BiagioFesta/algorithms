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
#include <algorithm>
#include <algorithms/BackTracking/CombinationSum.hpp>
#include <cassert>
#include <set>
#include <stack>
#include <tuple>
#include <type_traits>

namespace {

//! \return all numbers into the vector are > 0
template <typename T>
bool allStrictlyPositive(const std::vector<T>& iVector) {
  static_assert(std::is_arithmetic_v<T>);
  return std::all_of(iVector.cbegin(), iVector.cend(), [](const auto iValue) {
    return iValue > 0;
  });
}

//! \return true if all numbers into the vector are different.
template <typename T>
bool noDuplicates(const std::vector<T>& iVector) {
  static_assert(std::is_arithmetic_v<T>);
  const std::set<T> aSet(iVector.cbegin(), iVector.cend());
  return aSet.size() == iVector.size();
}

}  // anonymous namespace

namespace algorithms {

std::vector<std::vector<int>> CombinationSum(
    const std::vector<int>& iCandidates,
    const int iTarget) {
  using Node_t = std::tuple<int, int, std::vector<int>>;
  using OpenList_t = std::stack<Node_t>;

  assert(iTarget > 0);
  assert(::allStrictlyPositive(iCandidates));
  assert(::noDuplicates(iCandidates));

  const int kSize = iCandidates.size();

  std::vector<std::vector<int>> aSolutions;

  OpenList_t aOpenList;
  aOpenList.emplace(iTarget, 0, std::vector<int>{});

  while (!aOpenList.empty()) {
    auto aCurrentNode = std::move(aOpenList.top());
    aOpenList.pop();

    const int aCurrentTarget = std::get<0>(aCurrentNode);
    const int aCurrentIndex = std::get<1>(aCurrentNode);

    assert(aCurrentTarget >= 0);

    if (aCurrentTarget == 0) {
      aSolutions.push_back(std::move(std::get<2>(aCurrentNode)));
    } else {
      for (int i = aCurrentIndex; i < kSize; ++i) {
        const int aIvalue = iCandidates[i];
        const int aNextTarget = aCurrentTarget - aIvalue;
        if (aNextTarget >= 0) {
          auto aAppendedSet = std::get<2>(aCurrentNode);
          aAppendedSet.push_back(aIvalue);

          aOpenList.emplace(aNextTarget, i, std::move(aAppendedSet));
        }
      }
    }
  }

  return aSolutions;
}

}  // namespace algorithms
