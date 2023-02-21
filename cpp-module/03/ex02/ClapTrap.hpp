#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

#include <string>

class ClapTrap {
 private:
  std::string type_;
  std::string name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;

 public:
	ClapTrap(void);
  ClapTrap(std::string name);
	~ClapTrap(void);
  ClapTrap(const ClapTrap& rhs);
  ClapTrap& operator=(const ClapTrap& rhs);

	void setType(std::string type);
	std::string getType(void) const;

	void setName(std::string name);
	std::string getName(void) const;

  void setHitPoints(unsigned int amount);
  unsigned int getHitPoints(void) const;

  void setEnergyPoints(unsigned int amount);
  unsigned int getEnergyPoints(void) const;

  void setAttackDamage(unsigned int amount);
  unsigned int getAttackDamage(void) const;

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
