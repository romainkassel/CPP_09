/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/12/18 07:20:14 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Sources:

o How to define a bisextile year? https://kalendrier.ouest-france.fr/annees-bissextiles.html
o Calendar for number of days per month: https://www.timeanddate.com/calendar/months/
o Calculator with copy/paste: https://web2.0calc.fr/
o Convertor scientific to decimal notation: https://www.calculator.io/fr/convertisseur-de-notation-scientifique/

*/

#include "BitcoinExchange.hpp"

// start colors

#define BOLD "\033[1;"
#define NORMAL "\033[0;"

#define MAGENTA "35m"
#define GREEN "32m"

#define END "\033[0m"

// end colors

// Test functions

void	testBitcoinExchangeCopyByAffectationFilled( void );
void	testBitcoinExchangeCopyByAffectationEmpty( void );
void	testConstructorByCopy(BitcoinExchange bitcoinExchange);
void	testBitcoinExchangeCopyByConstructor( void );

int main( int argc, char **argv )
{	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Main test" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	
	(void)argc;

	try
	{
		if (argv[1] == NULL)
			throw BitcoinExchange::CouldNotOpenFileException();
		BitcoinExchange::checkInputFile(argv[1]);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << "." << std::endl;
		std::cout << std::endl;
		return (1);
	}

	BitcoinExchange	bitcoinExchange;

	std::cout << std::endl;

	bitcoinExchange.eatDatabase();
	bitcoinExchange.printResult(argv[1]);

	testBitcoinExchangeCopyByAffectationFilled();
	testBitcoinExchangeCopyByAffectationEmpty();
	testBitcoinExchangeCopyByConstructor();

	std::cout << std::endl;
	
	return 0;
}

void    testBitcoinExchangeCopyByAffectationFilled()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test BitcoinExchange copy by affectation (from filled to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a BitcoinExchange instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	BitcoinExchange	bitcoinExchange1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this BitcoinExchange with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	bitcoinExchange1.insert(std::pair<std::string, float>("insert1", 42.45));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert2", 87));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert3", 8.9));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert4", 7654));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert5", 78.98));

	BitcoinExchange::iterator	it;
	BitcoinExchange::iterator	ite = bitcoinExchange1.end();

	for (it = bitcoinExchange1.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a BitcoinExchange instance (copy)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	BitcoinExchange	bitcoinExchange2;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this BitcoinExchange with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	bitcoinExchange2.insert(std::pair<std::string, float>("test1", 1));
	bitcoinExchange2.insert(std::pair<std::string, float>("test2", 2));
	bitcoinExchange2.insert(std::pair<std::string, float>("test3", 3));
	bitcoinExchange2.insert(std::pair<std::string, float>("test4", 4));
	bitcoinExchange2.insert(std::pair<std::string, float>("test5", 5));

	ite = bitcoinExchange2.end();

	for (it = bitcoinExchange2.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Affecting bitcoinExchange1 to bitcoinExchange2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	bitcoinExchange2 = bitcoinExchange1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "bitcoinExchange2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	ite = bitcoinExchange2.end();

	for (it = bitcoinExchange2.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Updating copy, should not affect original instance" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	bitcoinExchange2["insert1"] = 87766;
	bitcoinExchange2["insert2"] = 768;
	bitcoinExchange2["insert3"] = 9;
	bitcoinExchange2["insert4"] = 43;
	bitcoinExchange2["insert5"] = 21;

	std::cout << "bitcoinExchange2 after: " << std::endl;
	ite = bitcoinExchange2.end();

	for (it = bitcoinExchange2.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;

	std::cout << "bitcoinExchange1 after: " << std::endl;
	ite = bitcoinExchange1.end();

	for (it = bitcoinExchange1.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;
    
    return ;
}

void    testBitcoinExchangeCopyByAffectationEmpty()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test BitcoinExchange copy by affectation (from empty to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a BitcoinExchange instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	BitcoinExchange	bitcoinExchange1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this BitcoinExchange with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	bitcoinExchange1.insert(std::pair<std::string, float>("insert1", 42.45));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert2", 87));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert3", 8.9));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert4", 7654));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert5", 78.98));

	BitcoinExchange::iterator	it;
	BitcoinExchange::iterator	ite = bitcoinExchange1.end();

	for (it = bitcoinExchange1.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of an empty BitcoinExchange instance (copy)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	BitcoinExchange	bitcoinExchange2;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Affecting bitcoinExchange1 to bitcoinExchange2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	bitcoinExchange2 = bitcoinExchange1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "bitcoinExchange2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	ite = bitcoinExchange2.end();

	for (it = bitcoinExchange2.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Updating copy, should not affect original instance" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	bitcoinExchange2["insert1"] = 87766;
	bitcoinExchange2["insert2"] = 768;
	bitcoinExchange2["insert3"] = 9;
	bitcoinExchange2["insert4"] = 43;
	bitcoinExchange2["insert5"] = 21;

	std::cout << "bitcoinExchange2 after: " << std::endl;
	ite = bitcoinExchange2.end();

	for (it = bitcoinExchange2.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;

	std::cout << "bitcoinExchange1 after: " << std::endl;
	ite = bitcoinExchange1.end();

	for (it = bitcoinExchange1.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;
    
    return ;
}

void    testBitcoinExchangeCopyByConstructor()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test BitcoinExchange copy by constructor" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a BitcoinExchange instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	BitcoinExchange	bitcoinExchange1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this BitcoinExchange with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	bitcoinExchange1.insert(std::pair<std::string, float>("insert1", 42.45));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert2", 87));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert3", 8.9));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert4", 7654));
	bitcoinExchange1.insert(std::pair<std::string, float>("insert5", 78.98));

	BitcoinExchange::iterator	it;
	BitcoinExchange::iterator	ite = bitcoinExchange1.end();

	for (it = bitcoinExchange1.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Call to copy by constructor" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	testConstructorByCopy(bitcoinExchange1);
    
    return ;
}

void	testConstructorByCopy(BitcoinExchange bitcoinExchange)
{
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Copy after" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	BitcoinExchange::iterator	it;
	BitcoinExchange::iterator	ite = bitcoinExchange.end();

	for (it = bitcoinExchange.begin(); it != ite; it++)
		std::cout << it->first << " => " << it->second << std::endl;
	
	std::cout << std::endl;
	
	return ;
}