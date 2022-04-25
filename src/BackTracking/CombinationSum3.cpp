/*
  Copyright (C) 2022  Biagio Festa

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
#include <algorithms/BackTracking/CombinationSum3.hpp>
#include <cassert>
#include <functional>
#include <vector>

namespace algorithms {

std::vector<std::vector<int>> CombinationSum3(const int K, const int N) {
  assert(K > 0);
  assert(N > 0);

  std::vector<std::vector<int>> aSolutions;

  const std::function<void(int, std::vector<int>*)> aHelperFn = [&](int iTarget, std::vector<int>* ioSeq) {
    const auto aSizeSeq = ioSeq->size();

    if (iTarget >= 0) {
      if (iTarget == 0 && aSizeSeq == static_cast<size_t>(K)) {
        aSolutions.emplace_back(*ioSeq);
      } else {
        const int aLastNum = ioSeq->empty() ? 0 : ioSeq->back();
        for (int i = aLastNum + 1; i <= 9; ++i) {
          ioSeq->push_back(i);
          aHelperFn(iTarget - i, ioSeq);
          ioSeq->pop_back();
        }
      }
    }
  };

  std::vector<int> aSequence;
  aSequence.reserve(K + 1);

  aHelperFn(N, &aSequence);

  return aSolutions;
}

}  // namespace algorithms
