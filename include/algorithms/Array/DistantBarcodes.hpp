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
#ifndef ALGORITHMS__ARRAY__DISTANTBARCODES__HPP
#define ALGORITHMS__ARRAY__DISTANTBARCODES__HPP
#include <vector>

namespace algorithms {

/*! \brief In a warehouse, there is a row of barcodes, where the i-th barcode is
 *  barcodes[i].
 *  Rearrange the barcodes so that no two adjacent barcodes are equal.
 *  You may return any answer, and it is guaranteed an answer exists.
 *
 *  \note  Complexity --> Time: O(NlogK)  Space: O(K)  (K === distinct nums)
 *  \note https://leetcode.com/problems/distant-barcodes/
 */
std::vector<int> DistantBarcodes(const std::vector<int>& barcodes);

}  // namespace algorithms

#endif  // ALGORITHMS__ARRAY__DISTANTBARCODES__HPP
