/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:22:56 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 23:42:24 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() {
    _contactsCount = 0;
}

void Phonebook::addContact() {
    Contact contact;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    if (_contactsCount == 8) {
        for (int i = 0; i < _contactsCount - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        _contactsCount--;
    }

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    contact.setFirstName(firstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    contact.setLastName(lastName);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    contact.setNickname(nickname);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    contact.setPhoneNumber(phoneNumber);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    contact.setDarkestSecret(darkestSecret);

    contacts[_contactsCount] = contact;
    _contactsCount++;
}

void Phonebook::searchContact() {
    if (_contactsCount == 0) {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }

    std::cout << "     index|first name| last name|  nickname" << std::endl;
    for (int i = 0; i < _contactsCount; i++) {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << contacts[i].getFirstName().substr(0, 10) << "|";
        std::cout << std::setw(10) << contacts[i].getLastName().substr(0, 10) << "|";
        std::cout << std::setw(10) << contacts[i].getNickname().substr(0, 10) << std::endl;
    }

    std::string index;
    std::cout << "Enter index: ";
    std::getline(std::cin, index);

    if (index.length() == 1 && index[0] >= '1' && index[0] <= '8') {
        int i = index[0] - '1';
        std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
        std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
        std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}