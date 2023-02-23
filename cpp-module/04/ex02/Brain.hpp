#ifndef BRAIN_HPP
#define BRAIN_HPP

#define NUMBER_OF_IDEA 100

#include <string>

class Brain {
 public:
	Brain(void);
	~Brain(void);
  Brain(const Brain& rhs);
  Brain& operator=(const Brain& rhs);

  std::string ideas[NUMBER_OF_IDEA];

  const std::string& getIdea(int idx) const;
  void  setIdea(int idx, const std::string& idea);
};

#endif
