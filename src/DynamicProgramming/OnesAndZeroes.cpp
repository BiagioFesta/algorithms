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
#include <algorithm>
#include <algorithms/DynamicProgramming/OnesAndZeroes.hpp>
#include <string>
#include <vector>

namespace algorithms {

int OnesAndZeroes(const std::vector<std::string>& strs, const int m, const int n) {
  const int Mplus = m + 1;
  const int Nplus = n + 1;
  std::vector<int> table(Mplus * Nplus);

  int numZeroes, numOnes;

  for (const auto& str : strs) {  // O(S)
    numZeroes = numOnes = 0;
    for (const char c : str) {
      numZeroes += (c & 0x1) ^ 0x1;
      numOnes += c & 0x1;
    }

    for (int i = m; i >= numZeroes; --i) {  // O(M)
      for (int j = n; j >= numOnes; --j) {  // O(N)
        table[i * Nplus + j] = std::max(table[i * Nplus + j], table[(i - numZeroes) * Nplus + (j - numOnes)] + 1);
      }
    }
  }

  return table.back();
}

}  // namespace algorithms
