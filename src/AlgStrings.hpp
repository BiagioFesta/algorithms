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
#ifndef ALGORITHMS__ALG_STRINGS__HPP
#define ALGORITHMS__ALG_STRINGS__HPP
#include <cstdint>
#include <cstring>
#include <string>

namespace algorithms {

/*! \brief  Given two strings, write a method to decide if one is a permutation
 *  of the other.
 *  \note Assumptions: case sensitive, white spaces make difference, ASCII
 *  coding.
 *  \complexity: Space = O(1)   Time = O(N + M)
 */
bool isPermutation(const char* iStr1, const char* iStr2);

/*! \brief It replaces all spaces in a string with '%20'.
 *  \note It assumes that the string has sufficient space at the end to hold the
 *  additional characters, and that you are given the "true" length of the
 *  string.
 *  \complexity: Space = O(1)   Time = O(N^2)
 */
void URLify(char* iStr, int iLenString);

/*! \brief It checks if it is a permutation of a palindrome.
 *  \note Assumptions: case sensitive, white spaces make difference, ASCII.
 *  \complexity: Space = O(1)   Time = O(N)
 */
bool palindromePermutation(const char* iStr);

/*! \brief There are three types of edits that can be performed on strings:
 *  insert a character, remove a character, or replace a character. Given two
 *  strings, it checks if they are one edit (or zero edits) away.
 */
bool oneWay(const std::string& iStr1, const std::string& iStr2);

/*! \brief It performs basic string compression using the counts
 *  of repeated characters. For example, the string aabcccccaaa would become
 *  2abc5c3a.
 *  \note If the "compressed" string does not fit the buffer in output, the
 *  method should return false and output will be trash data.
 *  \note It assumes the string contains only [A-Za-z] (no digits), othewise the
 *  result is ambiguos.
 */
bool stringCompression(const char* iStr, char* oBuffer, const int iSizeBuffer);

/*! \brief Given a string, find the length of the longest substring without
 *  repeating characters.
 */
int maxLenSubWithoutRep(const std::string& iString);

/*! \brief Given a string s consists of upper/lower-case alphabets and empty
 * space characters ' ', it returns the length of last word in the string.
 * \note If the last word does not exist, it returns 0.
 */
int lenLastWord(const char* iStr);

/*! \brief It counts the number of segments in a string, where a segment is
 *  defined to be a contiguous sequence of non-space characters.
 *  \note The string must not contain any non-printable character.
 *  \Complexity  Time O(N)   Space O(1)
 */
int countSegment(const char* iStr);

}  // namespace algorithms

#endif  // ALGORITHMS__ALG_STRINGS__HPP
