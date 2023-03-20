#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack {
 public:
  typedef typename Container::value_type 				value_type;
  typedef typename Container::reference 				reference;
  typedef typename Container::const_reference 	const_reference;
  typedef typename Container::size_type 				size_type;
  typedef					 Container 										container_type;

 protected:
  Container c;

 public:
  MutantStack(void);
  MutantStack(const MutantStack<T>& src);
  ~MutantStack(void);
  MutantStack<T, Container>& operator=(MutantStack<T> const& rhs);

  // Member functions
  bool empty(void) const;
  size_type size(void) const;
  value_type& top(void);
  const T& top(void) const;
  void push(const T& value);
  void pop(void);

  // Iterator
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
};

#include "MutantStack.tpp"

#endif
