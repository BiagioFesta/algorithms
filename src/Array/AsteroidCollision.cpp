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
#include <algorithms/Array/AsteroidCollision.hpp>
#include <deque>
#include <vector>

namespace algorithms {

std::vector<int> AsteroidCollision(const std::vector<int>& asteroids) {
  std::deque<int> stack;

  for (const int asteroid : asteroids) {
    if (asteroid < 0) {
      const int positiveAsteroid = -asteroid;
      while (!stack.empty() && stack.back() >= 0 &&
             stack.back() < positiveAsteroid) {
        stack.pop_back();
      }
      if (stack.empty() || stack.back() < 0) {
        stack.push_back(asteroid);
      } else if (positiveAsteroid == stack.back()) {
        stack.pop_back();
      }
    } else {
      stack.push_back(asteroid);
    }
  }  // for all asteroids

  return std::vector<int>(stack.cbegin(), stack.cend());
}

}  // namespace algorithms
