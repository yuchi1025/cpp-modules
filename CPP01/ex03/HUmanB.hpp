/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUmanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:47:12 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:48:31 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string name );
		~HumanB();

		void attack( void );
		void setWeapon( Weapon& weapon );
		
	private:
		std::string name;
		Weapon* weaponPTR;
};

#endif