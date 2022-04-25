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
#ifndef ALGORITHMS__MATRIX__MATRIX2D__HPP
#define ALGORITHMS__MATRIX__MATRIX2D__HPP
#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

namespace algorithms {

/*! \class Matrix2D
 *  \author Biagio FESTA
 *  \brief 2D Matrix with sizes known at compile time.
 *  This class is supposed to be a better alternative to
 *  `std::vector<std::vector<T>>`.
 */
template <typename T, std::size_t N, std::size_t M = N>
class Matrix2D {
 public:
  using value_type = T;
  static constexpr std::size_t kNumRows = N;
  static constexpr std::size_t kNumCols = M;

  /*! \brief Initialize the matrix (allocating all the memory) with a init
   *  value.
   */
  Matrix2D(const value_type& initValue = value_type{});

  //! \return the value given (i, j).
  const value_type& getValue(const std::size_t i, const std::size_t j) const noexcept;

  //! \brief set the value given (i, j).
  void setValue(const std::size_t i,
                const std::size_t j,
                value_type value) noexcept(noexcept(std::is_nothrow_move_assignable_v<value_type>));

  //! \return the value given (i, j) as mutable pointer.
  value_type* getMutableValue(const std::size_t i, const std::size_t j) noexcept;

 private:
  static constexpr std::size_t kDataSize = kNumRows * kNumCols;
  using DataContainer = std::vector<value_type>;

  DataContainer data_;

  static std::size_t GetLinearIndex(const std::size_t i, const std::size_t j) noexcept {
    assert(i * kNumCols + j < kDataSize);
    return i * kNumCols + j;
  }

  class RowAccessor {
   public:
    value_type& operator[](const std::size_t j) noexcept {
      assert(j < kNumCols);
      return rowData_[j];
    }

   private:
    explicit RowAccessor(value_type* rowData) noexcept : rowData_(rowData) {}
    value_type* const rowData_;
    friend Matrix2D;
  };

  class ConstRowAccessor {
   public:
    const value_type& operator[](const std::size_t j) const noexcept {
      assert(j < kNumCols);
      return rowData_[j];
    }

   private:
    explicit ConstRowAccessor(const value_type* const rowData) noexcept : rowData_(rowData) {}
    const value_type* const rowData_;
    friend Matrix2D;
  };

 public:
  RowAccessor operator[](const std::size_t i) noexcept {
    assert(i < kNumRows);
    return RowAccessor(data_.data() + (i * kNumCols));
  }

  ConstRowAccessor operator[](const std::size_t i) const noexcept {
    assert(i < kNumRows);
    return ConstRowAccessor(data_.data() + (i * kNumCols));
  }
};

template <typename T, std::size_t N, std::size_t M>
Matrix2D<T, N, M>::Matrix2D(const value_type& initValue) : data_(kDataSize, initValue) {}

template <typename T, std::size_t N, std::size_t M>
auto Matrix2D<T, N, M>::getValue(const std::size_t i, const std::size_t j) const noexcept -> const value_type& {
  return data_[GetLinearIndex(i, j)];
}

template <typename T, std::size_t N, std::size_t M>
void Matrix2D<T, N, M>::setValue(const std::size_t i,
                                 const std::size_t j,
                                 value_type value) noexcept(noexcept(std::is_nothrow_move_assignable_v<value_type>)) {
  data_[GetLinearIndex(i, j)] = std::move(value);
}

template <typename T, std::size_t N, std::size_t M>
auto Matrix2D<T, N, M>::getMutableValue(const std::size_t i, const std::size_t j) noexcept -> value_type* {
  return &(data_[GetLinearIndex(i, j)]);
}

}  // namespace algorithms

#endif  // ALGORITHMS__MATRIX__MATRIX2D__HPP
