/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:39:01 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:49:27 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
	public:
		Weapon( std::string type );
		~Weapon();

		const std::string& getType( void ) const;
		void setType( std::string type );

	private:
		std::string type;
};

#endif