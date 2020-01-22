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
#ifndef ALGORITHMS__BINARY_INDEXED_TREE__BINARY_INDEXED_TREE__HPP
#define ALGORITHMS__BINARY_INDEXED_TREE__BINARY_INDEXED_TREE__HPP
#include <cassert>
#include <iterator>
#include <type_traits>
#include <vector>

namespace algorithms {

/*! \class BinaryIndexedTree
 *  \author Biagio Festa
 *  \brief This class implementes a Fenwick tree (or binary indexed tree).
 *         It is a data structure that can efficiently update elements and
 *         calculate prefix sums in a table of numbers.
 *  \note https://en.wikipedia.org/wiki/Fenwick_tree
 */
template <typename IntegerType = int>
class BinaryIndexedTree {
 public:
  static_assert(std::is_integral_v<IntegerType>);
  using value_type = IntegerType;

  /*! \brief Build a tree with `size` elements.
   *  All elements are zero initialized.
   */
  BinaryIndexedTree(const std::size_t size);

  /*! \brief Compute the prefix sum.
   *  It computes the sum of the elements in the array [0...index].
   *  `index`-th element is included in the sum.
   *  \note `index` must be less than size, otherwise undefined behavior.
   */
  value_type sum(std::size_t index) const noexcept;

  /*! \brief Compute the partial sum.
   *  In other words, it compute the sum of the elements in the array:
   *                 [i ... j]
   *  where the i-th and j-th elements are included in the sum.
   *  \note Both indices must be less than size, otherwise the behavior is
   *  undefined.
   */
  value_type partialSum(std::size_t i, std::size_t j) const noexcept;

  /*! \brief Update the value of a element in the array.
   *  \param [in] index   The index of the element.
   *  \param [in] delta   The delta (incremental update) to the new value.
   *  \note `index` must be less than size, otherwise the behaviour is
   *  undefined.
   */
  void update(std::size_t index, value_type delta) noexcept;

 private:
  std::vector<value_type> data_;

  static inline constexpr std::size_t lsb(const std::size_t i) noexcept {
    return i & (-i);
  }
};

template <typename IntegerType>
BinaryIndexedTree<IntegerType>::BinaryIndexedTree(const std::size_t size)
    : data_(size + 1) {}

template <typename IntegerType>
auto BinaryIndexedTree<IntegerType>::sum(std::size_t index) const noexcept
    -> value_type {
  value_type sum = 0;
  ++index;
  while (index) {
    assert(index < data_.size());
    sum += data_[index];
    index -= lsb(index);
  }
  return sum;
}

template <typename IntegerType>
auto BinaryIndexedTree<IntegerType>::partialSum(std::size_t i,
                                                std::size_t j) const noexcept
    -> value_type {
  return sum(j) - (i ? sum(i - 1) : 0);
}

template <typename IntegerType>
void BinaryIndexedTree<IntegerType>::update(std::size_t index,
                                            value_type delta) noexcept {
  ++index;
  while (index < data_.size()) {
    data_[index] += delta;
    index += lsb(index);
  }
}

}  // namespace algorithms

#endif  // ALGORITHMS__BINARY_INDEXED_TREE__BINARY_INDEXED_TREE__HPP
