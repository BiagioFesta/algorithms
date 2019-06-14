#!/bin/env bash


echo "--------------------------------------------------"
echo "Interactive Script for Template Problem Generation"

getDir() {
    SOURCE="${BASH_SOURCE[0]}"
    while [ -h "$SOURCE" ]; do
        DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
        SOURCE="$(readlink "$SOURCE")"
        [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
    done
    DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
}

readProblemName() {
    read -r -p "Problem Name (function name) [ENTER]: " problemName
    read -r -p "Problem Name '${problemName}' correct? [y/N]: " response
    case "$response" in
        [yY])
            echo "Name confirmed!"
            ;;
        *)
            echo "Generation aborted"
            exit -1
    esac
}

readProblemType() {
    typeList=$(ls src/)
    echo "List of problem types:"
    for t in $typeList; do
        echo "   $t"
    done
    read -r -p "Problem Type [ENTER]:" problemType
    read -r -p "Problem Type '${problemType}' correct? [y/N]: " response
    case "$response" in
        [yY])
            echo "Type confirmed!"
            ;;
        *)
            echo "Generation aborted"
            exit -1
    esac
}

genCpp() {
    fileCpp="src/${problemType}/${problemName}.cpp"
    touch ${fileCpp}
    echo "/*
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
#include <algorithms/${problemType}/${problemName}.hpp>

namespace algorithms {

Type ${problemName}() {

}

}  // namespace algorithms" > ${fileCpp}

}

genHpp() {
    fileHpp="include/algorithms/${problemType}/${problemName}.hpp"
    touch ${fileHpp}
    echo "/*
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
#ifndef ALGORITHMS__${problemType^^}__${problemName^^}__HPP
#define ALGORITHMS__${problemType^^}__${problemName^^}__HPP

namespace algorithms {

Type ${problemName}()

}  // namespace algorithms

#endif  // ALGORITHMS__${problemType^^}__${problemName^^}__HPP" > ${fileHpp}

}

genTest() {
    fileTest="test/${problemType}/test${problemName}.cpp"
    touch ${fileTest}
    echo "/*
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
#include <gtest/gtest.h>
#include <algorithms/${problemType}/${problemName}.hpp>
#include <vector>

namespace algorithms::test {

TEST(${problemType}, ${problemName}) {
  using Test = ...
  const std::vector<Test> testCases = ...

  for (const auto& [...] : testCases) {

  }
}

}  // namespace algorithms::test " > ${fileTest}

}

#  ---- main ----


(getDir &&
     echo "Current Directory: ${DIR}" &&
     readProblemName &&
     echo "Problem Name: ${problemName}!" &&
     cd ${DIR}/.. &&
     readProblemType &&
     genCpp &&
     genHpp &&
     genTest)
