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

}  // namespace algorithms
