#pragma once

#include "core.cpp"
#include <string>

std::string inline str() {
  return "";
}

template<typename... T>
std::string inline str(std::string s1, T... rest) {
  return s1 + str(rest...);
}

std::string inline str(std::vector<std::string> strs) {
  return reduce(str<std::string>,strs);
}

std::string inline str(std::vector<char> chars) {
  return std::string(chars.begin(),chars.end());
}

std::string inline str_repeat(std::string val, size_t count) {
  return str(repeat(val,count));
}

std::string inline str_repeat(char val, size_t count) {
  return str(repeat(val,count));
}

std::vector<std::string> inline str_split(std::string s, char delimiter) {
    std::vector<std::string> out;
    std::string str = "";
    for (char c : s) {
        if (c == delimiter) {
            out.push_back(str);
            str.clear();
        } else {
            str += c;
        }
    }
    out.push_back(str);
    return out;
}