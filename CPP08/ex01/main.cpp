/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 10:37:24 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/08 14:06:09 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "Span.hpp"

int main()
{
    std::cout << "=== Subject example ===" << std::endl;

    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest(2): " << sp.shortestSpan() << std::endl;
    std::cout << "Longest(14): " << sp.longestSpan() << std::endl;

    std::cout << "=== Two numbers ===" << std::endl;

    Span sp1(4);

    sp1.addNumber(10);
    sp1.addNumber(25);

    std::cout << "Shortest(15): " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest(15): " << sp1.longestSpan() << std::endl;

    std::cout << "=== Duplicate numbers ===" << std::endl;

    sp1.addNumber(10);
    
    std::cout << "Shortest(0): " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest(15): " << sp1.longestSpan() << std::endl;

    std::cout << "=== Negative numbers ===" << std::endl;

    sp1.addNumber(-1);

    std::cout << "Shortest(0): " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest(26): " << sp1.longestSpan() << std::endl;

    std::cout << "=== Empty ===" << std::endl;

    Span sp2(1);

    try
    {
        std::cout << "Shortest: ";
        sp2.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Longest: ";
        sp2.longestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== One number ===" << std::endl;

    sp2.addNumber(42);

    try
    {
        std::cout << "Shortest: ";
        sp2.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Longest: ";
        sp2.longestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== MAX number + 1 ===" << std::endl;

    try
    {
        sp2.addNumber(1);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Range test: vector ===" << std::endl;

    Span sp3(5);

    std::vector<int> values;

    values.push_back(5);
    values.push_back(10);
    values.push_back(15);
    values.push_back(20);

    sp3.addNumbers(values.begin(), values.end());

    std::cout << "Shortest(5): " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest(15): " << sp3.longestSpan() << std::endl;

    std::cout << "=== Range test: list ===" << std::endl;

    Span sp4(5);

    std::list<int> l_values;

    l_values.push_back(5);
    l_values.push_back(10);
    l_values.push_back(15);
    l_values.push_back(20);

    sp4.addNumbers(l_values.begin(), l_values.end());

    std::cout << "Shortest(5): " << sp4.shortestSpan() << std::endl;
    std::cout << "Longest(15): " << sp4.longestSpan() << std::endl;

    std::cout << "=== 10000 numbers test ===" << std::endl;

    Span sp5(10000);

    std::vector<int> v_values;

    for (int i = 0; i < 10000; ++i)
        v_values.push_back(i);

    sp5.addNumbers(v_values.begin(), v_values.end());

    std::cout << "Shortest(1): " << sp5.shortestSpan() << std::endl;
    std::cout << "Longest(9999): " << sp5.longestSpan() << std::endl;

    return 0;
}
