#ifndef ATarget_HPP
#define ATarget_HPP

#include <string>

class ASpell;

class ATarget {
	private:
		ATarget(void);

	protected:
		std::string type_;

	public:
		ATarget(const std::string& type);
		virtual ~ATarget(void);
		ATarget(const ATarget& src);
		ATarget& operator=(const ATarget& rhs);

		const std::string& getType(void) const;
		virtual ATarget* clone(void) const = 0;
		void getHitBySpell(const ASpell& spell) const;
};

#endif
