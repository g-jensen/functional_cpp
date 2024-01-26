#pragma once

#include "core.cpp"
#include <string>

std::string str() {
  return "";
}

template<typename... T>
std::string str(std::string s1, T... rest) {
  return s1 + str(rest...);
}

std::string str(std::vector<std::string> strs) {
  return reduce(str<std::string>,strs);
}

std::string str(std::vector<char> chars) {
  return std::string(chars.begin(),chars.end());
}
