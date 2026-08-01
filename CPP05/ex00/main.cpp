/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:48:35 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/01 13:37:51 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Valid constructor ===" << std::endl;
    Bureaucrat y("Yuchi", 42);
    std::cout << y << std::endl;
    std::cout << y.getName() << std::endl;
    std::cout << y.getGrade() << std::endl;
    std::cout << "=== Increase grade ===" << std::endl;
    y.increGrade();
    std::cout << y << std::endl;
    std::cout << "=== Decrease grade ===" << std::endl;
    y.decreGrade();
    std::cout << y << std::endl;

    std::cout << "=== Copy constructor ===" << std::endl;
    Bureaucrat c(y);
    std::cout << y << std::endl;
    std::cout << c << std::endl;

    std::cout << "=== Assignment operator ===" << std::endl;
    Bureaucrat r("Remi", 100);

    std::cout << "Before assignment:" << std::endl;
    std::cout << y << std::endl;
    std::cout << r << std::endl;

    r = y;
    std::cout << "After assignment:" << std::endl;
    std::cout << y << std::endl;
    std::cout << r << std::endl;

    std::cout << "=== Increase at the highest grade ===" << std::endl;
    try
    {
        Bureaucrat s("Seb", 1);
        s.increGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Decrease at the lowest grade ===" << std::endl;
    try
    {
        Bureaucrat j("John", 150);
        j.decreGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Grade too high ===" << std::endl;
    try
    {
        Bureaucrat m("Mark", 0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Grade too low ===" << std::endl;
    try
    {
        Bureaucrat a("AK", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

