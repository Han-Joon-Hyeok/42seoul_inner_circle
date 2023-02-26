#include "TargetGenerator.hpp"
#include <iostream>

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void)
{
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	std::list<ATarget *>::iterator iter = targets_.begin();
	while (iter != targets_.end()) {
		ATarget *find = *iter;
		if (find == target) {
			return ;
		}
	}
	targets_.push_back(target);
}

void TargetGenerator::forgetTargetType(const std::string &type)
{
	std::list<ATarget *>::iterator iter = targets_.begin();
	while (iter != targets_.end()) {
		ATarget *find = *iter;
		if (find->getType() == type) {
			targets_.erase(iter);
			return ;
		}
	}
}

ATarget *TargetGenerator::createTarget(const std::string &type)
{
	std::list<ATarget *>::iterator iter = targets_.begin();
	while (iter != targets_.end()) {
		ATarget *find = *iter;
		if (find->getType() == type) {
			return (find->clone());
		}
	}
}
