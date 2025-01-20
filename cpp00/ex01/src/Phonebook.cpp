/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:22:56 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/20 15:47:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() {
    _contactsCount = 0;
}

bool Phonebook::isContactValid(const Contact& contact) const {
    return !contact.getFirstName().empty() && !contact.getLastName().empty() &&
           !contact.getNickname().empty() && !contact.getPhoneNumber().empty() &&
           !contact.getDarkestSecret().empty();
}

bool Phonebook::isValid(const std::string& field) const {
    return !field.empty();
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

    if (isContactValid(contact)) {
        contacts[_contactsCount] = contact;
        _contactsCount++;
    } else {
        std::cout << "Error: All fields must be filled." << std::endl;
    }
}

std::string formatField(const std::string& field) {
    return field.length() > 10 ? field.substr(0, 9) + "." : field;
}

void Phonebook::searchContact() {
    if (_contactsCount == 0) {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }

    std::cout << "     index|first name| last name|  nickname" << std::endl;
    for (int i = 0; i < _contactsCount; i++) {
        std::string firstName = contacts[i].getFirstName();
        std::string lastName = contacts[i].getLastName();
        std::string nickname = contacts[i].getNickname();

        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << formatField(firstName) << "|";
        std::cout << std::setw(10) << formatField(lastName) << "|";
        std::cout << std::setw(10) << formatField(nickname) << std::endl;
    }

    std::string index;
    std::cout << "Enter index: ";
    std::getline(std::cin, index);

    if (index.length() == 1 && index[0] >= '1' && index[0] <= '8') {
        int i = index[0] - '1';
        if (i < _contactsCount) {
            std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
            std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
            std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
            std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << std::endl;
        } else {
            std::cout << "Invalid index" << std::endl;
        }
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}