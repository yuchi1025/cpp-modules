/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 11:05:04 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/21 11:10:29 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 3;
    int x = 42;
    int y = 42;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "swap(a, b)" << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "swap(x, y)" << std::endl;
    ::swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "swap(c, d)" << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}
