#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <vector>
#include <list>

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

    void vectorMergeInsertionSort();
    void listMergeInsertionSort();

    class InvalidInput : public std::exception {
      public:
        virtual const char* what(void) const throw();
    };
};

#endif
