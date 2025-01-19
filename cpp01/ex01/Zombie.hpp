#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string _name;
  public:
	Zombie() {};
	Zombie(std::string name) : _name(name){};
	~Zombie();
	void announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif