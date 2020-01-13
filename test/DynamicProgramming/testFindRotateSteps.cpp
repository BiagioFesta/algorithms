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
#include <algorithms/DynamicProgramming/FindRotateSteps.hpp>
#include <tuple>
#include <vector>

namespace algorithms::test {

TEST(DynamicProgramming, FindRotateSteps) {
  using Test = std::tuple<const char*, const char*, std::size_t>;
  const std::vector<Test> testCases = {
      {"godding", "gd", 4u},
      {"caotmcaataijjxi",
       "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx",
       137u}};

  for (const auto& [ring, key, expt] : testCases) {
    ASSERT_EQ(FindRotateSteps(ring, key), expt);
  }
}

}  // namespace algorithms::test
