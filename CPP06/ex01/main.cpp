/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 13:12:25 by yucchen           #+#    #+#             */
/*   Updated: 2026/08/10 11:08:25 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;

    data.name = "Yuchi";
    data.age = 29;

    uintptr_t raw = Serializer::serialize(&data);
    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Recovered address: " << recovered << std::endl;

    if (&data == recovered)
        std::cout << "Same pointer" << std::endl;
    else
        std::cout << "Different pointer" << std::endl;

    std::cout << recovered->name << std::endl;
    std::cout << recovered->age << std::endl;

    return 0;
}
