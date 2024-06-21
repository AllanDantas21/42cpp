/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:05:06 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/21 17:08:38 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int j = 1;
	int i = 0;
	char ch;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			ch = toupper(argv[j][i]);
			std::cout << ch;
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return (0);
}
