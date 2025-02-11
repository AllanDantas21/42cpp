#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap(std::string name); 
        ~ScavTrap();
        void attack(std::string const & target);
        void guardGate();
    private:
        bool _guardMode;
};