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
#include <algorithm>
#include <algorithms/String/SteadyGene.hpp>
#include <cassert>
#include <map>
#include <string>

namespace algorithms {

int SteadyGene(const std::string& gene) {
  std::map<char, int> occ;
  const int size = gene.size();
  assert(size % 4 == 0);
  const int maxOcc = size / 4;

  int lb = -1;
  for (int i = 0; i < size && lb < 0; ++i) {
    const char c = gene[i];
    int& frequency = occ[c];
    if (frequency >= maxOcc) {
      lb = i;
    } else {
      ++frequency;
    }
  }

  if (lb == -1) return 0;

  int ub = -1;
  for (int j = size - 1; j >= 0 && ub < 0; --j) {
    const char c = gene[j];
    int& frequency = occ[c];
    if (frequency >= maxOcc) {
      ub = j;
    } else {
      ++frequency;
    }
  }

  int min = ub - lb + 1;
  for (int i = lb - 1; i >= 0; --i) {
    const char c = gene[i];
    int& frequency = occ[c];
    --frequency;

    while (occ[gene[ub]] < maxOcc) {
      ++occ[gene[ub]];
      --ub;
    }

    min = std::min(min, ub - i + 1);
  }

  return min;
}

}  // namespace algorithms
