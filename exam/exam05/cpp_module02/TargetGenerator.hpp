#ifndef TARGET_GENERATOR_HPP
#define TARGET_GENERATOR_HPP

#include <list>
#include "ATarget.hpp"

class TargetGenerator
{
public:
	TargetGenerator(void);
	~TargetGenerator(void);

	void learnTargetType(ATarget *target);
	void forgetTargetType(const std::string &type);
	ATarget *createTarget(const std::string &type);

private:
	std::list<ATarget *> targets_;
};

#endif
