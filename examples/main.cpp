#include "../src/core.cpp"
#include "../src/io.cpp"
#include <string>

std::string nope(int a)
{
  return "nope";
}

bool is_even(int a)
{
  return a % 2 == 0;
}

int main()
{
  prn("hello");
  prn(inc(3));
  prn(dec(3));
  auto v1 = std::vector<int>{1, 2, 3};
  prn("original vec:");
  prnv(v1);

  prn("map:");
  prnv(map(inc<int>, v1));
  prnv(map([](int a){ return a + 2; },v1));
  prnv(map(nope, v1));

  prn("filter:");
  prnv(filter(is_even, v1));
  prnv(filter([](int a){ return a % 2 == 1; },v1));

  prn("vector is unchanged:");
  prnv(v1);
}