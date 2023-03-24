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

    std::list<ssize_t>::const_iterator getListIterator(void) const;
    std::list<ssize_t>::const_iterator getListEndIterator(void) const;

    class InvalidInput : public std::exception {
      public:
        virtual const char* what(void) const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const PmergeMe& rhs);

#endif
