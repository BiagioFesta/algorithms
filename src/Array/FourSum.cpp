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
#include <algorithm>
#include <algorithms/Array/FourSum.hpp>
#include <vector>

namespace algorithms {

std::vector<std::vector<int>> FourSum(std::vector<int>* iNumbers, const int iTarget) {
  const int size = static_cast<int>(iNumbers->size());
  std::sort(iNumbers->begin(), iNumbers->end());  // O(NlogN)

  std::vector<std::vector<int>> result;

  int p = 0, q, i, j;

  while (p < size - 3) {  // O(N)
    const int pv = (*iNumbers)[p];

    q = p + 1;
    while (q < size - 2) {  // O(N)
      const int qv = (*iNumbers)[q];

      const int tempTarget = iTarget - pv - qv;

      i = q + 1;
      j = size - 1;
      while (i < j) {  // O(N)
        const int iv = ((*iNumbers)[i]);
        const int jv = ((*iNumbers)[j]);
        const int sum = iv + jv;

        if (sum == tempTarget) {
          result.push_back({pv, qv, iv, jv});
          do {
            ++i;
          } while (i < j && (*iNumbers)[i] == iv);
          do {
            --j;
          } while (i < j && (*iNumbers)[j] == jv);
        } else if (sum < tempTarget) {
          ++i;
        } else {
          --j;
        }
      }  // while i,j

      do {
        ++q;
      } while (q < size && (*iNumbers)[q] == qv);
    }  // loop q

    do {
      ++p;
    } while (p < size && (*iNumbers)[p] == pv);
  }  // loop p

  return result;
}

}  // namespace algorithms
