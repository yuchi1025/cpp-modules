/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 09:53:22 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/29 16:51:40 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level )
{
    std::string levels[4];

    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    void (Harl::*functions[4])(void);

    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;

    int level_index = -1;

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            level_index = i;
            break;
        }
    }

    switch (level_index)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            (this->*functions[0])();
            std::cout << std::endl;

        case 1:
            std::cout << "[ INFO ]" << std::endl;
            (this->*functions[1])();
            std::cout << std::endl;

        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            (this->*functions[2])();
            std::cout << std::endl;

        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            (this->*functions[3])();
            std::cout << std::endl;
            break;

        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
