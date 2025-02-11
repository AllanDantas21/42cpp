#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name); 
        ~ScavTrap();
        void attack(std::string const & target);
        void guardGate();

        unsigned int getHP(void) const;
        unsigned int getEP(void) const;
        unsigned int getAD(void) const;
    private:
        bool _guardMode;
};

#endif