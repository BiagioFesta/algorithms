/*
  Copyright (C) 2020  Biagio Festa

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
#ifndef ALGORITHMS__LRU_CACHE__HPP
#define ALGORITHMS__LRU_CACHE__HPP
#include <map>

namespace algorithms {

/*! \brief Design and implement a data structure for Least Recently Used (LRU)
 *  cache. It should support the following operations: `get` and `put`.
 *    - get(key): Get the value (will always be positive) of the key if the key
 *                exists in the cache, otherwise return -1.
 *    - put(key, value): Set or insert the value if the key is not already
 *                       present. When the cache reached its capacity, it should
 *                       invalidate the least recently used item before
 *                       inserting a new item.
 *
 *  \note https://leetcode.com/problems/lru-cache/
 */
class LRUCache {
 public:
  LRUCache(int capacity);

  ~LRUCache();

  /*! \brief Set/insert the value of the key, if present, otherwise add the key
   *  as the most recently used key. If the cache has reached its capacity, it
   *  should replace the least recently used key with a new key.
   */
  void set(const int key, const int value);

  /*! \brief Get the value (will always be positive) of the key if the key
   *  exists in the cache, otherwise return -1.
   *  \note Get refresh the key (as most recent used).
   */
  int get(const int key);

 private:
  struct Node {
    Node* _prev = nullptr;
    Node* _next = nullptr;
    int _key;
    int _val;

    Node(int key, int val) : _key(key), _val(val) {}
  };

  std::map<int, Node*> _map;
  int _capacity;
  Node* _head = nullptr;
  Node* _tail = nullptr;

  void refreshNode(Node* node);
  Node* allocateNewHead(int key, int value);
  void removeTail();
};

}  // namespace algorithms

#endif  // ALGORITHMS__LRU_CACHE__HPP
