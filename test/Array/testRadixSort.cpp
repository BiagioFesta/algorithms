/*
  Copyright (C) 2018  Biagio Festa

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
#include <algorithms/Array/RadixSort.hpp>
#include <random>

namespace algorithms::test {

TEST(Array, RadixSort) {
  using RndEngine_t = std::mt19937_64;
  constexpr int kNumTest = 64;
  constexpr std::size_t kMaxSize = 64;

  RndEngine_t aRndEngine;
  std::uniform_int_distribution<unsigned int> aDistribution;

  std::vector<unsigned int> aVector, aSortedVector;

  for (int i = 0; i < kNumTest; ++i) {
    aVector.resize(aDistribution(aRndEngine) % kMaxSize);
    std::generate(
        aVector.begin(), aVector.end(), [&aRndEngine, &aDistribution]() {
          return aDistribution(aRndEngine);
        });

    aSortedVector = aVector;
    RadixSort(&aSortedVector);

    ASSERT_TRUE(std::is_sorted(aSortedVector.cbegin(), aSortedVector.cend()));
    ASSERT_TRUE(std::is_permutation(aSortedVector.cbegin(),
                                    aSortedVector.cend(),
                                    aVector.cbegin(),
                                    aVector.cend()));
  }
}

}  // namespace algorithms::test
