/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:51:33 by yucchen           #+#    #+#             */
/*   Updated: 2026/06/28 18:39:27 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "===== Polymorphism Test =====" << std::endl;
	
	Animal* animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << animals[i]->getType() << " " << std::endl;
		animals[i]->makeSound();
		delete animals[i];
	}
	
    std::cout << "===== Deep Copy Test =====" << std::endl;

    Dog dog1;
    dog1.setIdea(0, "I want a bone.");

    Dog dog2(dog1);	// Copy constructor

    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

    dog1.setIdea(0, "I want to sleep.");

    std::cout << "After changing dog1" << std::endl;
    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

	return 0;
}