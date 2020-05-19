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
#include <algorithms/BackTracking/MaxConcatUniqueChars.hpp>
#include <bitset>
#include <limits>
#include <string>
#include <vector>

namespace {

constexpr auto BitMaskSize = std::numeric_limits<char>::max();
using BitMask = std::bitset<static_cast<std::size_t>(BitMaskSize)>;

int ApplyToMask(const std::string& str, BitMask* bitMask) noexcept {
  int i = 0;
  for (const char c : str) {
    if (bitMask->test(static_cast<std::size_t>(c))) {
      break;
    }
    bitMask->set(static_cast<std::size_t>(c));
    ++i;
  }
  return i;
}

void RemoveFromMask(const std::string& str,
                    int index,
                    BitMask* bitMask) noexcept {
  char c;
  while (index) {
    c = str[--index];
    bitMask->reset(static_cast<std::size_t>(c));
  }
}

int MaxConcatUniqueCharsImpl(const std::vector<std::string>& arr,
                             const std::size_t i,
                             BitMask* bitMask) {
  int max = 0;
  if (i < arr.size()) {
    max = MaxConcatUniqueCharsImpl(arr, i + 1, bitMask);
    const auto& str = arr[i];
    const auto index = ::ApplyToMask(str, bitMask);
    if (static_cast<std::size_t>(index) == str.size()) {
      max = std::max(max,
                     index + ::MaxConcatUniqueCharsImpl(arr, i + 1, bitMask));
    }
    ::RemoveFromMask(str, index, bitMask);
  }
  return max;
}

}  // anonymous namespace

namespace algorithms {

int MaxConcatUniqueChars(const std::vector<std::string>& arr) {
  BitMask bitMask;
  return ::MaxConcatUniqueCharsImpl(arr, 0, &bitMask);
}

}  // namespace algorithms
