/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:47:29 by debian            #+#    #+#             */
/*   Updated: 2024/12/18 06:34:39 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange( void )
{
	std::cout << "Default constructor (void) from BitcoinExchange called" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) : map(src)
{
	std::cout << "Copy constructor from BitcoinExchange called" << std::endl;
	*this = src;
	return ;
}

BitcoinExchange::~BitcoinExchange( void )
{
	std::cout << "Destructor from BitcoinExchange called" << std::endl;
	return ;
}

BitcoinExchange    &BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	BitcoinExchange::const_iterator	it;
	BitcoinExchange::const_iterator	ite = rhs.end();
	
	std::cout << "Affectation operator from BitcoinExchange called" << std::endl;

	this->clear();
	
	for (it = rhs.begin(); it != ite; it++)
		this->insert(std::pair<std::string, float>(it->first, it->second));

	return (*this);
}

void    BitcoinExchange::checkInputFile( char *argv1 )
{
	std::ifstream		inputFile(argv1);
	struct stat			sb;
	std::stringstream	ss;
	std::string			inputFileRow;

	if (inputFile.fail() || (stat(argv1, &sb) == 0 && sb.st_mode & S_IFDIR))
		throw CouldNotOpenFileException();

	std::getline(inputFile, inputFileRow);
	if (inputFileRow.compare("date | value") != 0 || inputFileRow.empty())
		throw InvalidInputFileContentException();

	std::getline(inputFile, inputFileRow);
	if (inputFileRow.empty() || inputFileRow.compare("date | value") == 0)
		throw InvalidInputFileContentException();

	inputFile.close();

	return ;
}

void    BitcoinExchange::eatDatabase( void )
{
	std::ifstream		intputDb("data.csv");
	std::stringstream	ss;
	std::string			dbRow, date;
	float				exchangeRate;

	std::getline(intputDb, dbRow);
	
	while (std::getline(intputDb, dbRow))
	{
		date = dbRow.substr(0, 10);
		ss.clear();
		ss << dbRow.substr(11);
		ss >> exchangeRate;
		this->insert(pair(date, exchangeRate));
	}

	intputDb.close();

	return ;
}

bool	BitcoinExchange::checkDate( std::string date ) const
{
	std::stringstream	ss;
	int					year, month, dayNb, day;

	if (date.length() != 10)
		return (false);

	for (int i = 0; i < (int)date.length(); i++)
		if (std::isdigit(date[i]) == 0 && date[i] != '-')
			return (false);

	ss.clear();
	ss << date.substr(0, 4);
	ss >> year;

	if ((year < 2009 && year != 2000) || (year > 2022 && year != 2100))
		return (false);

	ss.clear();
	ss << date.substr(5, 2);
	ss >> month;

	if (month < 1 || month > 12)
		return (false);

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		dayNb = 30;
	} else if (month == 2) {
		dayNb = 28;
		if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 100 == 0) && (year % 400 == 0)))
			dayNb = 29;
	} else {
		dayNb = 31;
	}

	ss.clear();
	ss << date.substr(8, 2);
	ss >> day;

	if (day < 1 || day > dayNb)
		return (false);

	return (true);
}

void	BitcoinExchange::printResult( char *argv1 )
{
	std::ifstream		inputFile(argv1);
	std::stringstream	ss;
	std::string			inputFileRow, date, tmp_date;
	float				value;

	std::getline(inputFile, inputFileRow);
	
	while (std::getline(inputFile, inputFileRow))
	{
		date = inputFileRow.substr(0, 10);

		if (this->checkDate(date) == false)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		ss.clear();
		ss << inputFileRow.substr(13);
		ss >> value;

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		} else if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		tmp_date = date;

		if (this->find(date) == this->end())
			for (map::iterator it = this->begin(); it != this->end() && it->first < date; it++)
				tmp_date = it->first;

		std::cout << date << " => " << value << " = " << (value * this->find(tmp_date)->second) << std::endl;

	}

	inputFile.close();

	return ;
}

const char *BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return ("could not open file");
}

const char *BitcoinExchange::InvalidInputFileContentException::what() const throw()
{
	return ("invalid input file content");
}