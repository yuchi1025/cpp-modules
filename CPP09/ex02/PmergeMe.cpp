/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:32:36 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/30 16:34:32 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>      // INT_MAX
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other): _vector(other._vector), _deque(other._deque)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

const std::vector<int>& PmergeMe::getVector() const
{
    return this->_vector;
}

const std::deque<int>& PmergeMe::getDeque() const
{
    return this->_deque;
}

bool PmergeMe::parse(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            std::cerr << "Error: Must use positive integer" << std::endl;
            return false;
        }

        long num;

        std::istringstream iss(argv[i]);

        if (!(iss >> num) || !iss.eof() || num <= 0 || num > INT_MAX)
        {
            std::cerr << "Error: Invalid input" << std::endl;
            return false;
        }

        int i_num = static_cast<int>(num);

        if (std::find(_vector.begin(), _vector.end(), i_num) != _vector.end())
        {
            std::cerr << "Error: Duplicate number" << std::endl;
            return false;
        }
        
        this->_vector.push_back(i_num);
        this->_deque.push_back(i_num);
    }

    return true;
}

std::size_t jacobsthal(std::size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return (2 * jacobsthal(n - 2) + jacobsthal(n - 1));
}

std::vector<int> PmergeMe::fordJohnson(const std::vector<int>& nums)
{
    // Base case
    if (nums.size() <= 1)
        return nums;

    // Make (small, big) pairs
    std::vector< std::pair<int, int> > pairs;
    bool hasStraggler;
    int straggler;

    if (nums.size() % 2)
    {
        hasStraggler = true;
        straggler = nums.back();
    }
    else
        hasStraggler = false;

    for (std::vector<int>::size_type i = 0; i + 1 < nums.size(); i += 2)
    {
        if (nums[i] < nums[i + 1])
            pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
        else
            pairs.push_back(std::make_pair(nums[i + 1], nums[i]));
    }

    // Store Bigs
    std::vector<int> Bigs;

    //std::cout << "=== pairs === " << std::endl;
    for (std::vector< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i)
    {
        //std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
        Bigs.push_back(pairs[i].second);
    }

    // Recursively sort Bigs
    Bigs = fordJohnson(Bigs);

    // Build main chain (Put b1 inside first)
    std::vector<int> mainChain;

    //std::cout << "=== mainChain ===" << std::endl;

    for (std::vector< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].second == Bigs[0])
        {
            //std::cout << "Bigs[0]: " << Bigs[0] << "; small pair: " << pairs[i].first << std::endl;
            mainChain.push_back(pairs[i].first);
            break ;
        }
    }

    // Append sorted Bigs
    for (std::vector<int>::size_type i = 0; i < Bigs.size(); ++i)
        mainChain.push_back(Bigs[i]);

    // Build pendings (b2, b3, ...)
    std::vector< std::pair<int, int> > pendings;

    //std::cout << "=== Pending ===" << std::endl;
    std::vector<int>::iterator it;
    for (it = Bigs.begin() + 1; it != Bigs.end(); ++it)
    {    
        for (std::vector< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i)
        {
            if (pairs[i].second == *it)
            {
                pendings.push_back(std::make_pair(pairs[i].first, pairs[i].second));
                break ;
            }
        }
    }

    /*
    for (std::vector< std::pair<int, int> >::size_type i = 0; i < pendings.size(); ++i)
        std::cout << pendings[i].first << " " << pendings[i].second << std::endl;
    */

    // Insert straggler
    if (hasStraggler)
    {
        //std::cout << "Straggler: " << straggler << std::endl;

        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    // Get Jacobsthal insertion order
    //std::cout << "=== jacobsthal order ===" << std::endl;
    std::vector<std::size_t> jacobsthalOrder;
    std::size_t pairCnt = pairs.size();
    std::size_t previous = 1;

    if (pairCnt > 1)
    {
        for (std::size_t i = 3; ; ++i)
        {
            std::size_t current = jacobsthal(i); 
            std::size_t boundary = current;

            if (boundary > pairCnt)
                boundary = pairCnt;

            for (std::size_t j = boundary; j > previous; --j)
                jacobsthalOrder.push_back(j - 2);

            if (boundary == pairCnt)
                break ;

            previous = current;
        }
    }

    /*
    for (std::vector<std::size_t>::size_type i = 0; i < jacobsthalOrder.size(); ++i)
        std::cout << jacobsthalOrder[i] << " ";
    std::cout << std::endl;
    */

    // Insert smalls
    for (std::vector<std::size_t>::size_type i = 0; i < jacobsthalOrder.size(); ++i)
    {
        int small = pendings[jacobsthalOrder[i]].first;
        int big = pendings[jacobsthalOrder[i]].second;

        std::vector<int>::iterator bigPos = std::find(mainChain.begin(), mainChain.end(), big);
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), bigPos, small);
        mainChain.insert(insertPos, small);
    }

    return mainChain;
}

std::deque<int> PmergeMe::fordJohnson(const std::deque<int>& nums)
{
    // Base case
    if (nums.size() <= 1)
        return nums;

    // Make (small, big) pairs
    std::deque< std::pair<int, int> > pairs;
    bool hasStraggler;
    int straggler;

    if (nums.size() % 2)
    {
        hasStraggler = true;
        straggler = nums.back();
    }
    else
        hasStraggler = false;

    for (std::deque<int>::size_type i = 0; i + 1 < nums.size(); i += 2)
    {
        if (nums[i] < nums[i + 1])
            pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
        else
            pairs.push_back(std::make_pair(nums[i + 1], nums[i]));
    }

    // Store Bigs
    std::deque<int> Bigs;

    for (std::deque< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i)
        Bigs.push_back(pairs[i].second);

    // Recursively sort Bigs
    Bigs = fordJohnson(Bigs);

    // Build main Chain (Put b1 inside first)
    std::deque<int> mainChain;

    for (std::deque< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].second == Bigs[0])
        {
            mainChain.push_back(pairs[i].first);
            break ;
        }
    }

    // Append sorted Bigs
    for (std::deque<int>::size_type i = 0; i < Bigs.size(); ++i)
        mainChain.push_back(Bigs[i]);
    
    // Build pendings (b2, b3, ...)
    std::deque< std::pair<int, int> > pendings;

    for (std::deque<int>::size_type i = 1; i < Bigs.size(); ++i)
    {
        for (std::deque< std::pair<int, int> >::size_type j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == Bigs[i])
            {
                pendings.push_back(std::make_pair(pairs[j].first, pairs[j].second));
                break ;
            }
        }
    }

    // Insert straggler
    if (hasStraggler)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    // Get jacobsthal insertion order 
    std::deque<std::size_t> jacobsthalOrder;
    std::size_t pairCnt = pairs.size();
    std::size_t previous = 1;

    if (pairCnt > 1)
    {
        for (std::size_t i = 3; ; ++i)
        {
            std::size_t current = jacobsthal(i);
            std::size_t boundary = current;

            if (boundary > pairCnt)
                boundary = pairCnt;

            for (std::size_t j = boundary; j > previous; --j)
                jacobsthalOrder.push_back(j - 2);

            if (boundary == pairCnt)
                break ;

            previous = current;
        }
    }

    // Insert smalls
    for (std::deque<std::size_t>::size_type i = 0; i < jacobsthalOrder.size(); ++i)
    {
        int small = pendings[jacobsthalOrder[i]].first;
        int big = pendings[jacobsthalOrder[i]].second;

        std::deque<int>::iterator bigPos = std::find(mainChain.begin(), mainChain.end(), big);
        std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), bigPos, small);
        mainChain.insert(insertPos, small);
    }

    return mainChain;
}
