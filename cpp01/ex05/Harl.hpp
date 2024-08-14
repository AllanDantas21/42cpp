/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:00:23 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/14 00:16:52 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl{
    private:
        void _debug( void );
        void _info( void );
        void _warning( void );
        void _error( void );
    public:
        Harl();
    	~Harl();
        void complain( std::string level );
};