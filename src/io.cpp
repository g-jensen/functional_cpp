#include <iostream>
#include <vector>

template <class T>
void prn(T val) {
  std::cout << val << std::endl;
}

template <class T>
void prnv(std::vector<T> vec) {
  std::cout << '{';
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
    if (i != vec.size() - 1) std::cout << ',';
  }
  std::cout << '}' << std::endl;
};