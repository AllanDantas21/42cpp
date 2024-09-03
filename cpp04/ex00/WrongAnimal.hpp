/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:30:31 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/02 22:42:53 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {

public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const& src);
    ~WrongAnimal();

    WrongAnimal& operator=(WrongAnimal const& other);
    const std::string getType(void) const;
    void setType(std::string type);
    void makeSound(void) const;

protected:
    std::string type;
};

#endif