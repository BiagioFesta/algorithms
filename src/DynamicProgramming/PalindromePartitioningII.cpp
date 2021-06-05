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
#include <algorithms/DynamicProgramming/PalindromePartitioningII.hpp>
#include <cassert>
#include <string>
#include <vector>

namespace {

bool IsPalindrome(const char* first, const char* last) noexcept {
  assert(first <= last);
  while (first < last) {
    if (*first != *last) {
      return false;
    }
    ++first;
    --last;
  }
  return true;
}

}  // anonymous namespace

namespace algorithms {

int PalindromePartitioningII(const std::string& str) {
  const int size = str.size();

  std::vector<bool> palindromes(size * size);
  for (int i = 0; i < size; ++i) {                                                   // O(N)
    for (int j = i; j < size; ++j) {                                                 // O(N)
      palindromes[i * size + j] = ::IsPalindrome(str.c_str() + i, str.c_str() + j);  // O(N)
    }
  }

  std::vector<int> dp(size);
  int temp;
  for (int j = 1; j < size; ++j) {
    temp = j;
    for (int i = 0; i <= j && temp; ++i) {
      if (palindromes[i * size + j]) {
        temp = i == 0 ? 0 : std::min(temp, 1 + dp[i - 1]);
      }
    }
    dp[j] = temp;
  }

  return size ? dp.back() : 0;
}

}  // namespace algorithms
