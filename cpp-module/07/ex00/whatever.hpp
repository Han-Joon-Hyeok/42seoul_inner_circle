#ifndef whatever_HPP
# define whatever_HPP

template <typename T>
void swap(T& x, T& y) {
  T temp = x;
  x = y;
  y = temp;
}

template <typename T>
T min(const T& x, T& y) {
  if (y > x) {
    return (x);
  }
  return (y);
}

template <typename T>
T max(const T& x, const T& y) {
  if (x > y) {
    return (x);
  }
  return (y);
}

#endif
