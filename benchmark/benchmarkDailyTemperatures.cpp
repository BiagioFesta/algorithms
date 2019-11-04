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
#include <algorithms/Array/DailyTemperatures.hpp>
#include <numeric>
#include <vector>

namespace {

std::vector<int> GenerateInputTemplate1(const int size) {
  std::vector<int> v(size);
  std::iota(v.begin(), v.end(), 0);
  std::reverse(v.begin(), v.end() - 1);
  return v;
}

}  // anonymous namespace

namespace algorithms::benchmark {

void BMDailyTemperatures(::benchmark::State& state) {
  const auto input = ::GenerateInputTemplate1(state.range());
  for (auto _ : state) {
    ::benchmark::DoNotOptimize(DailyTemperatures(input));
  }
}
BENCHMARK(BMDailyTemperatures)->RangeMultiplier(2)->Range(1 << 0, 1 << 20);

}  // namespace algorithms::benchmark
