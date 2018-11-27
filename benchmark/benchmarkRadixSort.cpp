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
#include <cstdint>
#include <vector>
#include "Utilities.hpp"

namespace {

constexpr std::int64_t kMinValue = 1;
constexpr std::int64_t kMaxValue = 1 << 15;
static_assert(kMinValue <= kMaxValue);

std::vector<unsigned int> generateVector(const std::size_t iSize) {
  using algorithms::benchmark::RndIntGenerator;

  RndIntGenerator<unsigned int> aRndGenerator{0};

  std::vector<unsigned int> aVector(iSize);
  std::generate(aVector.begin(), aVector.end(), aRndGenerator);
  return aVector;
}

}  // anonymous namespace

namespace algorithms::benchmark {

void bmRadixSort(::benchmark::State& ioState) {
  const auto kSize = ioState.range();

  while (ioState.KeepRunning()) {
    std::vector<unsigned int> v = ::generateVector(kSize);
    radixSort(&v);
    ::benchmark::DoNotOptimize(std::is_sorted(v.cbegin(), v.cend()));
  }
}
BENCHMARK(bmRadixSort)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

void bmStdSort(::benchmark::State& ioState) {
  const auto kSize = ioState.range();

  while (ioState.KeepRunning()) {
    std::vector<unsigned int> v = ::generateVector(kSize);
    std::sort(v.begin(), v.end());
    ::benchmark::DoNotOptimize(std::is_sorted(v.cbegin(), v.cend()));
  }
}
BENCHMARK(bmStdSort)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

}  // namespace algorithms::benchmark
