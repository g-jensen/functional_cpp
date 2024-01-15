#include <functional>
#include <vector>
#include <type_traits>
#include <map>

template <typename T>
T inc(T val) {
  return val + 1;
}

template <typename T>
T dec(T val) {
  return val - 1;
}

template <typename Input, class Output>
auto map(Output f, std::vector<Input> v)
    -> std::vector<decltype(f(std::declval<Input>()))> {
  std::vector<decltype(f(std::declval<Input>()))> out(v.size());
  for (int i = 0; i < v.size(); i++)
    out[i] = f(v[i]);
  return out;
}

template <typename T, class Condition>
std::vector<T> filter(Condition f, std::vector<T> v) {
  std::vector<T> out;
  for (auto i : v)
    if (f(i))
      out.push_back(i);
  return out;
}

template <typename T>
std::vector<T> conj(std::vector<T> v, T val) {
  v.push_back(val);
  return v;
}

template <typename T>
std::vector<T> cons(std::vector<T> v, T val) {
  v.insert(v.begin(),val);
  return v;
}

template <typename T>
std::vector<T> assoc(std::vector<T> v, size_t idx, T val) {
  v[idx] = val;
  return v;
}

template <typename K, typename V>
std::map<K, V> assoc(std::map<K, V> m, K key, V value) {
  m[key] = value;
  return m;
}