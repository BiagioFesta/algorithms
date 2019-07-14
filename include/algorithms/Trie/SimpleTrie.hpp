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
#ifndef ALGORITHMS__TRIE__SIMPLETRIE__HPP
#define ALGORITHMS__TRIE__SIMPLETRIE__HPP
#include <list>
#include <utility>

namespace algorithms {

/*! \class SimpleTrie
 *  \brief This class is a simple implementation of a Trie data-structure.
 *  \note https://en.wikipedia.org/wiki/Trie
 */
class SimpleTrie final {
 public:
  //! \brief Default constructor.
  SimpleTrie();

  //! \brief Inserts a string into the trie.
  void insert(const char* str);

  //! \brief Search for a string into the trie.
  bool find(const char* str) const;

  //! \brief It cannot be copied.
  SimpleTrie(SimpleTrie&) = delete;

  //! \brief It cannot be copied.
  SimpleTrie& operator=(const SimpleTrie&) = delete;

  //! \brief It cannot be moved.
  SimpleTrie(SimpleTrie&& rhs) = delete;

  //! \brief It cannot be moved.
  SimpleTrie& operator=(SimpleTrie&& rhs) = delete;

 private:
  static constexpr std::size_t kAlphabetSize = 1 << 8;

  struct Node final {
    Node* children_[kAlphabetSize] = {};
    bool final_ = false;
  };

  std::list<Node> data_;
  Node* root_;

  std::pair<Node*, std::size_t> scanPrefix(const char* str) const;
};

}  // namespace algorithms

#endif  // ALGORITHMS__TRIE__SIMPLETRIE__HPP
