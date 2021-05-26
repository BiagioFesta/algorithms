/*
  Copyright (C) 2020  Biagio Festa

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
#include <algorithms/DynamicProgramming/OnesAndZeroes.hpp>
#include <random>
#include <string>
#include <vector>

namespace {

using RndEngine_t = std::mt19937_64;

std::vector<std::string> GenerateBinaryStrs(const std::size_t lenVect,
                                            const std::size_t maxSizeSingleStr,
                                            RndEngine_t* rndEngine) {
  std::uniform_int_distribution<std::size_t> rndLenStr(1, maxSizeSingleStr);
  std::uniform_int_distribution<> rndDigit(0, 1);

  std::vector<std::string> strs(lenVect);
  for (auto& str : strs) {
    const std::size_t lenStr = rndLenStr(*rndEngine);
    str.reserve(lenStr);
    for (std::size_t i = 0; i < lenStr; ++i) {
      str.push_back(rndDigit(*rndEngine) ? '1' : '0');
    }
  }

  return strs;
}

}  // anonymous namespace

namespace algorithms::benchmark {

void BMOnesAndZeroes(::benchmark::State& state) {
  constexpr std::size_t kMaxSizeSingleStr = 10;

  ::RndEngine_t rndEngine;

  const auto S = state.range(0);
  const auto M = state.range(1);
  const auto N = state.range(2);
  const auto strs = ::GenerateBinaryStrs(S, kMaxSizeSingleStr, &rndEngine);

  for (auto _ : state) {
    OnesAndZeroes(strs, M, N);
  }
}
BENCHMARK(BMOnesAndZeroes)
    ->RangeMultiplier(10)
    ->Ranges({{10, 100}, {10, 100}, {10, 100}});

}  // namespace algorithms::benchmark
