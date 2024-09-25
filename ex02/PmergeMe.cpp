/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:06:40 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/25 11:42:15 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(std::vector<int> vec) : _array(vec)
{
    MergeSort(_array);
    std::cout << "(Vector)After: " << std::endl;
    for(unsigned int i = 0; i < _array.size(); i++)
        std::cout << _array[i] << " ";
    std::cout << std::endl;

}

PmergeMe::PmergeMe(std::deque<int> deq) : _darray(deq)
{
    MergeSortDeque(_darray);
    // std::cout << "(Deque)After: " << std::endl;
    // for(unsigned int i = 0; i < _darray.size(); i++)
    //     std::cout << _darray[i] << " ";
    // std::cout << std::endl;

}

PmergeMe::PmergeMe(const PmergeMe &copy) : _array(copy._array){}

PmergeMe &PmergeMe::operator=(const PmergeMe &merge)
{
    if (this != &merge)
    {
        _array = merge._array;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::MergeSort(std::vector<int> &array)
{
    if (array.size() == 1)
        return ;
    unsigned int mid = array.size() / 2;
    std::vector<int> _left(mid);
    std::vector<int> _right(array.size() - mid);
    for(unsigned int i = 0, j = 0; i < array.size(); i++)
    {
        if (i < mid)
            _left[i] = array[i];
        else
        {
            _right[j] = array[i];
            j++;
        }
    }
    MergeSort(_left);
    MergeSort(_right);
    Merge(_left, _right, array);
}

void PmergeMe::Merge(std::vector<int> left, std::vector<int> right, std::vector<int> &array)
{
    unsigned int i = 0, l = 0, r = 0;
    while(l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
        {
            array[i] = left[l];
            l++;
        }
        else
        {
            array[i] = right[r];
            r++;
        }
        i++;
    }
    while (l < left.size())
    {
        array[i] = left[l];
        i++;
        l++;
    }
    while (r < right.size())
    {
        array[i] = right[r];
        i++;
        r++;
    }
}

void PmergeMe::MergeSortDeque(std::deque<int> &array)
{
    if (array.size() == 1)
        return ;
    unsigned int mid = array.size() / 2;
    std::deque<int> _left(mid);
    std::deque<int> _right(array.size() - mid);
    for(unsigned int i = 0, j = 0; i < array.size(); i++)
    {
        if (i < mid)
            _left[i] = array[i];
        else
        {
            _right[j] = array[i];
            j++;
        }
    }
    MergeSortDeque(_left);
    MergeSortDeque(_right);
    MergeDeque(_left, _right, array);
}

void PmergeMe::MergeDeque(std::deque<int> left, std::deque<int> right, std::deque<int> &array)
{
    unsigned int i = 0, l = 0, r = 0;
    while(l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
        {
            array[i] = left[l];
            l++;
        }
        else
        {
            array[i] = right[r];
            r++;
        }
        i++;
    }
    while (l < left.size())
    {
        array[i] = left[l];
        i++;
        l++;
    }
    while (r < right.size())
    {
        array[i] = right[r];
        i++;
        r++;
    }
}