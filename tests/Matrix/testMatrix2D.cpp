/*
  Copyright (C) 2021  Biagio Festa

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
#include <gtest/gtest.h>
#include <algorithms/Matrix/Matrix2D.hpp>
#include <utility>

namespace {

using T = int;
constexpr std::size_t N = 20;
constexpr std::size_t M = 30;

}  // anonymous namespace

namespace algorithms::test {

TEST(Matrix2D, DefaultInit) {
  constexpr T initValue = 42;
  Matrix2D<T, N, M> matrix(initValue);

  ASSERT_EQ(matrix.kNumRows, N);
  ASSERT_EQ(matrix.kNumCols, M);

  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < M; ++j) {
      ASSERT_EQ(matrix[i][j], initValue);
      ASSERT_EQ(*matrix.getMutableValue(i, j), initValue);
      ASSERT_EQ(matrix.getValue(i, j), initValue);
    }
  }
}

TEST(Matrix2D, StoreAndLoad) {
  Matrix2D<T, N, M> matrix;
  T acc{};

  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < M; ++j) {
      matrix.setValue(i, j, ++acc);
      ASSERT_EQ(matrix[i][j], acc);
      ASSERT_EQ(std::as_const(matrix)[i][j], acc);
    }
  }
}

}  // namespace algorithms::test
