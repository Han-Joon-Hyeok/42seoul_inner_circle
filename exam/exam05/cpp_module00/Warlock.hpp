#ifndef Warlock_HPP
#define Warlock_HPP

#include <string>

class Warlock {
	private:
		Warlock(void);
		Warlock(const Warlock& src);
		Warlock& operator=(const Warlock& src);

		std::string name_;
		std::string title_;

	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock(void);

		const std::string& getName(void) const;
		const std::string& getTitle(void) const;
		void setTitle(const std::string& title);
		void introduce(void) const;
};

#endif
