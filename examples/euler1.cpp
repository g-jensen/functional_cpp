#include "../src/core.cpp"
#include "../src/io.cpp"

int divisible_by_3_or_5(int n) {
  return n % 3 == 0 || n % 5 == 0;
}

int main() {
  prn(reduce(add<int>,filter(divisible_by_3_or_5,range(1,1000))));
}