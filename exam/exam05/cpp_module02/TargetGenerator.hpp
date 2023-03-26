#ifndef TargetGenerator_HPP
#define TargetGenerator_HPP

#include <string>
#include <list>

class ATarget;

class TargetGenerator {
	private:
		TargetGenerator(const TargetGenerator& src);
		TargetGenerator& operator=(const TargetGenerator& rhs);

		std::list<ATarget*> targets_;

	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void learnTargetType(ATarget* target);
		void forgetTargetType(const std::string& target);
		ATarget* createTarget(const std::string& target);

};

#endif
