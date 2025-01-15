#include "src/Phonebook.hpp"

int main() {
    Phonebook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
    return 0;
}