/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:25:24 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/30 12:43:01 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cerr << "Must use a positive integer as an argument" << std::endl;
        return 1;
    }

    PmergeMe p;
    
    if (!p.parse(argc, argv))
        return 1;
    
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i];
        if (i != argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    clock_t vecStart = clock();
    std::vector<int> sortedVector = p.fordJohnson(p.getVector());
    clock_t vecEnd = clock();
    double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000.0;

    clock_t dequeStart = clock();
    std::deque<int> sortedDeque = p.fordJohnson(p.getDeque());
    clock_t dequeEnd = clock();
    double dequeTime = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000000.0;
    
    std::cout << "After:  ";
    for (std::vector<int>::size_type i = 0; i < sortedVector.size(); ++i)
        std::cout << sortedVector[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << dequeTime << " us" << std::endl;

    return 0;
}
