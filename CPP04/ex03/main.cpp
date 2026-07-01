/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:14:26 by yucchen           #+#    #+#             */
/*   Updated: 2026/07/01 19:50:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "=== Test deep copy ===" << std::endl;
	MateriaSource src1;
	src1.learnMateria(new Ice());

	MateriaSource src2(src1);

	AMateria* ice = src2.createMateria("ice");

	if (ice)
	{
		std::cout << ice->getType() << std::endl;
		delete ice;
	}
	
	std::cout << "=== Test inventory full ===" << std::endl;
	Character y("Yuchi");
    AMateria* ice1 = new Ice();

	y.equip(ice1);

	y.equip(new Ice());
	y.equip(new Ice());
	y.equip(new Ice());

	AMateria* ice2 = new Ice();

	y.equip(ice2);

	delete ice2;

	std::cout << "=== Test invalid index ===" << std::endl;
	y.use(-1, y);
	y.use(10, y);

	y.unequip(-1);
	y.unequip(10);

	std::cout << "=== Test unknown Materia ===" << std::endl;
	MateriaSource src3;

	AMateria* m = src3.createMateria("fire");

	if (m == NULL)
		std::cout << "Unknown materia" << std::endl;
    
	std::cout << "=== Test unequip() ===" << std::endl;
	y.unequip(0);

	delete ice1;

	return 0;
}
