template <typename C>
typename C::iterator easyfind(C& container, int find) {
	typename C::iterator iter;

	iter = std::find(container.begin(), container.end(), find);
	if (iter == container.end()) {
		throw (std::runtime_error("Can't find value: " + std::to_string(find)));
	}
	return (iter);
}

template <typename C>
typename C::const_iterator easyfind(const C& container, int find) {
	typename C::const_iterator iter;

	iter = std::find(container.begin(), container.end(), find);
	if (iter == container.end()) {
		throw (std::runtime_error("Can't find value: " + std::to_string(find)));
	}
	return (iter);
}

