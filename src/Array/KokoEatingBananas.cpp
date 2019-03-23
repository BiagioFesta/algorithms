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
#include <algorithm>
#include <algorithms/Array/KokoEatingBananas.hpp>
#include <cassert>
#include <cmath>
#include <limits>
#include <vector>

namespace {

struct Tester {
  Tester(const std::vector<int>& piles, const int H);

  bool operator()(const int solution) const;

 private:
  const std::vector<int>& _piles;
  const int _h;
};

Tester::Tester(const std::vector<int>& piles, const int H)
    : _piles(piles), _h(H) {}

bool Tester::operator()(const int solution) const {
  int timeSpent = 0;

  for (const int value : _piles) {
    timeSpent += static_cast<int>(
        std::ceil(static_cast<double>(value) / static_cast<double>(solution)));
  }

  return timeSpent <= _h;
}

}  // anonymous namespace

namespace algorithms {

int KokoEatingBananas(const std::vector<int>& piles, const int H) {
  assert(H >= static_cast<int>(piles.size()));

  int upperBound = std::numeric_limits<int>::min();

  double relaxedSolution = 0.0;
  for (const int value : piles) {
    upperBound = std::max(upperBound, value);
    relaxedSolution += value;
  }
  relaxedSolution /= H;
  int lowerBound = static_cast<int>(std::ceil(relaxedSolution));

  ::Tester tester(piles, H);
  int solution = std::numeric_limits<int>::max();

  while (lowerBound <= upperBound) {
    const int middle = (lowerBound + upperBound) / 2;
    if (tester(middle)) {
      solution = std::min(solution, middle);
      upperBound = middle - 1;
    } else {
      lowerBound = middle + 1;
    }
  }

  // By contract there always is a solution
  assert(solution != std::numeric_limits<int>::max());

  return solution;
}

}  // namespace algorithms
