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
#include <algorithms/Array/SieveOfEratosthenes.hpp>
#include <cassert>
#include <vector>

namespace algorithms {

std::vector<int> SieveOfEratosthenes(const int iN) {
  assert(iN > 0);
  std::vector<int> aPrimes;

  std::vector<bool> aVector(iN + 1);
  for (int p = 2; p <= iN; ++p) {
    if (aVector[p] == false) {
      aPrimes.push_back(p);
      for (int q = 2 * p; q <= iN; q += p) {
        aVector[q] = true;
      }
    }
  }

  return aPrimes;
}

}  // namespace algorithms
