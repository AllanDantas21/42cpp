#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        DiamondTrap tom("Thomas");
        std::cout << "Thomas AD: " << tom.getAD() << std::endl;
        std::cout << "Thomas HP: " << tom.getHP() << std::endl;
        std::cout << "Thomas EP: " << tom.getEP() << std::endl;
    }

    std::cout << std::endl;
    {
        DiamondTrap norb("Norbert");

        norb.attack("Jeremy");
        norb.getHP();
        // norb.takeDamage(25);
        // norb.takeDamage(18);
        // norb.attack("Valerie");
        // norb.attack("Cassie");
        // norb.attack("Victor");
        // norb.attack("Tristan");
        // norb.beRepaired(40);
        // norb.whoAmI();
        // norb.attack("Killian");
        // norb.highFivesGuys();
        // norb.takeDamage(8);
        // norb.attack("Dominic");
        // norb.highFivesGuys();
    }
    return (0);
}