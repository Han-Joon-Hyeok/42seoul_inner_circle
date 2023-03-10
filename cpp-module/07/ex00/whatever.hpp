#ifndef whatever_HPP
# define whatever_HPP

template <typename T>
void swap(T& x, T& y) {
  T temp = x;
  x = y;
  y = temp;
}

#endif
