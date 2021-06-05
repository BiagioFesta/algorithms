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
#include <gtest/gtest.h>
#include <algorithm>
#include <algorithms/String/URLify.hpp>
#include <cstring>
#include <string>

namespace algorithms::test {

TEST(String, URLify) {
  constexpr const char kStr[] = "Mr John Smith";
  constexpr const char kExpectedResult[] = "Mr%20John%20Smith";
  constexpr int kLenStr = sizeof(kStr) - 1;

  std::string aBuffer(kStr);
  const int aNoSpaces = std::count(aBuffer.cbegin(), aBuffer.cend(), ' ');
  aBuffer.resize(aBuffer.size() + (aNoSpaces * 2), ' ');

  URLify(aBuffer.data(), kLenStr);

  ASSERT_TRUE(std::strcmp(aBuffer.c_str(), kExpectedResult) == 0);
}

}  // namespace algorithms::test
