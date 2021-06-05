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
#ifndef ALGORITHMS__BENCHMARK__UTILITIES__HPP
#define ALGORITHMS__BENCHMARK__UTILITIES__HPP
#include <algorithm>
#include <cstdint>
#include <random>
#include <type_traits>
#include <vector>

namespace algorithms::benchmark {

template <typename T>
struct RndIntGenerator {
  static_assert(std::is_integral_v<T>);

  using value_type = T;
  using RndEngine_t = std::mt19937_64;
  using Seed_t = RndEngine_t::result_type;

  explicit RndIntGenerator(Seed_t iSeed) : rndEngine_(iSeed) {}

  value_type operator()() noexcept {
    return rndDistribution_(rndEngine_);
  }

  RndEngine_t rndEngine_;
  std::uniform_int_distribution<value_type> rndDistribution_;
};

template <typename T>
struct RndRealGenerator {
  static_assert(std::is_floating_point_v<T>);

  using value_type = T;
  using RndEngine_t = std::mt19937_64;
  using Seed_t = RndEngine_t::result_type;

  explicit RndRealGenerator(Seed_t seed) : rndEngine_(seed) {}

  value_type operator()() noexcept {
    return rndDistribution_(rndEngine_);
  }

  RndEngine_t rndEngine_;
  std::uniform_real_distribution<value_type> rndDistribution_;
};

template <typename T, typename RndGenerator = RndIntGenerator<T>>
std::vector<T> GenerateVector(const std::size_t iSize, typename RndGenerator::Seed_t iSeed = 0) {
  RndGenerator aRndGenerator{iSeed};

  std::vector<T> aVector(iSize);
  std::generate(aVector.begin(), aVector.end(), aRndGenerator);
  return aVector;
}

}  // namespace algorithms::benchmark

#endif  // ALGORITHMS__BENCHMARK__UTILITIES__HPP
