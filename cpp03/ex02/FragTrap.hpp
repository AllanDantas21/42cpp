#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include <iostream>
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap();
    	FragTrap(std::string name); 
        ~FragTrap();
        void highFivesGuys(void);
};

#endif