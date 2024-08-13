/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:00:20 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/13 20:09:04 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::_debug(void)
{
    std::cout << "I love having extra bacon for my 
    7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put
    enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::_warning(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::_error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}