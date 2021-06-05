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
#ifndef ALGORITHMS__STRING__STEADY_GENE__HPP
#define ALGORITHMS__STRING__STEADY_GENE__HPP
#include <string>

namespace algorithms {

/*! \brief A gene is represented as a string of lenght n (where n is divisible
 *  by 4), composed of the letters A, C, T, G. It is considered to be steady if
 *  each of the four letters occurs exaclty n/4 times. The algorithm takes as
 *  input a gene which may be steady or not.
 *  \return the smallest possible substring to replace in the input gene to
 *  make a steady gene.
 *  \note https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
 */
int SteadyGene(const std::string& gene);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__STEADY_GENE__HPP
