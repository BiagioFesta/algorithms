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
#include <benchmark/benchmark.h>
#include <FlatSet.hpp>
#include <random>
#include <set>
#include <type_traits>

namespace {

struct RndIntGenerator {
  using RndEngine_t = std::mt19937_64;
  using Seed_t = RndEngine_t::result_type;

  explicit RndIntGenerator(Seed_t iSeed) : _rndEngine(iSeed) {}

  int operator()() noexcept { return _rndDistribution(_rndEngine); }

  RndEngine_t _rndEngine;
  std::uniform_int_distribution<int> _rndDistribution;
};

RndIntGenerator sRandomIntsEngine{0};

template <typename T, typename = std::void_t<>>
struct hasReserve : std::false_type {};

template <typename T>
struct hasReserve<T, std::void_t<decltype(&T::reserve)>> : std::true_type {};

static_assert(hasReserve<algorithms::FlatSet<int>>::value);
static_assert(!hasReserve<std::set<int>>::value);

template <typename ContainerOfInts>
void InsertRndInts(const std::size_t iSize, ContainerOfInts* oContainer) {
  if constexpr (hasReserve<ContainerOfInts>::value) {
    oContainer->reserve(iSize);
  }

  for (std::size_t i = 0; i < iSize; ++i) {
    oContainer->insert(sRandomIntsEngine());
  }
}

}  // anonymous namespace

namespace algorithms::benchmark {

template <typename Container>
void BMinsert(::benchmark::State& iState) {
  using RangeType = decltype(iState.range());
  const RangeType kSize = iState.range();

  Container aContainer;
  while (iState.KeepRunning()) {
    InsertRndInts(kSize, &aContainer);
  }
  ::benchmark::DoNotOptimize(aContainer.count(::sRandomIntsEngine()));
}
BENCHMARK_TEMPLATE(BMinsert, std::set<int>)
    ->RangeMultiplier(2)
    ->Range(1, 1 << 15);
BENCHMARK_TEMPLATE(BMinsert, FlatSet<int>)
    ->RangeMultiplier(2)
    ->Range(1, 1 << 15);

template <typename Container>
void BMlookup(::benchmark::State& ioState) {
  using RangeType = decltype(ioState.range());

  const RangeType kSize = ioState.range();

  Container aContainer;
  InsertRndInts(kSize, &aContainer);

  while (ioState.KeepRunning()) {
    ::benchmark::DoNotOptimize(aContainer.count(::sRandomIntsEngine()));
  }
}
BENCHMARK_TEMPLATE(BMlookup, std::set<int>)
    ->RangeMultiplier(2)
    ->Range(1, 1 << 15);
BENCHMARK_TEMPLATE(BMlookup, FlatSet<int>)
    ->RangeMultiplier(2)
    ->Range(1, 1 << 15);

}  // namespace algorithms::benchmark
