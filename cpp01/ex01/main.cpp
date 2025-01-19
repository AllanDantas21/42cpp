#include "Zombie.hpp"

int	main(void)
{
	int N = 5;

	Zombie *z = zombieHorde(N, "allan");
	for (int i = 0; i < N; i++)
		z->announce();
	delete[] z;
}
