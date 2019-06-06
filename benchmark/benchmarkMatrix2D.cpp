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
#include <benchmark/benchmark.h>
#include <algorithms/Matrix/Matrix2D.hpp>
#include <vector>

namespace {

using Type = int;
constexpr std::size_t N = 1000;
constexpr std::size_t M = 1000;

template <typename Matrix>
Type OnePassByRow(const Matrix& matrix,
                  const std::size_t n,
                  const std::size_t m) {
  Type acc{};

  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < m; ++j) {
      acc += matrix[i][j];
    }
  }

  return acc;
}

template <typename Matrix>
Type OnePassByCol(const Matrix& matrix,
                  const std::size_t n,
                  const std::size_t m) {
  Type acc{};

  for (std::size_t j = 0; j < m; ++j) {
    for (std::size_t i = 0; i < n; ++i) {
      acc += matrix[i][j];
    }
  }

  return acc;
}

}  // anonymous namespace

namespace algorithms::benchmark {

void BMMatrix2DMatrix2DOnePassByRow(::benchmark::State& state) {
  Matrix2D<Type, ::N, ::M> matrix(1);

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassByRow(matrix, ::N, ::M));
  }
}
BENCHMARK(BMMatrix2DMatrix2DOnePassByRow);

void BMMatrix2DNestVectorOnePassByRow(::benchmark::State& state) {
  std::vector<std::vector<Type>> matrix(::N, std::vector<Type>(::M, 1));

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassByRow(matrix, ::N, ::M));
  }
}
BENCHMARK(BMMatrix2DNestVectorOnePassByRow);

void BMMatrix2DMatrix2DOnePassByCol(::benchmark::State& state) {
  Matrix2D<Type, ::N, ::M> matrix(1);

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassByCol(matrix, ::N, ::M));
  }
}
BENCHMARK(BMMatrix2DMatrix2DOnePassByCol);

void BMMatrix2DNestVectorOnePassByCol(::benchmark::State& state) {
  std::vector<std::vector<Type>> matrix(::N, std::vector<Type>(::M, 1));

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassByCol(matrix, ::N, ::M));
  }
}
BENCHMARK(BMMatrix2DNestVectorOnePassByCol);

}  // namespace algorithms::benchmark
