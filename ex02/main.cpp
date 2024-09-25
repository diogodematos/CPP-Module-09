/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:35:14 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/25 11:53:18 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
        std::cerr << "Error" << std::endl;
    else
    {
        std::vector<int> vec;
        for( int i = 1; i < argc; i++)
        {
            int p = 0;
            for(int j = 0; argv[i][j]; j++)
            {
                if (!isdigit(argv[i][j]))
                {
                    std::cerr << "Error" << std::endl;
                    return 0;
                }
                p = p * 10 +(argv[i][j] - 48);
            }
            vec.push_back(p);
        }
        std::cout << "Before: " << std::endl;
        for( unsigned int i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
        
        std::clock_t start_vector = std::clock();
    
        PmergeMe Ford(vec);

        std::clock_t end_vector = std::clock();

        double duration_vector = 1000000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << duration_vector << " us" << std::endl;

        std::deque<int> deq(vec.begin(), vec.end());

        std::clock_t start_deque = std::clock();

        PmergeMe Jhonson(deq);

        
        std::clock_t end_deque = std::clock();

        double duration_deque = 1000000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << duration_deque << " us" << std::endl;

    
        
    }
    return 0;
}