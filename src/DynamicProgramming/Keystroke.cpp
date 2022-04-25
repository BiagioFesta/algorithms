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
#include <algorithms/DynamicProgramming/Keystroke.hpp>
#include <vector>

namespace algorithms {

int Keystroke(const int N) {
  const int kNplusOne = N + 1;
  std::vector<int> aSolutions(kNplusOne);

  for (int i = 1; i < kNplusOne; ++i) {
    aSolutions[i] = aSolutions[i - 1] + 1;
    for (int j = 1; j < i - 2; ++j) {
      aSolutions[i] = std::max(aSolutions[i], (i - j - 1) * aSolutions[j]);
    }
  }

  return aSolutions[N];
}

}  // namespace algorithms
