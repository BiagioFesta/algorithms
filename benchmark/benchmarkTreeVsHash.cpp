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
#include <cassert>
#include <limits>
#include <random>
#include <set>
#include <unordered_set>

namespace {

constexpr std::int64_t kMinValue = 1;
constexpr std::int64_t kMaxValue = 1 << 20;
static_assert(kMinValue <= kMaxValue);
using RndEngine = std::mt19937_64;

std::vector<int> GenerateRndSequence(const RndEngine::result_type iSeed,
                                     const std::size_t iSize) {
  RndEngine rndEngine(iSeed);
  std::uniform_int_distribution<int> rndValue;

  std::vector<int> vector;
  vector.reserve(iSize);

  std::generate_n(std::back_inserter(vector), iSize, [&rndEngine, &rndValue]() {
    return rndValue(rndEngine);
  });

  return vector;
}

std::vector<int> GenerateRndSequenceButValue(const RndEngine::result_type iSeed,
                                             const std::size_t iSize,
                                             const int iValueToRemove,
                                             const int iNewValue) {
  assert(iValueToRemove != iNewValue);
  auto vector = ::GenerateRndSequence(iSeed, iSize);
  std::replace(vector.begin(), vector.end(), iValueToRemove, iNewValue);
  return vector;
}

int GenerateRndValue(const RndEngine::result_type iSeed) {
  return ::GenerateRndSequence(iSeed, 1).front();
}

}  // anonymous namespace

namespace algorithms::benchmark {

template <typename Container>
void BMinsertNaturalSequence(::benchmark::State& iState) {
  using RangeType = decltype(iState.range());
  using value_type = typename Container::value_type;

  const RangeType kSize = iState.range();

  for (auto _ : iState) {
    Container container;
    for (RangeType i = 0; i < kSize; ++i) {
      ::benchmark::DoNotOptimize(container.emplace(static_cast<value_type>(i)));
    }
  }
}
BENCHMARK_TEMPLATE(BMinsertNaturalSequence, std::set<int>)
    ->RangeMultiplier(2)
    ->Range(::kMinValue, ::kMaxValue);
BENCHMARK_TEMPLATE(BMinsertNaturalSequence, std::unordered_set<int>)
    ->RangeMultiplier(2)
    ->Range(::kMinValue, ::kMaxValue);

template <typename Container>
void BMinsertRandomSequence(::benchmark::State& iState) {
  using RangeType = decltype(iState.range());
  constexpr ::RndEngine::result_type kFixedSeed = 0;

  const RangeType kSize = iState.range();
  const auto kSequence = ::GenerateRndSequence(kFixedSeed, kSize);

  for (auto _ : iState) {
    Container container(kSequence.cbegin(), kSequence.cend());
    ::benchmark::DoNotOptimize(container.size());
  }
}
BENCHMARK_TEMPLATE(BMinsertRandomSequence, std::set<int>)
    ->RangeMultiplier(2)
    ->Range(::kMinValue, ::kMaxValue);
BENCHMARK_TEMPLATE(BMinsertRandomSequence, std::unordered_set<int>)
    ->RangeMultiplier(2)
    ->Range(::kMinValue, ::kMaxValue);

template <typename Container>
void BMlookupMiss(::benchmark::State& iState) {
  using RangeType = decltype(iState.range());
  constexpr ::RndEngine::result_type kFixedSeed = 0;

  const RangeType kSize = iState.range();
  const int kMissValue = ::GenerateRndValue(kFixedSeed);
  const int kPresentValue =
      (kMissValue == std::numeric_limits<int>::max() ? kMissValue - 1
                                                     : kMissValue + 1);
  const auto kSequence = ::GenerateRndSequenceButValue(
      kFixedSeed, kSize, kMissValue, kPresentValue);
  const Container kContainer{kSequence.cbegin(), kSequence.cend()};

  for (auto _ : iState) {
    ::benchmark::DoNotOptimize(kContainer.count(kMissValue));
  }
}
BENCHMARK_TEMPLATE(BMlookupMiss, std::set<int>)
    ->RangeMultiplier(2)
    ->Range(::kMinValue, ::kMaxValue);
BENCHMARK_TEMPLATE(BMlookupMiss, std::unordered_set<int>)
    ->RangeMultiplier(2)
    ->Range(::kMinValue, ::kMaxValue);

}  // namespace algorithms::benchmark
