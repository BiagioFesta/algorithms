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
#include <algorithms/BackTracking/LetterCombinationsPhoneNumber.hpp>
#include <array>
#include <cassert>
#include <cmath>
#include <stack>
#include <string>
#include <vector>

namespace {

constexpr std::size_t kSizeMap = 8;
constexpr std::array<const char*, kSizeMap> kKeyMap{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void LetterCombinationsPhoneNumberImpl(const char* digits, std::string* comp, std::vector<std::string>* out) {
  const char d = *digits;
  if (d == '\0') {
    if (!comp->empty()) {
      out->push_back(*comp);
    }
  } else {
    assert(static_cast<std::size_t>(d - '2') < kSizeMap);
    const char* n = kKeyMap[d - '2'];
    while (*n != '\0') {
      comp->push_back(*n);
      LetterCombinationsPhoneNumberImpl(digits + 1, comp, out);
      comp->pop_back();
      ++n;
    }
  }
}

}  // anonymous namespace

namespace algorithms {

std::vector<std::string> LetterCombinationsPhoneNumber(const std::string& digits) {
  std::vector<std::string> ans;
  std::string tmp;

  ans.reserve(std::pow(3, digits.size()));
  tmp.reserve(digits.size());

  ::LetterCombinationsPhoneNumberImpl(digits.c_str(), &tmp, &ans);

  return ans;
}

}  // namespace algorithms
