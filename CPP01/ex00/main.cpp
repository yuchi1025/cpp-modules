/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:54:27 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:42:50 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main( void )
{
	Zombie* newZ;

	randomChump("Random");
	std::cout << std::endl;

	newZ = newZombie("newZ");
	delete newZ;

	return 0;
}
