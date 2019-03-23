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
#include <algorithms/DynamicProgramming/Fibonacci.hpp>
#include <cassert>

namespace algorithms {

int Fibonacci(const int n) {
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

}  // namespace algorithms
