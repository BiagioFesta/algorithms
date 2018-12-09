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
#include <AlgArrays.hpp>
#include <cstdint>
#include <limits>
#include <vector>
#include "Utilities.hpp"

namespace {

constexpr std::int64_t kMinValue = 1;
constexpr std::int64_t kMaxValue = 1 << 15;
static_assert(kMinValue <= kMaxValue);

std::vector<int> generatePositiveInts(const std::size_t iSize) {
  using algorithms::benchmark::generateVector;
  using PositiveInt_t = std::uint16_t;

  static_assert(std::numeric_limits<PositiveInt_t>::max() <=
                std::numeric_limits<int>::max());

  auto aVector = generateVector<PositiveInt_t>(iSize);
  return {aVector.cbegin(), aVector.cend()};
}

}  // anonymous namespace

namespace algorithms::benchmark {

void bmHIndex(::benchmark::State& iState) {
  auto v = ::generatePositiveInts(iState.range());

  for (auto _ : iState) {
    ::benchmark::DoNotOptimize(hIndex(&v));
  }
}
BENCHMARK(bmHIndex)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

void bmHIndexLinear(::benchmark::State& iState) {
  auto v = ::generatePositiveInts(iState.range());

  for (auto _ : iState) {
    ::benchmark::DoNotOptimize(hIndexLinear(v));
  }
}
BENCHMARK(bmHIndexLinear)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

}  // namespace algorithms::benchmark
