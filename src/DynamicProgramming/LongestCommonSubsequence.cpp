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
#include <algorithms/DynamicProgramming/LongestCommonSubsequence.hpp>
#include <string>
#include <vector>

namespace algorithms {

int LongestCommonSubsequence(const std::string& iStr1,
                             const std::string& iStr2) {
  const int N = iStr1.size();
  const int M = iStr2.size();

  std::vector<int> solutions(N * M);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (iStr1[i] == iStr2[j]) {
        const int prev =
            (i == 0 || j == 0 ? 0 : solutions[(i - 1) * M + (j - 1)]);
        solutions[i * M + j] = prev + 1;
      } else {
        const int s1 = i != 0 ? solutions[(i - 1) * M + j] : 0;
        const int s2 = j != 0 ? solutions[i * M + (j - 1)] : 0;
        solutions[i * M + j] = std::max(s1, s2);
      }
    }
  }

  return solutions[N * M - 1];
}

}  // namespace algorithms
