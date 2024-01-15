#include "../src/core.cpp"
#include "../src/io.cpp"
#include <string>

std::string nope(int a) {
  return "nope";
}

int main() {
  prn("hello");
  prn("bye","other thing",4);
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
  prnv(filter(is_even<int>, v1));
  prnv(filter([](int a){ return a % 2 == 1; },v1));

  prn("apply:");
  prn(apply(add<int>,v1));
  prn(apply(sub<int>,v1));
  prn(apply(mult<int>,v1));
  prn(apply(div<int>,reverse(v1)));

  prn("every:");
  prn(every(is_even<int>, v1));
  prn(every(is_even<int>, map([](int a){return a*2;},v1)));

  prn("any:");
  prn(any(is_even<int>, v1));
  prn(any(is_odd<int>, map([](int a){return a*2;},v1)));

  prn("cons, conj:");
  prnv(conj(v1,4));
  prnv(cons(v1,0));

  prn("first, last:");
  prn(first(v1));
  prn(last(v1));

  prn("assoc vec:");
  prnv(assoc(v1,0,2));

  prn("assoc map:");
  std::map<int,std::string> map;
  auto m2 = assoc(map,0,std::string("hi"));
  prnm(assoc(m2,5,std::string("hello")));

  prn("dissoc map:");
  prnm(dissoc(m2,5));

  prn("comp:");
  auto not_odd = comp(is_odd<int>,inc<int>);
  prn(not_odd(1));
  prn(not_odd(2));

  prn("range:");
  prnv(range(-2,10));

  prn("reverse:");
  prnv(reverse(v1));

  prn("constantly:");
  auto five = constantly(5);
  prn(five());

  prn("identity:");
  prn(identity("hi"));

  prn("count:");
  prn(count(v1));

  prn("vector is unchanged:");
  prnv(v1);
}