#include "../src/core.cpp"
#include "../src/io.cpp"
#include "../src/str.cpp"

std::string nope(int a) {
  return "nope";
}

int add_three_nums(int a, int b, int c) {
  return a+b+c;
}

int main() {
  prn("hello");
  prn("bye","other thing",4);
  prn(inc(3));
  prn(dec(3));
  prn(nein(true));
  auto less_than_two = less_than<int>(2);
  prn(less_than_two(1));
  prn(less_than_two(2));
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

  prn("reduce:");
  prn(reduce(add<int>,v1));
  prn(reduce(sub<int>,v1));
  prn(reduce(mult<int>,v1));
  prn(reduce(div<int>,reverse(v1)));

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

  prn("drop:");
  prnv(drop(2,v1));

  prn("rest:");
  prnv(rest(v1));

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

  prn("partial:");
  auto filter_evens = partial(filter<int>,is_even<int>);
  prnv(filter_evens(v1));
  auto sum = partial(reduce<int>,add<int>);
  prn(sum(v1));

  // I don't know why anyone would do this,
  // but this is just to showcase how to partial a composition
  auto comp_count = partial(comp<std::vector<int>,std::vector<int>,int>,count<int>);
  auto reverse_and_count = comp_count(reverse<int>);
  prn(reverse_and_count(v1));

  prn("count:");
  prn(count(v1));

  prn("zipmap:");
  prnm(zipmap(v1,std::vector<std::string>{"hi","bye","nope"}));

  prn("map_indexed:");
  prnv(map_indexed([](int idx, std::string s){return std::to_string(idx) + ": " + s;},std::vector<std::string>{"hi","bye","nope"}));

  prn("filter_indexed:");
  prnv(filter_indexed([](int idx, int val){return is_even(idx) || is_even(val);},std::vector<int>{1,1,2,2,3,3}));

  prn("repeat:");
  prnv(repeat("hi",10));

  prn("iterate_while");
  prnv(iterate_while([](int a){return a < 5;},1,inc<int>));

  prn("vector is unchanged:");
  prnv(v1);

  prn("read_line: (enter to see str examples)");
  prn("input:",read_line());

  prn("str:");
  prn(str("hi", "n o", " yes"));
  prn(str(std::vector<std::string>{"sdflk"," aa","123"}));
  prn(str(std::vector<char>{'a',' ','b','c'}));

  prn("str_repeat:");
  prn(str_repeat("hi",5));
  prn(str_repeat('o',5));
}