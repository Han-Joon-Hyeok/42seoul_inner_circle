#ifndef whatever_HPP
# define whatever_HPP

template <typename T>
void swap(T& x, T& y) {
  T temp = x;
  x = y;
  y = temp;
}

template <typename T>
T min(T x, T y) {
  if (x > y) {
    return (y);
  }
  return (x);
}

template <typename T>
T max(T x, T y) {
  if (x > y) {
    return (x);
  }
  return (y);
}

#endif
