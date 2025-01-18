#include "Zombie.hpp"

int	main(void) {
	std::string str = "Allan";
	Zombie zom(str);
	Zombie *newZomb;

	zom.announce();
	newZomb = newZombie("Potato");
	newZomb->announce();
	randomChump("PotatoTwo");
	delete newZomb;
}