#ifndef ASpell_HPP
#define ASpell_HPP

#include <string>

class ATarget;

class ASpell {
	private:
		ASpell(void);

	protected:
		std::string name_;
		std::string effects_;

	public:
		ASpell(const std::string& name, const std::string& effects);
		virtual ~ASpell(void);
		ASpell(const ASpell& src);
		ASpell& operator=(const ASpell& rhs);

		const std::string& getName(void) const;
		const std::string& getEffects(void) const;
		virtual ASpell* clone(void) const = 0;
		void launch(const ATarget& target) const;
};

#endif
