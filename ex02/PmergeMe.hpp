/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:07:12 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/24 18:22:30 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class PmergeMe
{
    private:

        std::vector<int> _array;

    public:

        PmergeMe();
        PmergeMe(std::vector<int> vec);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &merge);
        ~PmergeMe();

        void MergeSort(std::vector<int> &array);
        void Merge(std::vector<int> left, std::vector<int> right, std::vector<int> &array);
};

#endif