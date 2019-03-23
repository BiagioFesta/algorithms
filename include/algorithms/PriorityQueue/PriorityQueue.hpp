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
#ifndef ALGORITHMS__PRIORITY_QUEQUE__HPP
#define ALGORITHMS__PRIORITY_QUEQUE__HPP
#include <cmath>
#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

namespace algorithms {

/*! \class PriorityQueue
 *  \brief Implement a priority queue data structure.
 *  \note https://en.wikipedia.org/wiki/Priority_queue
 */
template <typename T, typename Comparator = std::less<T>>
class PriorityQueue {
 public:
  using value_type = T;
  using value_compare = Comparator;
  using container_type = std::vector<T>;

  /*! \brief Insert a new element inside the container.
   *  \Complexity  Time: O(logN)
   */
  void push(value_type iValue);

  /*! \brief Get a reference to the top value.
   *  This is a max-heap. The top value is the greatest element in the queue.
   *  \note The behaviour is undefined is the container is empty.
   *  \Complexity   Time: O(1)
   */
  const value_type& top() const noexcept;

  /*! \brief Delete the top element (the greatest).
   *  \Complexity:   Time: O(logN)
   */
  void pop();

  //! \return the size of the container.
  int size() const noexcept;

  //! \return 'true' whether the container is empty.
  bool empty() const noexcept;

 private:
  container_type _data;

  //! \Complexity Time: O(logN)
  void upHeapify(int iIndexNode);

  //! \Complexity Time: O(logN)
  void downHeapify(int iIndexNode);

  //! \Complexity Time: O(1)
  inline int getParentIndex(int iIndexNode) const noexcept;

  //! \Complexity Time: O(1)
  inline int getLeftChildIndex(int iIndexNode) const noexcept;
};

template <typename T, typename Comparator>
int PriorityQueue<T, Comparator>::size() const noexcept {
  return static_cast<int>(_data.size());
}

template <typename T, typename Comparator>
bool PriorityQueue<T, Comparator>::empty() const noexcept {
  return _data.empty();
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::push(value_type iValue) {
  const int aIndex = size();
  _data.push_back(std::move(iValue));
  upHeapify(aIndex);
}

template <typename T, typename Comparator>
const typename PriorityQueue<T, Comparator>::value_type&
PriorityQueue<T, Comparator>::top() const noexcept {
  return _data.front();
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::pop() {
  if (_data.size() > 1) {
    std::swap(_data[0], _data[_data.size() - 1]);
    _data.pop_back();
    downHeapify(0);
  } else {
    _data.pop_back();
  }
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::upHeapify(int iIndexNode) {
  value_compare aCompare;
  int aParentIndex = getParentIndex(iIndexNode);

  while (iIndexNode > 0 && aCompare(_data[aParentIndex], _data[iIndexNode])) {
    std::swap(_data[iIndexNode], _data[aParentIndex]);
    iIndexNode = aParentIndex;
    aParentIndex = getParentIndex(iIndexNode);
  }
}

template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::downHeapify(int iIndexNode) {
  const int kSize = static_cast<int>(_data.size());

  value_compare aCompare;
  int aLeft = getLeftChildIndex(iIndexNode);
  int aRight = aLeft + 1;
  int aMaxIndexChild;

  while (aLeft < kSize) {
    aMaxIndexChild = aLeft;
    if (aRight < kSize && _data[aLeft] < _data[aRight]) {
      aMaxIndexChild = aRight;
    }

    if (aCompare(_data[iIndexNode], _data[aMaxIndexChild])) {
      std::swap(_data[iIndexNode], _data[aMaxIndexChild]);
      iIndexNode = aMaxIndexChild;
      aLeft = getLeftChildIndex(iIndexNode);
      aRight = aLeft + 1;
    } else {
      aLeft = kSize;
    }
  }
}

template <typename T, typename Comparator>
int PriorityQueue<T, Comparator>::getParentIndex(int iIndexNode) const
    noexcept {
  return (iIndexNode - 1) / 2;
}

template <typename T, typename Comparator>
int PriorityQueue<T, Comparator>::getLeftChildIndex(int iIndexNode) const
    noexcept {
  return iIndexNode * 2 + 1;
}

}  // namespace algorithms

#endif  // ALGORITHMS__PRIORITY_QUEQUE__HPP
