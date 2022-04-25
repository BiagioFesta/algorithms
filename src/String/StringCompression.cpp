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
#include <algorithms/String/StringCompression.hpp>
#include <cstring>
#include <string>

namespace algorithms {

bool StringCompression(const char* iStr, char* oBuffer, const int iSizeBuffer) {
  int bytesWritten = 0;
  int numSame = 0;
  std::string interBuffer;

  while (*iStr != '\0') {
    if (bytesWritten + 1 >= iSizeBuffer) return false;

    if (*iStr == *(iStr + 1)) {
      ++numSame;
    } else {
      if (numSame) {
        interBuffer.clear();
        interBuffer += std::to_string(numSame + 1);
        interBuffer += *iStr;
        if (bytesWritten + static_cast<int>(interBuffer.size()) <= iSizeBuffer) {
          std::memcpy(oBuffer, interBuffer.data(), interBuffer.size());
          oBuffer += interBuffer.size();
          bytesWritten += interBuffer.size();
        } else {
          return false;
        }
        numSame = 0;
      } else {
        *oBuffer = *iStr;
        ++oBuffer;
        ++bytesWritten;
      }
    }

    ++iStr;
  }
  *oBuffer = '\0';

  return true;
}

}  // namespace algorithms
