/*
  Copyright (C) 2022  Biagio Festa

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
#include <algorithms/Trie/SimpleTrie.hpp>

namespace algorithms {

SimpleTrie::SimpleTrie() : data_(1), root_(&data_.front()) {}

void SimpleTrie::insert(const char* str) {
  auto [parent, index] = scanPrefix(str);
  char c;
  while ((c = str[index]) != '\0') {
    data_.emplace_back();
    parent->children_[static_cast<int>(c)] = &data_.back();
    parent = &data_.back();
    ++index;
  }
  parent->final_ = true;
}

bool SimpleTrie::find(const char* str) const {
  auto [node, index] = scanPrefix(str);
  return str[index] == '\0' && node->final_;
}

std::pair<SimpleTrie::Node*, std::size_t> SimpleTrie::scanPrefix(const char* str) const {
  std::pair<Node*, std::size_t> p{root_, 0};
  Node* next;

  while ((next = p.first->children_[static_cast<int>(str[p.second])])) {
    p.first = next;
    ++p.second;
  }

  return p;
}

}  // namespace algorithms
