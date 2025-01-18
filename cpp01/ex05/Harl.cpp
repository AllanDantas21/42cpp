#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level) {
        std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

        void (Harl::*functions[4])(void) = {
            &Harl::_debug,
            &Harl::_info,
            &Harl::_warning,
            &Harl::_error
        };

        for (int i = 0; i < 4; ++i) {
            if (levels[i] == level) {
                (this->*functions[i])();
                return;
            }
        };

        std::cout << "Probably complaining about insignificant problems \n";
    }

void Harl::_debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do! \n";
}

void Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! \n";
}

void Harl::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month \n";}

void Harl::_error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now. \n";
}