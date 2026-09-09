/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:17:07 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/09 12:00:28 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::list<int> i_list;

    mstack.push(5);
    mstack.push(17);
    i_list.push_back(5);
    i_list.push_back(17);

    std::cout << "mstack-size: " << mstack.size() << std::endl;
    std::cout << "i_list-size: " << i_list.size() << std::endl;
    std::cout << "mstack-top: " << mstack.top() << std::endl;
    std::cout << "i_list-top: " << i_list.back() << std::endl;

    std::cout << "Pop" << std::endl;

    mstack.pop();
    i_list.pop_back();

    std::cout << "mstack-size: " << mstack.size() << std::endl;
    std::cout << "i_list-size: " << i_list.size() << std::endl;
    std::cout << "mstack-top: " << mstack.top() << std::endl;
    std::cout << "i_list-top: " << i_list.back() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    i_list.push_back(3);
    i_list.push_back(5);
    i_list.push_back(737);
    i_list.push_back(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::list<int>::iterator l_it = i_list.begin();
    std::list<int>::iterator l_ite = i_list.end();
    
    ++it;
    --it;
    std::cout << "=== Iter mstack ===" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    ++l_it;
    --l_it;
    std::cout << "=== Iter l_list ===" << std::endl;
    while (l_it != l_ite)
    {
        std::cout << *l_it << std::endl;
        ++l_it;
    }

    std::cout << "=== Copy constructor ===" << std::endl;
    
    MutantStack<int> origin;
    
    origin.push(1);
    origin.push(2);

    MutantStack<int> copy(origin);

    std::cout << "copy top: " << copy.top() << std::endl;
    std::cout << "copy pop" << std::endl;
    copy.pop();
    std::cout << "origin top: " << origin.top() << std::endl;
    std::cout << "copy top: " << copy.top() << std::endl;

    std::cout << "=== Assignment operator ===" << std::endl;

    MutantStack<int> assign;
    
    assign = origin;

    std::cout << "Top: " << assign.top() << std::endl;

    return 0;
}
