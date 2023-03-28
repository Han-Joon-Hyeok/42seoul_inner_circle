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
      if (std::distance(first, it) > std::distance(first, insert_point)) {
        std::iter_swap(it, insert_point);
      }
    }
  }

  template <typename BidIt>
  void mergeAndSort(BidIt first, BidIt middle, BidIt last) {
    typedef typename BidIt::value_type value_type;
    typedef typename BidIt::difference_type difference_type;   // equal to std::ptrdiff_t(long)

    difference_type len1 = std::distance(first, middle);
    difference_type len2 = std::distance(middle, last);

    std::vector<value_type> v1(len1);
    std::vector<value_type> v2(len2);

    std::copy(first, middle, v1.begin());
    std::copy(middle, last, v2.begin());

    typename std::vector<value_type>::iterator it1 = v1.begin();
    typename std::vector<value_type>::iterator it2 = v2.begin();

    while (it1 != v1.end() && it2 != v2.end()) {
      if (*it1 < *it2) {
        *first++ = *it1++;
      } else {
        *first++ = *it2++;
      }
    }

    std::copy(it1, v1.end(), first);
    std::copy(it2, v2.end(), std::next(first, len1));
  }

  template <typename BidIt>
  void recursiveMergeInsertionSort(BidIt first, BidIt last) {
    if (std::distance(first, last) <= this->threshold_) {
      insertion_sort(first, last);
      return;
    }

    BidIt middle = first;
    std::advance(middle, std::distance(first, last) / 2);

    recursiveMergeInsertionSort(first, middle);
    recursiveMergeInsertionSort(middle, last);

    mergeAndSort(first, middle, last);
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
