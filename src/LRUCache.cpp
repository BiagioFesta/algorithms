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
#include "LRUCache.hpp"
#include <cassert>
#include <map>

namespace algorithms {

LRUCache::LRUCache(int capacity) : _capacity(capacity) {}

int LRUCache::get(const int key) {
  const auto finder = _map.find(key);
  if (finder == _map.cend()) return -1;

  Node* node = finder->second;
  assert(node->_key == key);

  refreshNode(node);

  return node->_val;
}

void LRUCache::set(const int key, const int value) {
  auto& node = _map[key];
  if (node) {
    node->_val = value;
    refreshNode(node);
  } else {
    node = allocateNewHead(key, value);
    if (static_cast<int>(_map.size()) > _capacity) {
      removeTail();
    }
  }
}

void LRUCache::refreshNode(Node* node) {
  if (_head != node) {
    Node* prev = node->_prev;
    Node* next = node->_next;

    assert(prev->_next == node);
    prev->_next = next;

    if (next) {
      assert(next->_prev == node);
      next->_prev = prev;
    } else {
      _tail = prev;
    }

    _head->_prev = node;
    node->_prev = nullptr;
    node->_next = _head;
    _head = node;
  }
}

LRUCache::Node* LRUCache::allocateNewHead(int key, int value) {
  Node* node = new Node(key, value);
  node->_next = _head;
  if (_head) {
    _head->_prev = node;
  }
  _head = node;

  if (_tail == nullptr) {
    _tail = _head;
  }

  return node;
}

void LRUCache::removeTail() {
  Node* newTail = _tail->_prev;
  if (newTail) {
    newTail->_next = nullptr;
  } else {
    _head = nullptr;
  }

  _map.erase(_tail->_key);
  delete _tail;

  _tail = newTail;
}

}  // namespace algorithms
