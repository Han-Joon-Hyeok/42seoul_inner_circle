#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <vector>
#include <list>
#include <ctime>
#include <iostream>

class PmergeMe
{
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

    bool hasDuplicatedNumber(std::list<size_t> list);

    template <typename T>
    void insertion_sort(T first, T last) {
      for (T it = std::next(first); it != last; ++it) {
        T insert_point = std::upper_bound(first, it, *it);
        if (it != insert_point) {
          std::rotate(insert_point, it, std::next(it));
        }
      }
    }

    void vectorMergeInsertionSort(void);
    void recursiveVectorSort(std::vector<size_t>::iterator first, std::vector<size_t>::iterator last);
    std::string showVector(void);

    void listMergeInsertionSort(void);
    void recursiveListSort(std::list<size_t>::iterator first, std::list<size_t>::iterator last);
    std::string showList(void);

    void printResult(std::clock_t start, std::clock_t end, const std::string& type);

    class InvalidInput : public std::exception {
      public:
        virtual const char* what(void) const throw();
    };
};

#endif
