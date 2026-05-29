/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:25:15 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:45:29 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	public:
		Zombie( void );
		~Zombie( void );
		
		void	setName( std::string name );
		void	announce( void );
		
	private:
		std::string _name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif