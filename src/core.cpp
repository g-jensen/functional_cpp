#include <functional>
#include <vector>
#include <type_traits>
#include <map>
#include <algorithm>

template <typename T>
T cond(bool cond, T success, T failure) {
  if (cond)
    return success;
  else
    return failure;
}

template <typename T>
T when(bool cond, T success) {
  if (cond)
    return success;
  else
    return T(NULL);
}

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

template <typename T>
bool is_even(T a) {
  return a % 2 == 0;
}

template <typename T>
bool is_odd(T a) {
  return a % 2 == 1;
}

template <typename T>
bool positive(T a) {
  return a > 0;
}

template <typename T>
bool negative(T a) {
  return a < 0;
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
T first(T* v) {
  return v[0];
}

template <typename T>
T last(std::vector<T> v) {
  return v[v.size()-1];
}

template <typename T>
T last(T* v, size_t size) {
  return v[size-1];
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
std::vector<Output> map(std::function<Output(const Input)> f, std::vector<Input> v) {
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

template <typename K, typename V>
std::map<K, V> zipmap(std::vector<K> keys, std::vector<V> vals) {
  std::map<K,V> out;
  if (keys.size() != vals.size()) {return out;}
  for (int i = 0; i < keys.size(); i++) {
    out.insert(std::pair(keys[i],vals[i]));
  }
  return out;
}

template <typename Input, class Output>
std::vector<Output> map_indexed(std::function<Output(const size_t, const Input)> f, std::vector<Input> v) {
  std::vector<Output>out(v.size());
  for (size_t i = 0; i < v.size(); i++)
    out[i] = f(i,v[i]);
  return out;
}

template <typename Input, class Output>
auto map_indexed(Output f, std::vector<Input> v) {
  std::vector<decltype(f(std::declval<size_t>(),std::declval<Input>()))>out(v.size());
  for (size_t i = 0; i < v.size(); i++)
    out[i] = f(i,v[i]);
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
std::vector<T> filter_indexed(std::function<bool(size_t,const T)> f, std::vector<T> v) {
  std::vector<T> out;
  for (size_t i = 0; i < v.size(); i++)
    if (f(i,v[i]))
      out.push_back(v[i]);
  return out;
}

template <typename T, class Output>
std::vector<T> filter_indexed(Output f, std::vector<T> v) {
  std::vector<T> out;
  for (size_t i = 0; i < v.size(); i++)
    if (f(i,v[i]))
      out.push_back(v[i]);
  return out;
}

template <class F>
void repeatedly(F f, size_t n) {
  for (int i = 0; i < n; i++)
    f();
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
bool every(std::function<bool(const T)> f, T* v, size_t size) {
  for (int i = 0; i < size; i++)
    if (!f(v[i]))
      return false;
  return true;
}

template <typename T, class Output>
bool every(Output f, T* v, size_t size) {
  for (int i = 0; i < size; i++)
    if (!f(v[i]))
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
bool any(std::function<bool(const T)> f, T* v, size_t size) {
  for (int i = 0; i < size; i++)
    if (f(v[i]))
      return true;
  return false;
}

template <typename T, class Output>
bool any(Output f, T* v, size_t size) {
  for (int i = 0; i < size; i++)
    if (f(v[i]))
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