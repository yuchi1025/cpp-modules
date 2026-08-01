/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:48:35 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/01 14:29:37 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Valid Form ===" << std::endl;
    try
    {
        Form tax("Tax", 50, 25);
        std::cout << tax << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Valid Boundaries ===" << std::endl;
    try
    {
        Form highest("Highest", 1, 1);
        Form lowest("Lowest", 150, 150);

        std::cout << highest << std::endl;
        std::cout << lowest << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Sign Grade too high ===" << std::endl;
    try
    {
        Form form1("InvalidHighSignGrade", 0, 50);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=== Sign Grade too low ===" << std::endl;
    try
    {
        Form form2("InvalidLowSignGrade", 151, 50);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Execute Grade too high ===" << std::endl;
    try
    {
        Form form3("InvalidHighExecuteGrade", 50, 0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=== Execute Grade too low ===" << std::endl;
    try
    {
        Form form4("InvalidLowExecuteGrade", 50, 151);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "=== Successful Sign ===" << std::endl;
    Bureaucrat y("Yuchi", 42);
    Form visa1("Visa1", 60, 50);
    Form visa2("Visa2", 42, 42);
    std::cout << visa1 << std::endl;
    std::cout << visa2 << std::endl;
    y.signForm(visa1);
    y.signForm(visa2);
    std::cout << visa1 << std::endl;
    std::cout << visa2 << std::endl;

    std::cout << "=== Failed Sign ===" << std::endl;
    Bureaucrat r("Remi", 50);
    Form form5("Form5", 42, 30);
    std::cout << form5 << std::endl;
    r.signForm(form5);
    std::cout << form5 << std::endl;

    std::cout << "=== Copy Constructor ===" << std::endl;
    y.signForm(form5);
    Form copy(form5);

    std::cout << form5 << std::endl;
    std::cout << copy << std::endl;

    std::cout << "=== Assignment Operator ===" << std::endl;
    Form first("First", 60, 10);
    Form second("Second", 100, 80);

    r.signForm(first);

    std::cout << "Before assignment:" << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;

    second = first;

    std::cout << "After assignment:" << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    return (0);
}

