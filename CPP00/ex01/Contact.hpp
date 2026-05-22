/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:42:27 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/22 13:53:13 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
	public:
		Contact( void );
		~Contact( void );
		
		void setContact( std::string firstName, 
			std::string lastName, std::string nickname,
			std::string phoneNumber, std::string darkestSecret );
		void printContact( int index );
		void printContactInfo( void );
	
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
