/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:04:08 by aldantas          #+#    #+#             */
/*   Updated: 2024/11/30 22:24:02 by aldantas         ###   ########.fr       */
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
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif