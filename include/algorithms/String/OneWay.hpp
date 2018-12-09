/*
  Copyright (C) 2018  Biagio Festa

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
#ifndef ALGORITHMS__STRING__ONE_WAY__HPP
#define ALGORITHMS__STRING__ONE_WAY__HPP
#include <string>

namespace algorithms {

/*! \brief There are three types of edits that can be performed on strings:
 *  insert a character, remove a character, or replace a character. Given two
 *  strings, it checks if they are one edit (or zero edits) away.
 */
bool OneWay(const std::string& iStr1, const std::string& iStr2);

}  // namespace algorithms

#endif  // ALGORITHMS__STRING__ONE_WAY__HPP
