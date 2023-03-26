#include "TargetGenerator.hpp"
#include "ATarget.hpp"
#include <iostream>

TargetGenerator::TargetGenerator(void) {
}

TargetGenerator::~TargetGenerator(void) {
	std::list<ATarget*>::iterator it = targets_.begin();
	while (it != targets_.end()) {
		delete *it;
		it++;
	}
}

void TargetGenerator::learnTargetType(ATarget* target) {
	targets_.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const std::string& target) {
	std::list<ATarget*>::iterator it = targets_.begin();
	while (it != targets_.end()) {
		ATarget* find = *it;
		if (find->getType() == target) {
			targets_.erase(it);
			delete find;
			return ;
		}
		it++;
	}
}

ATarget* TargetGenerator::createTarget(const std::string& target) {
	std::list<ATarget*>::iterator it = targets_.begin();
	while (it != targets_.end()) {
		ATarget* find = *it;
		if (find->getType() == target) {
			return (find->clone());
		}
		it++;
	}
	return (NULL);
}
