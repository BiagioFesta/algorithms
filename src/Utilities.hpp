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
#ifndef ALGORITHMS__UTILITIES__HPP
#define ALGORITHMS__UTILITIES__HPP
#include <algorithm>
#include <unordered_map>
#include <vector>

namespace algorithms {

/*! \brief It checks whether two container store the same values in the same
 *  order.
 *  \Complexity   Time O(N) (because size should be same)
 */
template <typename ContainerT, typename ContainerU>
bool checkStrictEqualityContainers(const ContainerT& c1, const ContainerU& c2) {
  if (c1.size() != c2.size()) return false;

  auto c1Iterator = c1.cbegin();
  auto c2Iterator = c2.cbegin();

  while (c1Iterator != c1.cend() && *c1Iterator == *c2Iterator) {
    ++c1Iterator;
    ++c2Iterator;
  }

  return c1Iterator == c1.cend();
}

/*! \brief It checks whether two containers store the same values.
 *  \Complexity  Time O(N)    (using an hash table)
 */
template <typename ContainerT, typename ContainerU>
bool haveSameValues(const ContainerT& c1, const ContainerU& c2) {
  using ValueT = typename ContainerT::value_type;

  if (c1.size() != c2.size()) return false;

  std::unordered_map<ValueT, int> c1Occurrences;

  for (const auto& t : c1) {
    ++c1Occurrences[t];
  }

  for (const auto& u : c2) {
    auto& u_occurrences = c1Occurrences[u];
    if (u_occurrences == 0) return false;
    --u_occurrences;
  }

  return true;
}

/*! \brief It checks whether two containers store the same values.
 *  \Complexity  Time O(NM)    (without using hash table)
 */
template <typename ContainerT, typename ContainerU>
bool haveSameValuesNoHash(const ContainerT& c1, const ContainerU& c2) {
  std::vector<bool> aVisitedIndex(c2.size());

  const int kSize1 = c1.size();
  const int kSize2 = c2.size();

  if (kSize1 != kSize2) return false;

  for (const auto& t : c1) {
    const auto aFinder = std::find(std::cbegin(c2), std::cend(c2), t);
    const auto aIndex = std::distance(std::cbegin(c2), aFinder);

    if (aIndex >= kSize2 || aVisitedIndex[aIndex] == true) {
      return false;
    }

    aVisitedIndex[aIndex] = true;
  }

  return true;
}

}  // namespace algorithms

#endif  // ALGORITHMS__UTILITIES__HPP
