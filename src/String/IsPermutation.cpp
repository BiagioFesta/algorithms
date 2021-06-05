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
#include <algorithms/String/IsPermutation.hpp>
#include <cstring>

namespace algorithms {

bool IsPermutation(const char* iStr1, const char* iStr2) {
  constexpr int kLenTable = 2 << 8;

  int aTable[kLenTable];
  int aLen1 = 0;
  int aLen2 = 0;

  std::memset(aTable, 0, kLenTable * sizeof(int));

  while (*iStr1 != '\0') {
    aTable[static_cast<int>(*iStr1)] += 1;
    ++iStr1;
    ++aLen1;
  }

  while (*iStr2 != '\0') {
    int& aOccurrence = aTable[static_cast<int>(*iStr2)];
    if (aOccurrence == 0) return false;
    --aOccurrence;
    ++iStr2;
    ++aLen2;
  }

  if (aLen1 != aLen2) return false;

  return true;
}

}  // namespace algorithms
