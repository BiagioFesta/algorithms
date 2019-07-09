/*
  Copyright (C) 2019  Biagio Festa

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
#include <algorithm>
#include <algorithms/Array/RadixSort.hpp>
#include <cstdint>
#include <vector>
#include "Utilities.hpp"

namespace {

constexpr std::int64_t kMinValue = 1;
constexpr std::int64_t kMaxValue = 1 << 15;
static_assert(kMinValue <= kMaxValue);

}  // anonymous namespace

namespace algorithms::benchmark {

void bmRadixSort(::benchmark::State& iState) {
  const auto kSize = iState.range();

  for (auto _ : iState) {
    auto v = GenerateVector<unsigned int>(kSize);
    RadixSort(&v);
    ::benchmark::DoNotOptimize(std::is_sorted(v.cbegin(), v.cend()));
  }
}
BENCHMARK(bmRadixSort)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

void bmStdSort(::benchmark::State& iState) {
  const auto kSize = iState.range();

  for (auto _ : iState) {
    auto v = GenerateVector<unsigned int>(kSize);
    std::sort(v.begin(), v.end());
    ::benchmark::DoNotOptimize(std::is_sorted(v.cbegin(), v.cend()));
  }
}
BENCHMARK(bmStdSort)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

}  // namespace algorithms::benchmark
