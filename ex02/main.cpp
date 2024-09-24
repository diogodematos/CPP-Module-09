/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:35:14 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/24 22:35:10 by dcarrilh         ###   ########.fr       */
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
    // Ordenando usando std::vector (supondo que PmergeMe aceita um std::vector)
        PmergeMe Ford(vec);

    // Captura o tempo final para o primeiro container (std::vector)
        std::clock_t end_vector = std::clock();

    // Calcula o tempo total para o primeiro container em microssegundos
        double duration_vector = 1000000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;

    // Exibe o tempo usado pelo std::vector
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << duration_vector << " us" << std::endl;

    
    
        
    }
    return 0;
}