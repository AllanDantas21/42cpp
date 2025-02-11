#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include <iostream>

class ClapTrap
{
  protected:
	std::string  _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	int getLife(void);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
#endif