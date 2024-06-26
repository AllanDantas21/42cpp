/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 03:23:30 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/26 04:56:14 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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