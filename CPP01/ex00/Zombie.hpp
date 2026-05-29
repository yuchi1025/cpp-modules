/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:18:58 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:44:18 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	public:
		Zombie( std::string name );
		~Zombie( void );
		
		void announce( void );
		
	private:
		std::string name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
