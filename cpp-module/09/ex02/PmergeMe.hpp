#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <ctime>
#include <iostream>
#include <list>
#include <vector>

class PmergeMe {
 private:
  std::vector<size_t> vector_;
  std::list<size_t> list_;
  int threshold_;

  PmergeMe(void);

 public:
  PmergeMe(int argc, char** argv);
  PmergeMe(const PmergeMe& src);
  ~PmergeMe(void);
  PmergeMe& operator=(PmergeMe const& rhs);

  template <typename T>
  void insertion_sort(T first, T last) {
    for (T it = std::next(first); it != last; ++it) {
      T insert_point = std::upper_bound(first, it, *it);
      if (it != insert_point) {
        std::rotate(insert_point, it, std::next(it));
      }
    }
  }

  template <typename BidIt>
  void recursiveMergeInsertionSort(BidIt begin, BidIt end) {
    if (std::distance(begin, end) <= this->threshold_) {
      insertion_sort(begin, end);
      return;
    }

    BidIt middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);

    recursiveMergeInsertionSort(begin, middle);
    recursiveMergeInsertionSort(middle, end);

    std::inplace_merge(begin, middle, end);
  }

  template <typename C>
  void mergeInsertionSort(C& container) {
    recursiveMergeInsertionSort(container.begin(), container.end());
  }

  template <typename C>
  std::string showElements(C& container) {
    typedef typename C::iterator iterator;

    iterator it = container.begin();
    std::string result;
    for (; it != container.end(); ++it) {
      result += std::to_string(*it) + " ";
    }
    return (result);
  }

  std::vector<size_t> getVector(void);
  std::list<size_t> getList(void);

  void printResult(std::clock_t start, std::clock_t end,
                   const std::string& type);

  class InvalidInput : public std::exception {
   public:
    virtual const char* what(void) const throw();
  };
};

#endif
