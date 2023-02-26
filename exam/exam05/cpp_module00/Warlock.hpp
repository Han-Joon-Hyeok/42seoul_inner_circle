#include <string>

class Warlock {
	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock(void);

		const std::string& getName(void) const;
		const std::string& getTitle(void) const;
		void setTitle(const std::string& title);
		void	introduce(void) const;

	private:
		Warlock(void);

		std::string name_;
		std::string title_;
};
