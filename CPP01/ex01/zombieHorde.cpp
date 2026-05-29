/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:26:26 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:45:45 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;
		
	Zombie* zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
    {
		zombies[i].setName(name);
        zombies[i].announce();
    }

	return zombies;
}
