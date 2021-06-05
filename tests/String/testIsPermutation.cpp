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
#include <algorithms/String/IsPermutation.hpp>

namespace algorithms::test {

TEST(String, IsPermutation) {
  const char* str1 = "dog";
  const char* str2 = "god";
  const char* str3 = "God";
  const char* str4 = "god ";
  const char* str5 = "og";

  ASSERT_TRUE(IsPermutation(str1, str2));
  ASSERT_FALSE(IsPermutation(str1, str3));
  ASSERT_FALSE(IsPermutation(str1, str4));
  ASSERT_FALSE(IsPermutation(str1, str5));
}

}  // namespace algorithms::test
