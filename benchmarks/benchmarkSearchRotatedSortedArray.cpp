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
#include <benchmark/benchmark.h>
#include <algorithm>
#include <algorithms/Array/SearchRotatedSortedArray.hpp>
#include <cassert>
#include <numeric>
#include <random>
#include <vector>

namespace {

constexpr std::int64_t kMinValue = 1 << 0;
constexpr std::int64_t kMaxValue = 1 << 15;
static_assert(kMinValue <= kMaxValue);

std::pair<std::vector<int>, int> GenerateInput(const std::size_t size) {
  assert(size > 0);
  std::mt19937_64 rndEngine;
  std::uniform_int_distribution<std::size_t> rndIndex(0, size - 1);

  std::vector<int> v(size);
  std::iota(v.begin(), v.end(), 0);

  const auto pivot = v.begin() + rndIndex(rndEngine);
  std::rotate(v.begin(), pivot, v.end());

  return std::make_pair(std::move(v), rndIndex(rndEngine));
}

int SearchRotatedSortedArrayLinearSearch(const std::vector<int>& nums, const int target) {
  const auto size = nums.size();
  for (std::size_t i = 0; i < size; ++i) {
    if (nums[i] == target) return i;
  }
  return -1;
}

}  // anonymous namespace

namespace algorithms::benchmark {

void BMSearchRotatedSortedArrayImpl(::benchmark::State& state) {
  const std::size_t size = state.range();
  const auto input = ::GenerateInput(size);

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(SearchRotatedSortedArray(input.first, input.second));
  }
}
BENCHMARK(BMSearchRotatedSortedArrayImpl)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

void BMSearchRotatedSortedArrayLinearSearch(::benchmark::State& state) {
  const std::size_t size = state.range();
  const auto input = ::GenerateInput(size);

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::SearchRotatedSortedArrayLinearSearch(input.first, input.second));
  }
}
BENCHMARK(BMSearchRotatedSortedArrayLinearSearch)->RangeMultiplier(2)->Range(::kMinValue, ::kMaxValue);

}  // namespace algorithms::benchmark
