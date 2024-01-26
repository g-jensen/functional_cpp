#pragma once

#include <iostream>
#include <vector>
#include <map>

void prn() {
  std::cout << std::endl;
}

template <typename T, typename... Types>
void prn(T val, Types... vals) {
  std::cout << val << " ";
  prn(vals...);
}

template <class T>
void prnv(std::vector<T> vec) {
  std::cout << '[';
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
    if (i != vec.size() - 1) std::cout << ',';
  }
  std::cout << ']' << std::endl;
};

template <typename K, typename V>
void prnm(std::map<K,V> m) {
  size_t size = m.size();
  std::cout << '{';
  int i = 1;
  for (const auto& p : m) {
    std::cout << p.first << ":" << p.second;
    if (i != size) std::cout << ',';
    i++;
  }
  std::cout << '}' << std::endl;
}

template <typename T>
T read() {
  T in;
  std::cin >> in;
  return in;
}

std::string read_line() {
  std::string in;
  std::getline(std::cin,in);
  return in;
}