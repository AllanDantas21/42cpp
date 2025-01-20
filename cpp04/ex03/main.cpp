#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void learnMaterias(IMateriaSource *src) {
    std::cout << "Learning Materia: Ice" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    std::cout << "Learning Materia: Cure" << std::endl;
    src->learnMateria(new Cure());
}

void equipMaterias(ICharacter *character, IMateriaSource *src) {
    AMateria *tmp1 = src->createMateria("ice");
    AMateria *tmp2 = src->createMateria("cure");

    std::cout << "Equipping Materia: ice" << std::endl;
    character->equip(tmp1);
    std::cout << "Equipping Materia: cure" << std::endl;
    character->equip(tmp2);
}

void useMaterias(ICharacter *user, ICharacter *target) {
    std::cout << "Using Materia: ice on target" << std::endl;
    user->use(0, *target);
    std::cout << "Using Materia: cure on target" << std::endl;
    user->use(1, *target);
    std::cout << "Using Materia: slot 2 on target" << std::endl;
    user->use(2, *target);
}

void cleanup(ICharacter *character, IMateriaSource *src, AMateria *tmp1, AMateria *tmp2) {
    std::cout << "Deleting character" << std::endl;
    delete character;
    std::cout << "Deleting src" << std::endl;
    delete src;
    std::cout << "Deleting tmp1" << std::endl;
    delete tmp1;
    std::cout << "Deleting tmp2" << std::endl;
    delete tmp2;
}

int main() {
    std::cout << "Creating MateriaSource" << std::endl;
    IMateriaSource *src = new MateriaSource();
    learnMaterias(src);

    std::cout << "Creating Character: me" << std::endl;
    ICharacter *me = new Character("me");
    equipMaterias(me, src);

    std::cout << "Creating Character: bob" << std::endl;
    ICharacter *bob = new Character("bob");

    useMaterias(me, bob);

    std::cout << "Assigning me to bob" << std::endl;
    *bob = *me;
    std::cout << "Unequipping Materia: slot 1" << std::endl;
    bob->unequip(1);
    std::cout << "Unequipping Materia: slot 0" << std::endl;
    bob->unequip(0);
    std::cout << "Equipping Materia: cure" << std::endl;
    bob->equip(src->createMateria("cure"));
    useMaterias(bob, me);

    useMaterias(me, bob);

    cleanup(me, NULL, NULL, NULL);

    return 0;
}
