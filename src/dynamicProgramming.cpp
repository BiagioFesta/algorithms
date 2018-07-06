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
#include "dynamicProgramming.hpp"
#include <cassert>
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

}  // namespace algorithms
