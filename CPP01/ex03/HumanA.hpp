/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:46:07 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:48:05 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA();
		
		void attack( void );
		
	private:
		std::string name;
		Weapon& weaponREF;
};

#endif