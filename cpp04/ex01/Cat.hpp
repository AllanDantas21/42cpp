/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:58:52 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/02 22:22:31 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {

public:
    Cat();
    Cat(Cat const& src);
    ~Cat();

    Cat& operator=(Cat const& rhs);
    virtual void makeSound(void) const;
};

#endif 