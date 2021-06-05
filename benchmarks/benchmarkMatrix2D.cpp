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
#include <benchmark/benchmark.h>
#include <algorithm>
#include <algorithms/Matrix/Matrix2D.hpp>
#include <numeric>
#include <random>
#include <vector>

namespace {

using Type = int;
constexpr std::size_t N = 1024;
constexpr std::size_t M = 1024;

template <typename Matrix>
Type OnePassByRow(const Matrix& matrix) {
  Type acc{};
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < M; ++j) {
      acc += matrix[i][j];
    }
  }
  return acc;
}

template <typename Matrix>
Type OnePassByCol(const Matrix& matrix) {
  Type acc{};
  for (std::size_t j = 0; j < M; ++j) {
    for (std::size_t i = 0; i < N; ++i) {
      acc += matrix[i][j];
    }
  }
  return acc;
}

template <typename Matrix>
Type OnePassRnd(const Matrix& matrix, const std::vector<std::size_t>& indicesAccess) {
  Type acc{};
  for (const std::size_t index : indicesAccess) {
    acc += matrix[index / M][index % M];
  }
  return acc;
}

std::vector<std::size_t> GetRndAccessIndices() {
  std::vector<std::size_t> indices(N * M);
  std::iota(indices.begin(), indices.end(), 0);

  std::default_random_engine rndEngine(0);
  std::shuffle(indices.begin(), indices.end(), rndEngine);

  return indices;
}

}  // anonymous namespace

namespace algorithms::benchmark {

void BMMatrix2DMatrix2DOnePassByRow(::benchmark::State& state) {
  Matrix2D<Type, ::N, ::M> matrix(1);

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassByRow(matrix));
  }
}
BENCHMARK(BMMatrix2DMatrix2DOnePassByRow);

void BMMatrix2DNestVectorOnePassByRow(::benchmark::State& state) {
  std::vector<std::vector<Type>> matrix(::N, std::vector<Type>(::M, 1));

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassByRow(matrix));
  }
}
BENCHMARK(BMMatrix2DNestVectorOnePassByRow);

void BMMatrix2DMatrix2DOnePassByCol(::benchmark::State& state) {
  Matrix2D<Type, ::N, ::M> matrix(1);

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassByCol(matrix));
  }
}
BENCHMARK(BMMatrix2DMatrix2DOnePassByCol);

void BMMatrix2DNestVectorOnePassByCol(::benchmark::State& state) {
  std::vector<std::vector<Type>> matrix(::N, std::vector<Type>(::M, 1));

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassByCol(matrix));
  }
}
BENCHMARK(BMMatrix2DNestVectorOnePassByCol);

void BMMatrix2DMatrix2DOnePassRnd(::benchmark::State& state) {
  Matrix2D<Type, ::N, ::M> matrix(1);
  auto indicesAccess = ::GetRndAccessIndices();

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassRnd(matrix, indicesAccess));
  }
}
BENCHMARK(BMMatrix2DMatrix2DOnePassRnd);

void BMMatrix2DNestVectorOnePassRnd(::benchmark::State& state) {
  std::vector<std::vector<Type>> matrix(::N, std::vector<Type>(::M, 1));
  auto indicesAccess = ::GetRndAccessIndices();

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(::OnePassRnd(matrix, indicesAccess));
  }
}
BENCHMARK(BMMatrix2DNestVectorOnePassRnd);

}  // namespace algorithms::benchmark
