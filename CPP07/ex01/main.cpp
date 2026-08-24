/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:12:47 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/21 15:16:03 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void print(int value)
{
    std::cout << value << std::endl;
}

void printConst(const int &n)
{
    std::cout << n << std::endl;
}

template <typename T>
void printElement(const T &value)
{
    std::cout << value << std::endl;
}

void increment(int &x)
{
    x++;
}

void addComma(std::string &str)
{
    str += ",";
}

int main()
{
    int numbers[] = {1, 2, 3};

    iter(numbers, 0, print);
    std::cout << "print: " << std::endl;
    iter(numbers, 3, print);
    std::cout << "increment" << std::endl;
    iter(numbers, 3, increment);
    std::cout << "printElement<int>: " << std::endl;
    iter(numbers, 3, printElement<int>);
    std::cout << "====================" << std::endl;

    const int conNum[] = {1, 2, 3};
    std::cout << "printConst: " << std::endl;
    iter(conNum, 3, printConst);
    std::cout << "printElement<const int>: " << std::endl;
    iter(conNum, 3, printElement<const int>);
    std::cout << "====================" << std::endl;

    std::string strs[] = {"hello", "42", "Singapore"};

    std::cout << "printElement<std::string>: " << std::endl;
    iter(strs, 3, printElement<std::string>);
    std::cout << "addComma" << std::endl;
    iter(strs, 3, addComma);
    std::cout << "printElement<std::string>: " << std::endl;
    iter(strs, 3, printElement<std::string>);
    std::cout << "====================" << std::endl;

    double doubles[] = {1.1, 2.2, 3.3};
    char chars[] = {'a', 'b', 'c'};

    std::cout << "printElement<double>: " << std::endl;
    iter(doubles, 3, printElement<double>);
    std::cout << "printElement<char>: " << std::endl;
    iter(chars, 3, printElement<char>);

    return 0;
}
