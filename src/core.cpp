#include <functional>
#include <vector>
#include <type_traits>
#include <map>
#include <algorithm>

template <typename T>
T identity(T v) {
  return v;
}

template <typename T>
auto constantly(T v) {
  return [v](){ return v; };
}

template <class F, class T>
auto partial(F f, T val) {
  return [f,val](auto arg){ return f(val,arg); };
}

template <typename Output, typename A, typename B>
auto partial(std::function<Output(A,B)> f, A val) {
  return [f,val](auto arg){ return f(val,arg); };
}


template <typename T>
bool is_even(T a) {
  return a % 2 == 0;
}

template <typename T>
bool is_odd(T a) {
  return a % 2 == 1;
}

template <typename T>
T inc(T val) {
  return val + 1;
}

template <typename T>
T dec(T val) {
  return val - 1;
}

template <typename T>
T add(T x, T y) {
  return x+y;
}

template <typename T>
T sub(T x, T y) {
  return x-y;
}

template <typename T>
T mult(T x, T y) {
  return x*y;
}

template <typename T>
T div(T x, T y) {
  return x/y;
}

template <class F, class G>
auto comp(F f, G g) {
  return [f,g](auto b){ return f(g(b)); };
}
// f:a->b, g:b->c, g o f: a->c
template <typename A, typename B, typename C>
auto comp(std::function<C(B)> g, std::function<B(A)> f) {
  return [f,g](auto b){ return g(f(b)); };
}

template <typename T>
T first(std::vector<T> v) {
  return v[0];
}

template <typename T>
T last(std::vector<T> v) {
  return v[v.size()-1];
}

template <typename T>
size_t count(std::vector<T> v) {
  return v.size();
}

template <typename T>
bool is_empty(std::vector<T> v) {
  return count(v) == 0;
}

std::vector<int> range(int start, int end) {
  std::vector<int> out;
  for (int i = start; i < end; i++) {
    out.push_back(i);
  }
  return out;
}

template <typename T>
std::vector<T> reverse(std::vector<T> v) {
  std::reverse(v.begin(),v.end());
  return v;
}

template <typename Input, class Output>
auto map(std::function<Output(const Input)> f, std::vector<Input> v) {
  std::vector<Output>out(v.size());
  for (int i = 0; i < v.size(); i++)
    out[i] = f(v[i]);
  return out;
}

template <typename Input, class Output>
auto map(Output f, std::vector<Input> v) {
  std::vector<decltype(f(std::declval<Input>()))>out(v.size());
  for (int i = 0; i < v.size(); i++)
    out[i] = f(v[i]);
  return out;
}

template <typename T>
std::vector<T> filter(std::function<bool(const T)> f, std::vector<T> v) {
  std::vector<T> out;
  for (auto i : v)
    if (f(i))
      out.push_back(i);
  return out;
}

template <typename T, class Output>
std::vector<T> filter(Output f, std::vector<T> v) {
  std::vector<T> out;
  for (auto i : v)
    if (f(i))
      out.push_back(i);
  return out;
}

template <typename T>
T reduce(std::function<T(const T, const T)> f, std::vector<T> v) {
  if (is_empty(v)) return T(NULL);
  T out = v[0];
  for (int i = 1; i < v.size(); i++)
    out = f(out,v[i]);
  return out;
}

template <typename T, class Output>
T reduce(Output f, std::vector<T> v) {
  if (is_empty(v)) return T(NULL);
  T out = v[0];
  for (int i = 1; i < v.size(); i++)
    out = f(out,v[i]);
  return out;
}

template <typename T>
bool every(std::function<bool(const T)> f, std::vector<T> v) {
  for (auto i : v)
    if (!f(i))
      return false;
  return true;
}

template <typename T, class Output>
bool every(Output f, std::vector<T> v) {
  for (auto i : v)
    if (!f(i))
      return false;
  return true;
}

template <typename T>
bool any(std::function<bool(const T)> f, std::vector<T> v) {
  for (auto i : v)
    if (f(i))
      return true;
  return false;
}

template <typename T, class Output>
bool any(Output f, std::vector<T> v) {
  for (auto i : v)
    if (f(i))
      return true;
  return false;
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

template <typename K, typename V>
std::map<K, V> dissoc(std::map<K, V> m, K key) {
  m.erase(key);
  return m;
}