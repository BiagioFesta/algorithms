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
#include <algorithms/Array/EuclideanAlgorithmGCD.hpp>

namespace algorithms {

int EuclideanAlgorithmGCD(int iNumberA, int iNumberB) {
  if (iNumberA == 0) return iNumberB;
  if (iNumberB == 0) return iNumberA;

  while (iNumberA != iNumberB) {
    if (iNumberA < iNumberB) {
      iNumberB -= iNumberA;
    } else {
      iNumberA -= iNumberB;
    }
  }

  return iNumberA;
}

}  // namespace algorithms
