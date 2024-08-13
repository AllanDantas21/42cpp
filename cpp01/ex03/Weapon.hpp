/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:18:42 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/13 19:08:20 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon{
    private:
        std::string _type;
    public:
        Weapon(std::string type): _type(type) {};
        const std::string &getType() const;
        void setType(const std::string &type); 
};

#endif