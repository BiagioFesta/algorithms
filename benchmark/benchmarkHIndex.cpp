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
#include <algorithm>
#include <array>
#include <cstdint>
#include <limits>
#include <vector>
#include "Utilities.hpp"

namespace {

constexpr std::int64_t kMinValue = 1;
constexpr std::int64_t kMaxValue = 1 << 15;
static_assert(kMinValue <= kMaxValue);

std::vector<int> generateVector(const std::size_t iSize) {
  using algorithms::benchmark::RndIntGenerator;
  using RndInteger_t = std::uint16_t;

  RndIntGenerator<RndInteger_t> aRndGenerator{0};
  static_assert(std::numeric_limits<RndInteger_t>::max() <=
                std::numeric_limits<int>::max());

  std::vector<int> aVector(iSize);
  std::generate(aVector.begin(), aVector.end(), aRndGenerator);
  return aVector;
}

}  // anonymous namespace

namespace algorithms::benchmark {

void bmHIndex(::benchmark::State& ioState) {
  auto v = ::generateVector(ioState.range());

  for (auto _ : ioState) {
    ::benchmark::DoNotOptimize(hIndex(&v));
  }
}
BENCHMARK(bmHIndex)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

void bmHIndexLinear(::benchmark::State& ioState) {
  auto v = ::generateVector(ioState.range());

  for (auto _ : ioState) {
    ::benchmark::DoNotOptimize(hIndexLinear(v));
  }
}
BENCHMARK(bmHIndexLinear)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

}  // namespace algorithms::benchmark
