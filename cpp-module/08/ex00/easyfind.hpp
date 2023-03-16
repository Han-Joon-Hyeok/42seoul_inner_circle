#ifndef easyfind_HPP
#define easyfind_HPP

#include <algorithm>

template <typename C>
typename C::iterator easyfind(C& container, int find);

template <typename C>
typename C::const_iterator easyfind(const C& container, int find);

#include "easyfind.tpp"

#endif
