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
#include "DynamicProgramming.hpp"
#include <algorithm>
#include <array>
#include <cassert>
#include <limits>
#include <string>
#include <vector>

namespace algorithms {

int binomialCoefficient(const int n, const int k) {
  assert(n >= k);
  assert(k >= 0);

  // Recursion ->  (n, k) = (n - 1, k - 1) * n / k
  std::vector<int> aSolutions(k);
  aSolutions[0] = n - k + 1;

  for (int i = 1; i < k; ++i) {
    aSolutions[i] = aSolutions[i - 1] * (n - k + 1 + i) / (i + 1);
  }

  return aSolutions[k - 1];
}

int fibonacci(const int n) {
  assert(n >= 0);

  if (n == 0 || n == 1) return 1;

  int n_1 = 1;
  int n_2 = 0;

  int current;
  for (int i = 2; i <= n; ++i) {
    current = n_1 + n_2;
    n_2 = n_1;
    n_1 = current;
  }

  return current;
}

int minPathSum(const int* const iMatrix, const int M, const int N) {
  static constexpr int kMaxInt = std::numeric_limits<int>::max();
  const int Q = M * N;
  assert(Q > 0);

  std::vector<int> aSolutions(Q);
  aSolutions[Q - 1] = iMatrix[Q - 1];

  for (int i = 1; i < Q; ++i) {
    const int index = Q - 1 - i;
    const int costDown =
        i < N ? kMaxInt : aSolutions[index + N] + iMatrix[index];
    const int costRight =
        i % N == 0 ? kMaxInt : aSolutions[index + 1] + iMatrix[index];
    aSolutions[index] = std::min(costDown, costRight);
  }

  return aSolutions[0];
}

int longestCommonSubsequence(const std::string& iStr1,
                             const std::string& iStr2) {
  const int N = iStr1.size();
  const int M = iStr2.size();

  std::vector<int> solutions(N * M);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (iStr1[i] == iStr2[j]) {
        const int prev =
            (i == 0 || j == 0 ? 0 : solutions[(i - 1) * M + (j - 1)]);
        solutions[i * M + j] = prev + 1;
      } else {
        const int s1 = i != 0 ? solutions[(i - 1) * M + j] : 0;
        const int s2 = j != 0 ? solutions[i * M + (j - 1)] : 0;
        solutions[i * M + j] = std::max(s1, s2);
      }
    }
  }

  return solutions[N * M - 1];
}

int sherlockAndCost(const std::vector<int>& iUpperBounds) {
  std::array<int, 2> L = {0, 0};
  std::array<int, 2> H = {0, 0};

  for (std::size_t i = 0u; i < iUpperBounds.size(); ++i) {
    L[1] = i == 0 ? 0 : std::max(L[0], H[0] + iUpperBounds[i - 1] - 1);
    H[1] = i == 0 ? 0
                  : std::max(
                        H[0] + std::abs(iUpperBounds[i] - iUpperBounds[i - 1]),
                        L[0] + iUpperBounds[i] - 1);
    L[0] = L[1];
    H[0] = H[1];
  }

  return std::max(L[1], H[1]);
}

int substringsSum(const std::string& iStr) {
  static const int kMod = 1000000007;
  if (iStr.empty()) return 0;

  long long prev = iStr[0] - '0';
  long long current;
  long long sum = iStr[0] - '0';
  for (std::size_t i = 1; i < iStr.size(); ++i) {
    current = ((10 * prev) % kMod + (i + 1) * (iStr[i] - '0')) % kMod;
    sum = (sum + current) % kMod;
    prev = current;
  }

  return (int)sum;
}

int keystroke(const int N) {
  const int kNplusOne = N + 1;
  std::vector<int> aSolutions(kNplusOne);

  for (int i = 1; i < kNplusOne; ++i) {
    aSolutions[i] = aSolutions[i - 1] + 1;
    for (int j = 1; j < i - 2; ++j) {
      aSolutions[i] = std::max(aSolutions[i], (i - j - 1) * aSolutions[j]);
    }
  }

  return aSolutions[N];
}

int maxProfit(const std::vector<int>& iPrices) {
  const std::size_t kSize = iPrices.size();
  if (kSize == 0) return 0;

  std::vector<int> aMaxRevenue(kSize);

  int aCurrentMin = iPrices[0];
  for (std::size_t i = 1; i < kSize; ++i) {
    const int iCurrentPrice = iPrices[i];
    aMaxRevenue[i] = std::max(aMaxRevenue[i - 1], iCurrentPrice - aCurrentMin);
    aCurrentMin = std::min(aCurrentMin, iCurrentPrice);
  }

  int aMaxProfit = aMaxRevenue.back();
  int aCurrentMax = iPrices.back();
  for (std::size_t i = kSize; i > 0; --i) {
    const int iCurrentPrice = iPrices[i - 1];
    aMaxProfit =
        std::max(aMaxProfit, aCurrentMax - iCurrentPrice + aMaxRevenue[i - 1]);
    aCurrentMax = std::max(aCurrentMax, iCurrentPrice);
  }

  return aMaxProfit;
}

std::size_t findRotateSteps(const std::string_view iRing,
                            const std::string_view iKey) {
  constexpr auto kMaxIndex = std::numeric_limits<std::size_t>::max();
  const auto kK = iKey.size();
  const auto kR = iRing.size();

  const auto kFnDistance = [kR](const std::size_t i,
                                const std::size_t j) noexcept {
    const auto aAbs = i < j ? j - i : i - j;
    return std::min(aAbs, kR - aAbs);
  };

  std::vector<std::size_t> aSolutions((kK + 1) * kR);

  for (auto c = iKey.crbegin(); c != iKey.crend(); ++c) {  // O(K)
    const auto i = kK - std::distance(iKey.crbegin(), c) - 1;

    for (std::size_t j = 0; j < kR; ++j) {  // O(R)
      std::size_t aMin = kMaxIndex;

      for (std::size_t q = 0; q < kR; ++q) {  // O(R)
        if (iRing[q] == iKey[i]) {
          const auto aRecur = aSolutions[(i + 1) * kR + q];
          const auto aDist = kFnDistance(j, q);
          aMin = std::min(aMin, aRecur + 1 + aDist);
        }
      }
      assert(aMin != kMaxIndex);

      aSolutions[i * kR + j] = aMin;
    }
  }

  return aSolutions[0];
}

std::pair<int, int> twoEggsDropping(const int iNumFloors) {
  assert(iNumFloors >= 0);

  std::vector<int> aTable(iNumFloors + 1);

  int aKMin = -1;
  int aMinValue;

  for (int i = iNumFloors - 1; i >= 0; --i) {
    aKMin = -1;
    aMinValue = std::numeric_limits<int>::max();

    for (int k = i; k < iNumFloors; ++k) {
      const int aKSolution = std::max(k - i, aTable[k + 1]);
      if (aKSolution < aMinValue) {
        aMinValue = aKSolution;
        aKMin = k;
      }
    }
    assert(aKMin != -1);

    aTable[i] = aMinValue + 1;
  }

  return std::make_pair(aTable[0], aKMin);
}

std::vector<int> cheapestJump(const std::vector<int>& iVector,
                              const int iMaxJump) {
  assert(iMaxJump >= 0);
  assert(!iVector.empty());

  const int kSize = iVector.size();

  std::vector<std::pair<int, int>> aTableSolutions(kSize, {0, -1});

  for (int i = kSize - 2; i >= 0; --i) {
    auto& [aCostFromI, aIndexFromI] = aTableSolutions[i];

    const int kUpperBound = std::min(i + iMaxJump + 1, kSize);
    for (int k = i + 1; k < kUpperBound; ++k) {
      const int aKValue = iVector[k];

      if (aKValue >= 0) {
        const int aSolutionK = aKValue + aTableSolutions[k].first;
        if (aIndexFromI == -1 || aSolutionK < aCostFromI) {
          aIndexFromI = k;
          aCostFromI = aSolutionK;
        }
      }
    }
  }

  std::vector<int> aPath;
  aPath.reserve(kSize);

  int aIndex = 0;
  while (aTableSolutions[aIndex].second != -1) {
    aPath.push_back(aIndex + 1);
    aIndex = aTableSolutions[aIndex].second;
  }
  aPath.push_back(aIndex + 1);

  if (aPath.back() != kSize) {
    aPath.clear();
  }

  return aPath;
}

}  // namespace algorithms
