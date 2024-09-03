/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:58:52 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/03 00:36:04 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public AAnimal {

public:
    Cat();
    Cat(Cat const& src);
    ~Cat();

    Cat& operator=(Cat const& rhs);
    virtual void makeSound(void) const;
    Brain* getBrain(void) const;

private:
    Brain* _brain;
};

#endif 