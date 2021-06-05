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
#ifndef ALGORITHMS__FLAT_SET__HPP
#define ALGORITHMS__FLAT_SET__HPP
#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>
#include <utility>
#include <vector>

namespace algorithms {

/*! \class FlatSet
 *  \author Biagio Festa
 *  \brief FlatSet is an assosiative and sorted container (like a `std::set`).
 *  Differently from std::set, a FlatSet is implemented in a contiguos memory
 *  region in order to increase cache locality.
 */
template <typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>>
class FlatSet {
 public:
  using value_type = T;
  using allocator_type = Allocator;
  using size_type = std::size_t;
  using reference = value_type&;
  using pointer = typename std::allocator_traits<Allocator>::pointer;
  using internal_container = std::vector<value_type, allocator_type>;
  using iterator = typename internal_container::iterator;
  using const_iterator = typename internal_container::const_iterator;

  FlatSet() = default;

  explicit FlatSet(const Allocator& alloc);

  template <typename InputIt>
  FlatSet(InputIt first, InputIt last, const Allocator& alloc = Allocator());

  /*! \brief It inserts a value into the container.
   *  The continaer (like `std::set`) cannot contain the same value more than
   *  once.
   *  In case you try to insert the same value, no actual insertion will be
   *  performed.
   *  \return A pair:
   *    - In case the value is not already present in the container, the second
   *      element of the returned pair is `true`; the first element is the
   *      iterator to the object just inserted into the container.
   *    - In case the value is already present in the container, the second
   *      element of the returned pair is `falese`; the first element is the
   *      iterator to the object already stored into the container.
   *
   *  \note Complexity -> Time: O(logN) comparisons plus O(N) possible move.
   *           In short, O(N)
   *  \note In case of reallocation some iterators (past-end iterator included)
   *  will be invalidated.
   */
  std::pair<iterator, bool> insert(const value_type& iValue);
  std::pair<iterator, bool> insert(value_type&& iValue);

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  const_iterator cbegin() const noexcept;

  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cend() const noexcept;

  /*! \brief It returns an iterator the the searched element (or `end` iterator
   *  is not present).
   *  \note  Complexity ->  Time: O(logN)
   */
  iterator find(const value_type& iValue);
  const_iterator find(const value_type& iValue) const;

  //! \brief As `find`, but return boolean result.
  bool contains(const value_type& iValue) const;

  //! \return the number of elements with that value (1 or 0).
  size_type count(const value_type& iValue) const;

  //! \return 'true' if the container is empty
  bool empty() const noexcept;

  //! \return the number of elements stored into the container.
  size_type size() const noexcept;

  //! \brief (As `std::vector`) reserve capacity.
  void reserve(size_type iNewCapacity);

  //! \return the current capacity of the container.
  size_type capacity() const noexcept;

 private:
  internal_container _data;

  template <typename U>
  std::pair<iterator, bool> insert_impl(U&& iValue);
};

template <typename T, typename Compare, typename Allocator>
template <typename U>
auto FlatSet<T, Compare, Allocator>::insert_impl(U&& iValue) -> std::pair<iterator, bool> {
  Compare aComparator;
  auto aLwIt = std::lower_bound(_data.begin(), _data.end(), iValue, aComparator);
  if (aLwIt != _data.end() && !aComparator(iValue, *aLwIt)) {
    return std::make_pair(aLwIt, false);
  }
  return std::make_pair(_data.insert(aLwIt, std::forward<U>(iValue)), true);
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::insert(const value_type& iValue) -> std::pair<iterator, bool> {
  return insert_impl(iValue);
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::insert(value_type&& iValue) -> std::pair<iterator, bool> {
  return insert_impl(std::move(iValue));
}

template <typename T, typename Compare, typename Allocator>
bool FlatSet<T, Compare, Allocator>::empty() const noexcept {
  return _data.empty();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::find(const value_type& iValue) -> iterator {
  Compare aComparator;
  auto aLwIt = std::lower_bound(_data.begin(), _data.end(), iValue, aComparator);
  if (aLwIt != _data.end() && !aComparator(iValue, *aLwIt)) {
    return aLwIt;
  }
  return _data.end();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::find(const value_type& iValue) const -> const_iterator {
  Compare aComparator;
  auto aLwIt = std::lower_bound(_data.cbegin(), _data.cend(), iValue, aComparator);
  if (aLwIt != _data.end() && !aComparator(iValue, *aLwIt)) {
    return aLwIt;
  }
  return _data.end();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::begin() noexcept -> iterator {
  return _data.begin();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::begin() const noexcept -> const_iterator {
  return _data.begin();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::cbegin() const noexcept -> const_iterator {
  return _data.cbegin();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::end() noexcept -> iterator {
  return _data.end();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::end() const noexcept -> const_iterator {
  return _data.end();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::cend() const noexcept -> const_iterator {
  return _data.cend();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::size() const noexcept -> size_type {
  return _data.size();
}

template <typename T, typename Compare, typename Allocator>
void FlatSet<T, Compare, Allocator>::reserve(size_type iNewCapacity) {
  _data.reserve(iNewCapacity);
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::capacity() const noexcept -> size_type {
  return _data.capacity();
}

template <typename T, typename Compare, typename Allocator>
bool FlatSet<T, Compare, Allocator>::contains(const value_type& iValue) const {
  return find(iValue) != cend();
}

template <typename T, typename Compare, typename Allocator>
auto FlatSet<T, Compare, Allocator>::count(const value_type& iValue) const -> size_type {
  return contains(iValue) ? 1u : 0u;
}

template <typename T, typename Compare, typename Allocator>
template <typename InputIt>
FlatSet<T, Compare, Allocator>::FlatSet(InputIt first, InputIt last, const Allocator& alloc) : _data(alloc) {
  const auto kSize = std::distance(first, last);
  reserve(kSize);

  while (first != last) {
    insert(*first);
    ++first;
  }
}

template <typename T, typename Compare, typename Allocator>
FlatSet<T, Compare, Allocator>::FlatSet(const Allocator& alloc) : _data(alloc) {}

}  // namespace algorithms

#endif  // ALGORITHMS__FLAT_SET__HPP
