/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:20:49 by yucchen           #+#    #+#             */
/*   Updated: 2026/09/28 15:15:27 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        const std::vector<int>& getVector() const;
        const std::deque<int>& getDeque() const;

        bool parse(int argc, char** argv);
        std::vector<int> fordJohnson(const std::vector<int>& nums);
        std::deque<int> fordJohnson(const std::deque<int>& nums);
};

#endif
