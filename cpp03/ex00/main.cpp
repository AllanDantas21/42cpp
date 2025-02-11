#include "ClapTrap.hpp"

int main(){
    ClapTrap a("allan");
    ClapTrap b = a;
    a.attack("dantas");
    a.takeDamage(5);
    std::cout << "current Life: " << a.getLife() << "\n";
}