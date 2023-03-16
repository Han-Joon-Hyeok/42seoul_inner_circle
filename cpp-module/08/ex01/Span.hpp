#ifndef Span_HPP
# define Span_HPP

#include <vector>

class Span
{
	private:
		Span(void);
		unsigned int size_;
		std::vector<unsigned int> vec_;

	public:
		Span(unsigned int n);
		Span(const Span& src);
		~Span(void);
		Span& operator=(Span const& rhs);

		void addNumber(unsigned int n);

		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
};

#endif
