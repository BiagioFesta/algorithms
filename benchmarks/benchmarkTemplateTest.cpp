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
#include <algorithms/Array/CountSmallerAfterSelf.hpp>
#include <algorithms/Array/DeckIncreasingReveal.hpp>
#include <algorithms/Array/RankTransformArray.hpp>
#include <algorithms/Array/ValidateStackSequences.hpp>
#include <algorithms/BackTracking/BeautifulArrangement.hpp>
#include <algorithms/BackTracking/MaxConcatUniqueChars.hpp>
#include <algorithms/BackTracking/NumbersConsecutiveDifferences.hpp>
#include <algorithms/BackTracking/RestoreIPAddresses.hpp>
#include <algorithms/DynamicProgramming/BuySellStockWithCooldown.hpp>
#include <algorithms/DynamicProgramming/CoinChange2.hpp>
#include <algorithms/DynamicProgramming/PalindromePartitioningII.hpp>
#include <algorithms/Graph/MinimumGeneticMutation.hpp>
#include <algorithms/Misc/BasicCalculator.hpp>
#include <algorithms/Misc/BrokenCalculator.hpp>
#include <algorithms/Misc/NextGreaterElementIII.hpp>
#include <algorithms/String/FindAllAnagramsString.hpp>
#include <algorithms/String/SwapAdjacentLR.hpp>
#include <algorithms/String/ValidPalindrome.hpp>
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
template <std::size_t Size, typename T = int, typename Container = std::vector<T>>
constexpr Container SeqList() {
  return SeqListImpl<Container>(std::make_integer_sequence<T, Size>());
}

}  // anonymous namespace

namespace algorithms::benchmark {

GENERATE_BENCHMARK(FindAllAnagramsString, "cbaebabacd", "abc");
GENERATE_BENCHMARK(ValidateStackSequences, {1, 2, 3, 4, 5}, {4, 5, 3, 2, 1});
GENERATE_BENCHMARK(DeckIncreasingReveal, SeqList<1024>());
GENERATE_BENCHMARK(
    MinimumGeneticMutation,
    "AAAAAAAA",
    "CCCCCCCC",
    {"AAAAAAAA", "AAAAAAAC", "AAAAAACC", "AAAAACCC", "AAAACCCC", "AACACCCC", "ACCACCCC", "ACCCCCCC", "CCCCCCCA"});
GENERATE_BENCHMARK(BrokenCalculator, 2, 10000);
GENERATE_BENCHMARK(NumbersConsecutiveDifferences, 9, 0);
GENERATE_BENCHMARK(BasicCalculator, "(2+3-(5+(3)-(4)+(5+6+7-3-(3)+(3+2)+3)-4+5)-2)+10");
GENERATE_BENCHMARK(CoinChange2, 5, {1, 2, 5});
GENERATE_BENCHMARK(SwapAdjacentLR,
                   "RXXXXLXXXXXRXXXXXLXXXXXLXXXXXRXXXXLXXXXXRXXXXXLXXXXXRXXXXXL"
                   "XXXLXXXXRXXXRXX",
                   "XXRXLXXXXXXXXRXLXXXXLXXXXXXXXXXRXLXXXXXXXXRXLXXXXXXXXRXLXXX"
                   "XLXXXXXXXXRXRXX");
GENERATE_BENCHMARK(BuySellStockWithCooldown, {1, 2, 3, 0, 2});
GENERATE_BENCHMARK(RestoreIPAddresses, "25525511135");
GENERATE_BENCHMARK(BeautifulArrangement, 6);
GENERATE_BENCHMARK(PalindromePartitioningII, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
GENERATE_BENCHMARK(CountSmallerAfterSelf, SeqList<1024>());
GENERATE_BENCHMARK(NextGreaterElementIII, 1999999999);
GENERATE_BENCHMARK(ValidPalindrome, "A man, a plan, a canal: Panama");
GENERATE_BENCHMARK(RankTransformArray, {37, 12, 28, 9, 100, 56, 80, 5, 12});
GENERATE_BENCHMARK(MaxConcatUniqueChars, {"cha", "r", "act", "ers"});

}  // namespace algorithms::benchmark
