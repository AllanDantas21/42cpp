/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:19:53 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/27 15:57:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip> 
# include "Contact.hpp"

class Phonebook {
private:
    Contact contacts[8];
    int contactsCount;
    
public:
    Phonebook();
    void addContact();
    void searchContact();
};

#endif