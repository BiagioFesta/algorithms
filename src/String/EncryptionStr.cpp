/*
  Copyright (C) 2020  Biagio Festa

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
#include <algorithms/String/EncryptionStr.hpp>
#include <cassert>
#include <cmath>
#include <locale>
#include <string>

namespace algorithms {

std::string EncryptionStr(const std::string& iString) {
  std::string aTrailedString;
  aTrailedString.reserve(iString.size());
  std::copy_if(iString.cbegin(), iString.cend(), std::back_inserter(aTrailedString), [](const char c) {
    return !std::isspace(c, std::locale());
  });
  const int aNewLen = aTrailedString.size();
  const double aSqrt = std::sqrt(static_cast<double>(aNewLen));

  const int aFloor = static_cast<int>(std::floor(aSqrt));
  const int aCeil = static_cast<int>(std::ceil(aSqrt));

  int nRows = aCeil;
  int nCols = aCeil;
  if (aFloor * aFloor >= aNewLen) {
    nRows = aFloor;
    nCols = aFloor;
  } else if (aFloor * aCeil >= aNewLen) {
    nRows = aFloor;
  }
  assert(nRows * nCols >= aNewLen);

  std::string aRtn;
  aRtn.reserve(aNewLen);

  for (int j = 0; j < nCols; ++j) {
    for (int i = 0; i < nRows; ++i) {
      const int aIndex = i * nCols + j;
      if (aIndex < aNewLen) {
        aRtn.push_back(aTrailedString[aIndex]);
      }
    }
    aRtn.push_back(' ');
  }
  aRtn.pop_back();

  return aRtn;
}

}  // namespace algorithms
