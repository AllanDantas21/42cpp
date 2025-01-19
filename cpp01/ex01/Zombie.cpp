#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "goodbye!" << '\n';
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << '\n';
}