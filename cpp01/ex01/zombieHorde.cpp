#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* Horde = new Zombie[N]; 
    
	  for (int i = 0; i < N; i++) {
        new (&Horde[i]) Zombie(name);
    }
    return Horde; 
}