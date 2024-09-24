/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:35:14 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/09/24 18:25:26 by dcarrilh         ###   ########.fr       */
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
            vec.push_back(argv[i][0] - 48);
        }
        std::cout << "First array" << std::endl;
        for( unsigned int i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i] << std::endl;
        }
        PmergeMe ford(vec);
    }
    return 0;
}