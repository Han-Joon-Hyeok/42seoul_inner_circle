#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <vector>
#include <list>
#include <ctime>

class PmergeMe
{
  private:
    std::vector<ssize_t> vector_;
    std::list<ssize_t> list_;

    PmergeMe(void);
  public:
    PmergeMe(int argc, char** argv);
    PmergeMe(const PmergeMe& src);
    ~PmergeMe(void);
    PmergeMe& operator=(PmergeMe const& rhs);

    bool hasDuplicatedNumber(std::list<ssize_t> list);

    template <typename T>
    void insertion_sort(T first, T last) {
      for (T i = first; i != last; ++i) {
        T j = i;
        while (j != i && *j < *(j - 1)) {
          std::swap(*j, *(j - 1));
          --j;
        }
      }
    }

    void vectorMergeInsertionSort(void);
    void listMergeInsertionSort(void);

    void printResult(std::clock_t start, std::clock_t end, const std::string& type);

    std::list<ssize_t>::const_iterator getListIterator(void) const;
    std::list<ssize_t>::const_iterator getListEndIterator(void) const;

    class InvalidInput : public std::exception {
      public:
        virtual const char* what(void) const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const PmergeMe& rhs);

#endif
