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
#include <algorithms/BackTracking/MaxConcatUniqueChars.hpp>
#include <cassert>
#include <string>
#include <vector>

namespace {

using BitMask = std::size_t;
using VectMasks = std::vector<BitMask>;
static_assert(static_cast<std::size_t>('z' - 'a') < (sizeof(BitMask) * 8));

/*! \brief Compute the 'mask' for each string of the input vector.
 *  The mask simply indicates the letters present in the string.
 *
 *      E.g.:
 *        'ac'        ->       0..000000101  (MSB  --- LSB)
 *
 *  \note If the string contains duplicate letters, the mask is zero.
 */
VectMasks ComputeMasks(const std::vector<std::string>& arr) {
  VectMasks vectMasks;
  BitMask mask, bit;

  vectMasks.reserve(arr.size());

  for (const auto& str : arr) {
    mask = 0;
    for (const char c : str) {
      assert(c >= 'a' && c <= 'z');
      bit = 1 << static_cast<int>(c - 'a');
      if (mask & bit) {
        mask = 0;
        break;
      }
      mask |= bit;
    }
    vectMasks.emplace_back(mask);
  }

  return vectMasks;
}

int MaxConcatUniqueCharsImpl(const std::vector<std::string>& arr,
                             const VectMasks& vectMasks,
                             const std::size_t index,
                             BitMask* bitMask) {
  if (arr.size() <= index) {
    return 0;
  }

  int ans = ::MaxConcatUniqueCharsImpl(arr, vectMasks, index + 1, bitMask);

  const BitMask mask = vectMasks[index];
  if (mask && !(mask & (*bitMask))) {
    *bitMask |= mask;
    const int opt =
        static_cast<int>(arr[index].size()) + ::MaxConcatUniqueCharsImpl(arr, vectMasks, index + 1, bitMask);
    ans = std::max(ans, opt);
    *bitMask ^= mask;
  }

  return ans;
}

}  // anonymous namespace

namespace algorithms {

int MaxConcatUniqueChars(const std::vector<std::string>& arr) {
  const VectMasks vectMasks = ::ComputeMasks(arr);
  BitMask bitMask = 0;
  return ::MaxConcatUniqueCharsImpl(arr, vectMasks, 0, &bitMask);
}

}  // namespace algorithms
