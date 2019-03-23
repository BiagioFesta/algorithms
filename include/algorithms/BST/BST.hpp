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
#ifndef ALGORITHMS__BST__HPP
#define ALGORITHMS__BST__HPP
#include <cassert>
#include <stack>
#include <utility>

namespace algorithms {

/*! \brief This class implements a simple Binary Search Tree (BST).
 *  Simple common operation are implemented, such as insertion and lookup.
 *  \note https://en.wikipedia.org/wiki/Binary_search_tree
 */
template <typename T>
class BST {
 public:
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;

  //! \brief Default destructor. Free memory.
  ~BST();

  //! \brief Insert an value in the tree.
  void insertValue(value_type iValue);

  //! \return the number of nodes in the tree.
  int getSize() const noexcept;

  //! \return 'true' if the element is stored in the tree.
  bool isStored(const_reference iValue) const;

  //! Clean the tree. Remove all nodes and free memory.
  void clean();

 private:
  struct TreeNode {
    value_type _data;
    TreeNode* _left = nullptr;
    TreeNode* _right = nullptr;

    explicit TreeNode(value_type&& iData);
  };

  TreeNode* _root = nullptr;
  int _size = 0;
};

template <typename T>
int BST<T>::getSize() const noexcept {
  return _size;
}

template <typename T>
void BST<T>::insertValue(value_type iValue) {
  TreeNode* aPtrNode = _root;
  TreeNode** aEdgeToMod = &_root;
  while (aPtrNode != nullptr) {
    const bool aGoRight = aPtrNode->_data < iValue;
    aEdgeToMod = aGoRight ? &aPtrNode->_right : &aPtrNode->_left;
    aPtrNode = aGoRight ? aPtrNode->_right : aPtrNode->_left;
  }
  assert(*aEdgeToMod == nullptr);

  *aEdgeToMod = new TreeNode(std::move(iValue));

  ++_size;
}

template <typename T>
bool BST<T>::isStored(const_reference iValue) const {
  const TreeNode* aPtrNode = _root;
  while (aPtrNode != nullptr) {
    if (aPtrNode->_data == iValue) return true;
    aPtrNode = aPtrNode->_data < iValue ? aPtrNode->_right : aPtrNode->_left;
  }
  return false;
}

template <typename T>
BST<T>::TreeNode::TreeNode(value_type&& iData) : _data(std::move(iData)) {}

template <typename T>
void BST<T>::clean() {
  std::stack<TreeNode*> openList;
  if (_root) openList.push(_root);

  while (!openList.empty()) {
    TreeNode* aTop = openList.top();
    openList.pop();

    if (aTop->_left) openList.push(aTop->_left);
    if (aTop->_right) openList.push(aTop->_right);

    delete aTop;
  }

  _size = 0;
  _root = nullptr;
}

template <typename T>
BST<T>::~BST() {
  clean();
}

}  // namespace algorithms

#endif  // ALGORITHMS__BST__HPP
