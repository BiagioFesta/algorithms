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
#include <algorithms/CTCI/Chapter2/RemoveDuplicates.hpp>
#include <iterator>
#include <list>
#include <type_traits>
#include <unordered_set>

namespace algorithms {

void RemoveDuplicates(std::list<int>* ioList) {
  std::unordered_set<int> hashTable;

  auto iterator = ioList->begin();
  while (iterator != ioList->end()) {
    if (hashTable.insert(*iterator).second) {
      ++iterator;
    } else {
      iterator = ioList->erase(iterator);
    }
  }
}

void RemoveDuplicatesSpaceOptimized(std::list<int>* ioList) {
  using Iterator = decltype(ioList->begin());
  Iterator iterator, successive;

  iterator = ioList->begin();
  while (iterator != ioList->end()) {
    successive = std::next(iterator);

    while (successive != ioList->end()) {
      if (*iterator == *successive) {
        successive = ioList->erase(successive);
      } else {
        ++successive;
      }
    }

    ++iterator;
  }
}

}  // namespace algorithms
