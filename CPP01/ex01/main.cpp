/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:28:22 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:46:38 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie*	zombies;
	int N = 5;

	zombies = zombieHorde( N, "zombie" );
	delete [] zombies;
	
	return 0;
}
