/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:07:12 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/24 23:04:04 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    private:

        std::vector<int> _array;
        std::deque<int> _darray;

    public:

        PmergeMe();
        PmergeMe(std::vector<int> vec);
        PmergeMe(std::deque<int> deq);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &merge);
        ~PmergeMe();

        void MergeSort(std::vector<int> &array);
        void Merge(std::vector<int> left, std::vector<int> right, std::vector<int> &array);

        void MergeSortDeque(std::deque<int> &array);
        void MergeDeque(std::deque<int> left, std::deque<int> right, std::deque<int> &array);


};

#endif