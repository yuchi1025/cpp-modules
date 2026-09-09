/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:16:08 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/05 14:34:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::cout << "===== vector =====" << std::endl;

    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 1);
        std::cout << "Find the value: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 4);
        std::cout << "Find the value: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "===== list =====" << std::endl;

    std::list<int> i_list;

    i_list.push_back(1);
    i_list.push_back(2);
    i_list.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(i_list, 1);
        std::cout << "Find the value: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(i_list, 4);
        std::cout << "Find the value: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
