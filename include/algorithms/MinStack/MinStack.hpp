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
#ifndef ALGORITHMS__MIN_STACK__HPP
#define ALGORITHMS__MIN_STACK__HPP
#include <functional>
#include <stack>
#include <utility>

namespace algorithms {

/*! \brief Design a stack that supports push, pop, top, and retrieving the
 *  minimum element in constant time.
 *  \note https://leetcode.com/problems/min-stack/
 */
template <typename T, typename Compare = std::less<T>>
class MinStack {
 public:
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;

  //! \note Complexity ->  Time: O(1)
  void push(value_type v);

  //! \note Complexity ->  Time: O(1)
  void pop();

  /*! \note Complexity ->  Time: O(1)
   *  \note Undefined behaviour if the container is empty.
   */
  const_reference top() const noexcept;

  /*! \return the minimum value in the MinStack.
   *  \note Undefined behaviour if the container is empty.
   *  \note Complexity ->  Time: O(1)
   */
  const_reference getMin() const;

  //! \return the size of the container.
  size_type size() const noexcept;

 private:
  std::stack<value_type> _data;
  std::stack<const value_type*> _mins;
};

template <typename T, typename Compare>
void MinStack<T, Compare>::push(value_type v) {
  _data.push(std::move(v));

  const auto& aTop = _data.top();
  if (_mins.empty() || Compare{}(aTop, *(_mins.top()))) {
    _mins.push(&aTop);
  }
}

template <typename T, typename Compare>
void MinStack<T, Compare>::pop() {
  if (_mins.top() == &_data.top()) {
    _mins.pop();
  }

  _data.pop();
}

template <typename T, typename Compare>
typename MinStack<T, Compare>::const_reference MinStack<T, Compare>::top() const noexcept {
  assert(_data.empty() == false);
  return _data.top();
}

template <typename T, typename Compare>
typename MinStack<T, Compare>::const_reference MinStack<T, Compare>::getMin() const {
  assert(_mins.empty() == false);
  return *(_mins.top());
}

template <typename T, typename Compare>
typename MinStack<T, Compare>::size_type MinStack<T, Compare>::size() const noexcept {
  return _data.size();
}

}  // namespace algorithms

#endif  // ALGORITHMS__MIN_STACK__HPP
