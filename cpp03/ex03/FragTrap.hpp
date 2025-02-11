#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include <iostream>
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
    	FragTrap(std::string name); 
        ~FragTrap();
        void highFivesGuys(void);
    
    unsigned int getHP(void) const;
    unsigned int getEP(void) const;
    unsigned int getAD(void) const;
};

#endif