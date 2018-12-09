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
#ifndef ALGORITHMS__MIN_STACK__HPP
#define ALGORITHMS__MIN_STACK__HPP
#include <algorithm>
#include <deque>
#include <stdexcept>
#include <utility>

namespace algorithms {

/*! \brief Design a stack that supports push, pop, top, and retrieving the
 *  minimum element in constant time.
 *  \note https://leetcode.com/problems/min-stack/
 */
template <typename T>
class MinStack {
 public:
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;

  //! \Complexity  Time O(1)
  void push(value_type v);

  //! \Complexity  Time O(N)
  void pop();

  /*! \Complexity  Time O(1)
   *  \note Undefined behaviour if the container is empty.
   */
  const_reference top() const noexcept;

  /*! \return the minimum value in the MinStack
   *  \throw in case the container is emtpy.
   *  \Complexity  Time O(1)
   */
  const_reference getMin() const;

 private:
  std::deque<value_type> _data;
  const value_type* _min = nullptr;
};

template <typename T>
void MinStack<T>::push(value_type v) {
  _data.push_back(std::move(v));

  if ((!_min) || (top() < *_min)) {
    _min = &top();
  }
}

template <typename T>
void MinStack<T>::pop() {
  _data.pop_back();

  const auto min = std::min_element(_data.cbegin(), _data.cend());
  if (min == _data.cend()) {
    _min = nullptr;
  } else {
    _min = &(*min);
  }
}

template <typename T>
typename MinStack<T>::const_reference MinStack<T>::top() const noexcept {
  assert(_data.empty() == false);
  return _data.back();
}

template <typename T>
typename MinStack<T>::const_reference MinStack<T>::getMin() const {
  if (_min == nullptr) {
    throw std::runtime_error("Empty container");
  }
  return *_min;
}

}  // namespace algorithms

#endif  // ALGORITHMS__MIN_STACK__HPP
