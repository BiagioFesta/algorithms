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
#include <algorithms/BackTracking/RestoreIPAddresses.hpp>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace {

constexpr std::size_t kNumFieldsIp = 4ull;
constexpr char kIpCharSep = '.';
constexpr std::size_t kSizeFieldMax = 3ull;

void RestoreIPAddressImpl(std::string_view s,
                          std::vector<std::string_view>* fields,
                          std::vector<std::string>* ips) {
  if (s.empty() && fields->size() == kNumFieldsIp) {
    std::string ip;
    for (std::size_t i = 0; i < kNumFieldsIp; ++i) {
      if (i != 0) ip += kIpCharSep;
      ip += (*fields)[i];
    }
    ips->push_back(std::move(ip));
  } else if (fields->size() < kNumFieldsIp) {
    for (std::size_t i = 0; i < kSizeFieldMax; ++i) {
      if (i < s.size()) {
        const auto field = s.substr(0, i + 1);
        const int num = std::stoi(std::string(field.data(), field.size()));
        if (num < 256) {
          fields->push_back(field);
          RestoreIPAddressImpl(s.substr(i + 1), fields, ips);
          fields->pop_back();
          if (num == 0) {
            break;
          }
        }
      }
    }
  }
}

}  // anonymous namespace

namespace algorithms {

std::vector<std::string> RestoreIPAddresses(const std::string& s) {
  std::vector<std::string_view> fields;
  std::vector<std::string> ips;
  ::RestoreIPAddressImpl(s, &fields, &ips);
  return ips;
}

}  // namespace algorithms
