#ifndef Span_HPP
#define Span_HPP

#include <set>

class Span {
 private:
  Span(void);
  unsigned int max_size_;
  std::set<unsigned int> set_;

 public:
  Span(unsigned int n);
  Span(const Span& src);
  ~Span(void);
  Span& operator=(Span const& rhs);

  void addNumber(unsigned int n);

  template <typename InputIt>
  void addNumbers(InputIt first, InputIt last) {
    if (std::distance(first, last) + this->set_.size() > this->max_size_) {
      throw MaxSizeException();
    }
    for (InputIt it = first; it != last; ++it) {
      addNumber(*it);
    }
  }

  unsigned int shortestSpan(void);
  unsigned int longestSpan(void);
  class MaxSizeException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class UnableToSpanException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
