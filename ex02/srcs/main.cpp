/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2025/01/02 06:49:06 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Header.hpp"

int main( int argc, char **argv )
{	
	std::cout << std::endl;
	
	try
	{
		if (argc < 2)
			throw PmergeMe::WrongArgNumberException();
		
		PmergeMe	vector;
		
		vector.sortNumbersVector(argv);
		vector.setEndTime();
		//vector.testSortedSequenceVector();
		vector.printBefore(argv);
		vector.printAfterVector();
		vector.printTime("vector");

		PmergeMe	list;

		list.sortNumbersList(argv);
		list.setEndTime();
		//list.testSortedSequenceList();
		//list.printBefore(argv);
		//list.printAfterList();
		list.printTime("list");
		
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << std::endl;
	}

	testVectorCopyByAffectationFilled();
	testVectorCopyByAffectationEmpty();
	testVectorCopyByConstructor();

	testListCopyByAffectationFilled();
	testListCopyByAffectationEmpty();
	testListCopyByConstructor();
	
	return 0;
}