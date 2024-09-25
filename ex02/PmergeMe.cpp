/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:06:40 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/25 11:58:50 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(std::vector<int> vec) : _array(vec)
{
    std::clock_t start_vector = std::clock();
    MergeSort(_array);
    std::clock_t end_vector = std::clock();
    double duration_vector = 1000000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;
    std::cout << "After: " << std::endl;
    for(unsigned int i = 0; i < _array.size(); i++)
        std::cout << _array[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << duration_vector << " us" << std::endl;


}

PmergeMe::PmergeMe(std::deque<int> deq) : _darray(deq)
{
    std::clock_t start_deque = std::clock();
    MergeSortDeque(_darray);
    std::clock_t end_deque = std::clock();
    double duration_deque = 1000000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;
    // std::cout << "(Deque)After: " << std::endl;
    // for(unsigned int i = 0; i < _darray.size(); i++)
    //     std::cout << _darray[i] << " ";
    // std::cout << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << duration_deque << " us" << std::endl;
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