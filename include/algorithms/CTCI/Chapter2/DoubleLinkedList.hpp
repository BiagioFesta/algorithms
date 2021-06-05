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
#ifndef ALGORITHMS__CTCI__CHAPTER_2__DOUBLE_LINKED_LIST__HPP
#define ALGORITHMS__CTCI__CHAPTER_2__DOUBLE_LINKED_LIST__HPP
#include <cassert>
#include <utility>

namespace algorithms {

/*! \class DoubleLinkedList
 *  \brief This class represents a container. In particular, it abstracts a
 *  doubly linked list data structure.
 */
template <typename T>
class DoubleLinkedList final {
 public:
  using value_type = T;
  using const_reference = const value_type&;
  using size_type = std::size_t;

  //! \brief Default constructore. Initializes an empty list.
  DoubleLinkedList() = default;

  /*! \brief Destructor. Call `clean`.
   *  \see clean.
   */
  ~DoubleLinkedList();

  //! \brief Initializes the list copying values from another sequence.
  template <typename InputIt>
  DoubleLinkedList(InputIt first, InputIt last);

  //! \brief Copy Constructor.
  DoubleLinkedList(const DoubleLinkedList& oth);

  //! \brief Assignment operator.
  DoubleLinkedList& operator=(const DoubleLinkedList& oth);

  //! \brief Move Constructor.
  DoubleLinkedList(DoubleLinkedList&& oth) noexcept;

  //! \brief Move operator.
  DoubleLinkedList& operator=(DoubleLinkedList&& oth) noexcept;

  /*! \brief Insert an element (by copying) at the end of the list.
   *  \note  Complexity ->  Time: O(1)
   */
  void push_back(const value_type& iValue);

  /*! \brief Insert an element (by moving) at the end of the list.
   *  \note  Complexity ->  Time: O(1)
   */
  void push_back(value_type&& iValue);

  /*! \brief Get the element at the i-th index (index starts from zero).
   *  \note The behaviour is undefined if the index requested is greater or
   *  equal than the size of the container.
   *  \note   Complexity ->  Time: O(iIndex)
   */
  const_reference getByIndex(const size_type iIndex) const;

  /*! \return the size of the container.
   *  \note  Complexity -> Time: O(1)
   */
  size_type size() const noexcept;

  /*! \brief Destroy all objects inside the container.
   *  After this call the container is empty.
   *  \note  Complexity -> Time: O(N) where N is the size.
   */
  void clean();

 private:
  struct Node {
    value_type _data;
    Node* _next;
    Node* _prev;

    Node(const value_type& iDate, Node* iNext, Node* iPrev);
    Node(value_type&& iData, Node* iNext, Node* iPrev);
  };

  Node* _root = nullptr;
  size_type _size = 0ull;

  template <typename U>
  void push_back_impl(U&& iValue);

  Node* getLastValidNode() const;
};

template <typename T>
void DoubleLinkedList<T>::push_back(const value_type& iValue) {
  push_back_impl(iValue);
}

template <typename T>
void DoubleLinkedList<T>::push_back(value_type&& iValue) {
  push_back_impl(std::move(iValue));
}

template <typename T>
template <typename U>
void DoubleLinkedList<T>::push_back_impl(U&& iValue) {
  Node* lastNode = getLastValidNode();
  if (lastNode == nullptr) {
    _root = new Node(std::forward<U>(iValue), nullptr, nullptr);
  } else {
    assert(lastNode->_next == nullptr);
    lastNode->_next = new Node(std::forward<U>(iValue), nullptr, lastNode);
  }
  ++_size;
}

template <typename T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::getLastValidNode() const {
  Node* current = _root;
  while (current != nullptr && current->_next != nullptr) {
    current = current->_next;
  }
  return current;
}

template <typename T>
typename DoubleLinkedList<T>::const_reference DoubleLinkedList<T>::getByIndex(const size_type iIndex) const {
  const Node* current = _root;
  for (size_type i = 0ull; i < iIndex; ++i) {
    assert(current != nullptr);
    current = current->_next;
  }

  assert(current != nullptr);
  return current->_data;
}

template <typename T>
typename DoubleLinkedList<T>::size_type DoubleLinkedList<T>::size() const noexcept {
  return _size;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  clean();
}

template <typename T>
void DoubleLinkedList<T>::clean() {
  const Node* current = _root;
  const Node* toDelete;
  while (current != nullptr) {
    toDelete = current;
    current = current->_next;
    delete toDelete;
  }
  _size = 0ull;
}

template <typename T>
template <typename InputIt>
DoubleLinkedList<T>::DoubleLinkedList(InputIt first, InputIt last) {
  while (first != last) {
    push_back(*first);
    ++first;
  }
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList& oth) {
  for (std::size_t i = 0; i < oth.size(); ++i) {
    push_back(oth.getByIndex(i));
  }
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList& oth) {
  clean();

  for (std::size_t i = 0; i < oth.size(); ++i) {
    push_back(oth.getByIndex(i));
  }

  return *this;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList&& oth) noexcept : _root(oth._root), _size(oth._size) {
  oth._root = nullptr;
  oth._size = 0ull;
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(DoubleLinkedList&& oth) noexcept {
  clean();
  _root = oth._root;
  _size = oth._size;
  oth._root = nullptr;
  oth._size = 0ull;

  return *this;
}

template <typename T>
DoubleLinkedList<T>::Node::Node(value_type&& iData, Node* iNext, Node* iPrev)
    : _data(std::move(iData)), _next(iNext), _prev(iPrev) {}

template <typename T>
DoubleLinkedList<T>::Node::Node(const value_type& iData, Node* iNext, Node* iPrev)
    : _data(iData), _next(iNext), _prev(iPrev) {}

}  // namespace algorithms

#endif  // ALGORITHMS__CTCI__CHAPTER_2__DOUBLE_LINKED_LIST__HPP
