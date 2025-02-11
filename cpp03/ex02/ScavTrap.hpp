#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name); 
        ~ScavTrap();
        void attack(std::string const & target);
        void guardGate();
    private:
        bool _guardMode;
};

#endif