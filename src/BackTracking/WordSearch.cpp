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
#include <algorithm>
#include <algorithms/BackTracking/WordSearch.hpp>
#include <cassert>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace {

template <typename T>
bool IsMatrix(const std::vector<std::vector<T>>& iMatrix) {
  if (iMatrix.empty()) {
    return true;
  }
  const auto numCols = iMatrix.front().size();
  return std::all_of(
      iMatrix.cbegin(), iMatrix.cend(), [numCols](const auto& row) {
        return row.size() == numCols;
      });
}

using Pos = std::pair<int, int>;

bool WordSearchImpl(const std::vector<std::vector<char>>& iBoard,
                    const char* iWord,
                    const Pos iPos,
                    std::set<Pos>* iVisPos) {
  if (*iWord == '\0') {
    return true;
  }

  const auto [i, j] = iPos;
  const int numRows = iBoard.size();
  const int numCols = iBoard.front().size();
  if (i < 0 || j < 0 || i >= numRows || j >= numCols ||
      iVisPos->count(iPos) == 1 || iBoard[i][j] != *iWord) {
    return false;
  }

  iVisPos->insert(iPos);
  const bool result = WordSearchImpl(iBoard, iWord + 1, {i + 1, j}, iVisPos) ||
                      WordSearchImpl(iBoard, iWord + 1, {i - 1, j}, iVisPos) ||
                      WordSearchImpl(iBoard, iWord + 1, {i, j + 1}, iVisPos) ||
                      WordSearchImpl(iBoard, iWord + 1, {i, j - 1}, iVisPos);
  iVisPos->erase(iPos);
  return result;
}

}  // anonymous namespace

namespace algorithms {

bool WordSearch(const std::vector<std::vector<char>>& iBoard,
                const std::string& iWord) {
  assert(::IsMatrix(iBoard));

  if (iBoard.empty()) {
    return iWord.empty();
  }
  const auto numRows = iBoard.size();
  const auto numCols = iBoard.front().size();

  std::set<::Pos> visPos;
  for (std::size_t i = 0; i < numRows; ++i) {
    for (std::size_t j = 0; j < numCols; ++j) {
      if (::WordSearchImpl(iBoard, iWord.c_str(), {i, j}, &visPos)) {
        return true;
      }
    }
  }

  return false;
}

}  // namespace algorithms
