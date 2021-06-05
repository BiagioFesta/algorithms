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
#include <algorithm>
#include <algorithms/Array/DeckIncreasingReveal.hpp>
#include <cassert>
#include <iterator>
#include <vector>

namespace {

template <typename RandomIterator>
void DeckIncreasingRevealImpl(RandomIterator first, RandomIterator last) {
  assert(std::is_sorted(first, last));

  if (const auto size = std::distance(first, last); size < 4) {
    if (size == 3) {
      std::iter_swap(first + 1, last - 1);
    }
  } else {
    DeckIncreasingRevealImpl(first + 1, last);
    std::rotate(first + 1, last - 1, last);  // O(N)
  }
}

}  // anonymous namespace

namespace algorithms {

std::vector<int> DeckIncreasingReveal(std::vector<int> deck) {
  std::sort(deck.begin(), deck.end());                   // O(NlogN)
  ::DeckIncreasingRevealImpl(deck.begin(), deck.end());  // O(N^2)
  return deck;
}

}  // namespace algorithms
