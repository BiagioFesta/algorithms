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
#include <algorithms/DynamicProgramming/Fibonacci.hpp>
#include <cassert>
#include <utility>

namespace algorithms {

int Fibonacci(const int n) {
  assert(n >= 0);

  int n_0 = 0;
  int n_1 = 1;
  for (int i = 0; i < n; ++i) {
    n_0 = std::exchange(n_1, n_0 + n_1);
  }
  return n_0;
}

}  // namespace algorithms
