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
#include <algorithms/String/BiggerIsGreater.hpp>
#include <string>
#include <utility>

namespace algorithms {

std::string BiggerIsGreater(std::string iString) {
  static const char* kNoAnswer = "no answer";

  const int kSize = iString.size();
  int aPivot = kSize - 1;
  while (aPivot > 0 && iString[aPivot - 1] >= iString[aPivot]) --aPivot;
  --aPivot;
  if (aPivot < 0) return kNoAnswer;

  int aSwap = kSize - 1;
  while (iString[aSwap] <= iString[aPivot]) --aSwap;

  std::swap(iString[aPivot], iString[aSwap]);
  std::reverse(iString.begin() + aPivot + 1, iString.end());
  return iString;
}

}  // namespace algorithms
