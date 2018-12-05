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
#include <cstdint>
#include <set>
#include <type_traits>
#include "Utilities.hpp"

namespace {

constexpr std::int64_t kMinValue = 1;
constexpr std::int64_t kMaxValue = 1 << 15;
static_assert(kMinValue <= kMaxValue);

template <typename T, typename = std::void_t<>>
struct hasReserve : std::false_type {};

template <typename T>
struct hasReserve<T, std::void_t<decltype(&T::reserve)>> : std::true_type {};

static_assert(hasReserve<algorithms::FlatSet<int>>::value);
static_assert(!hasReserve<std::set<int>>::value);

template <typename ContainerOfInts>
void InsertRndInts(const std::size_t iSize, ContainerOfInts* oContainer) {
  using Type = typename ContainerOfInts::value_type;
  using algorithms::benchmark::RndIntGenerator;

  RndIntGenerator<Type> aRandomIntsEngine{0};

  if constexpr (hasReserve<ContainerOfInts>::value) {
    oContainer->reserve(iSize);
  }

  for (std::size_t i = 0; i < iSize; ++i) {
    oContainer->insert(aRandomIntsEngine());
  }
}

}  // anonymous namespace

namespace algorithms::benchmark {

template <typename Container>
void BMinsert(::benchmark::State& iState) {
  using RangeType = decltype(iState.range());
  const RangeType kSize = iState.range();

  for (auto _ : iState) {
    Container aContainer;
    InsertRndInts(kSize, &aContainer);
  }
}
BENCHMARK_TEMPLATE(BMinsert, std::set<int>)
    ->RangeMultiplier(2)
    ->Range(kMinValue, kMaxValue);
BENCHMARK_TEMPLATE(BMinsert, FlatSet<int>)
    ->RangeMultiplier(2)
    ->Range(kMinValue, kMaxValue);

template <typename Container>
void BMlookup(::benchmark::State& iState) {
  using Type = typename Container::value_type;
  using RangeType = decltype(iState.range());

  const RangeType kSize = iState.range();

  RndIntGenerator<Type> aRandomIntsEngine{0};

  Container aContainer;
  InsertRndInts(kSize, &aContainer);

  for (auto _ : iState) {
    ::benchmark::DoNotOptimize(aContainer.count(aRandomIntsEngine()));
  }
}
BENCHMARK_TEMPLATE(BMlookup, std::set<int>)
    ->RangeMultiplier(2)
    ->Range(kMinValue, kMaxValue);
BENCHMARK_TEMPLATE(BMlookup, FlatSet<int>)
    ->RangeMultiplier(2)
    ->Range(kMinValue, kMaxValue);

}  // namespace algorithms::benchmark
