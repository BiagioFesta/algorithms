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
#include <algorithms/Array/DeckIncreasingReveal.hpp>
#include <algorithms/Array/ValidateStackSequences.hpp>
#include <algorithms/String/FindAllAnagramsString.hpp>
#include <vector>

/*! \brief Macro generate a benchmark for a specific algorithm.
 *  \param [in] FunctionName  The function name implementing the algorithm.
 *  \param [in] ...           The args to pass to the function (input data).
 */
#define GENERATE_BENCHMARK(FunctionName, ...)        \
  void BM##FunctionName(::benchmark::State& state) { \
    for (auto _ : state) {                           \
      ::algorithms::FunctionName(__VA_ARGS__);       \
    }                                                \
  }                                                  \
  BENCHMARK(BM##FunctionName)

namespace {

template <typename Container, typename T, T... Values>
constexpr Container SeqListImpl(const std::integer_sequence<T, Values...>) {
  return Container{Values...};
}

/*! \brief Return a container initialized with a progressive sequence of
 *  integers.
 *    E.g.:
 *      std::vector<int>{0, 1, 2, 3, ,4 ..., Size - 1}
 */
template <std::size_t Size,
          typename T = int,
          typename Container = std::vector<T>>
constexpr Container SeqList() {
  return SeqListImpl<Container>(std::make_integer_sequence<T, Size>());
}

}  // anonymous namespace

namespace algorithms::benchmark {

GENERATE_BENCHMARK(FindAllAnagramsString, "cbaebabacd", "abc");
GENERATE_BENCHMARK(ValidateStackSequences, {1, 2, 3, 4, 5}, {4, 5, 3, 2, 1});
GENERATE_BENCHMARK(DeckIncreasingReveal, SeqList<1024>());

}  // namespace algorithms::benchmark
