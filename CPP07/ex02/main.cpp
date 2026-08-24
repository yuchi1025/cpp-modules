/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:31:29 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/23 15:40:05 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "=== Default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "=== Constructor with size ===" << std::endl;
    Array<int> numbers(5);
    std::cout << "size: " << numbers.size() << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "=== Update elements ===" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = i * 5;
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "=== Copy constructor ===" << std::endl;
    Array<int> copy(numbers);

    std::cout << "before modify copy[0], numbers[0]: " << numbers[0] << std::endl;
    std::cout << "before modify, copy[0]: " << copy[0] << std::endl;

    copy[0] = 42;
    std::cout << "after modify, copy[0]: " << copy[0] << std::endl;
    std::cout << "after modify copy[0], numbers[0]: " << numbers[0] << std::endl;

    std::cout << "=== Assignment operator ===" << std::endl;
    Array<int> assign(2);

    std::cout << "before update assign, numbers[1]: " << numbers[1] << std::endl;
    std::cout << "before update assign, assign[1]: " << assign[1] << std::endl;

    assign = numbers;
    assign[1] = 42;

    std::cout << "after update assign, numbers[1]: " << numbers[1] << std::endl;
    std::cout << "after update assign, assign[1]: " << assign[1] << std::endl;

    std::cout << "=== Out of bounds ===" << std::endl;
    try
    {
        std::cout << numbers[42] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== String array ===" << std::endl;
    Array<std::string> strs(3);

    strs[0] = "Hi";
    strs[1] = "42";
    strs[2] = "Singapore";

    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << " ";
    std::cout << std::endl;

    std::cout << "=== Const array ===" << std::endl;
    const Array<int> constInt(numbers);

    for (unsigned int i = 0; i < constInt.size(); i++)
        std::cout << constInt[i] << " ";
    std::cout << std::endl;

    return 0;
}
