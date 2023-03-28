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
        std::rotate(insert_point, it, std::next(it));
      }
    }
  }

  template <typename BidIt>
  void mergeAndSort(BidIt first, BidIt middle, BidIt last) {
    typedef typename std::iterator_traits<BidIt>::value_type value_type;
    typedef typename std::iterator_traits<BidIt>::difference_type difference_type;

    // Calculate the size of the left and right halves
    difference_type left_size = std::distance(first, middle);
    difference_type right_size = std::distance(middle, last);

    // Create temporary vectors to store the left and right halves of the range
    std::vector<value_type> left;
    std::vector<value_type> right;

    left.reserve(left_size);
    right.reserve(right_size);

    // Copy the left and right halves into the temporary vectors
    std::copy(first, middle, std::back_inserter(left));
    std::copy(middle, last, std::back_inserter(right));

    // Merge the left and right halves back into the original range
    typename std::vector<value_type>::iterator left_it = left.begin();
    typename std::vector<value_type>::iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            *first++ = *left_it++;
        } else {
            *first++ = *right_it++;
        }
    }

    // Copy leftovers to the origin container
    if (left_it != left.end()) {
      std::copy(left_it, left.end(), first);
    }

    if (right_it != right.end()) {
      std::copy(right_it, right.end(), first);
    }
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
