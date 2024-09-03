/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:04:08 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/03 00:40:58 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string _ideas[100];
    
public:
    Brain();
    Brain(Brain const& src);
    ~Brain();

    Brain& operator=(Brain const& other);
    void getIdea() const;
};

#endif