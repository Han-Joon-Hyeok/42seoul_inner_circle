#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <vector>
#include <list>
#include <ctime>

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
      for (T i = first; i != last; ++i) {
        T j = i;
        while (j != i && *j < *std::prev(j)) {
          std::iter_swap(j, std::prev(j));
          --j;
        }
      }
    }

    void vectorMergeInsertionSort(void);
    void recursiveVectorSort(std::vector<size_t>::iterator first, std::vector<size_t>::iterator last);

    void listMergeInsertionSort(void);
    void recursiveListSort(std::list<size_t>::iterator first, std::list<size_t>::iterator last);

    void printResult(std::clock_t start, std::clock_t end, const std::string& type);

    std::list<size_t>::const_iterator getListIterator(void) const;
    std::list<size_t>::const_iterator getListEndIterator(void) const;

    class InvalidInput : public std::exception {
      public:
        virtual const char* what(void) const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const PmergeMe& rhs);

#endif
