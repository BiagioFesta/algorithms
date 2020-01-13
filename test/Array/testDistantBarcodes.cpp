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
#include <gtest/gtest.h>
#include <algorithms/Array/AreAllDistant.hpp>
#include <algorithms/Array/DistantBarcodes.hpp>
#include <vector>

namespace algorithms::test {

TEST(Array, DistantBarcodes) {
  using Test = std::vector<int>;
  const std::vector<Test> testCases = {{1, 1, 1, 2, 2, 2},
                                       {1, 1, 1, 1, 2, 2, 3, 3},
                                       {1},
                                       {1, 2},
                                       {1, 2, 3},
                                       {1, 2, 3, 3}};

  for (const auto& v : testCases) {
    const auto result = DistantBarcodes(v);
    ASSERT_EQ(v.size(), result.size());
    ASSERT_TRUE(AreAllDistant(result));
  }
}

}  // namespace algorithms::test
