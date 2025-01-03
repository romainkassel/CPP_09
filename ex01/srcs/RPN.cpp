/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:47:29 by debian            #+#    #+#             */
/*   Updated: 2024/12/18 06:34:39 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN( void )
{
	//std::cout << "Default constructor (void) from RPN called" << std::endl;
	return ;
}

RPN::RPN( RPN const & src ) : stack(src)
{
	std::cout << "Copy constructor from RPN called" << std::endl;
	*this = src;
	return ;
}

RPN::~RPN( void )
{
	//std::cout << "Destructor from RPN called" << std::endl;
	return ;
}

RPN    &RPN::operator=( RPN const & rhs )
{
	std::cout << "Affectation operator from RPN called" << std::endl;

	this->c = rhs.c;

	return (*this);
}

void	RPN::processExpression( std::string input )
{
	std::stringstream	ss1(input), ss2;
	std::string			currentArg;
	float				nb;

	while (std::getline(ss1, currentArg, ' '))
	{
		if (currentArg.length() != 1)
			throw WrongInputException();
	
		if (std::isdigit(currentArg[0]) != 0) {
			ss2.clear();
			ss2 << currentArg;
			ss2 >> nb;
			this->push(nb);
		} else {
			if (currentArg.compare("+") != 0 && currentArg.compare("-") != 0
				&& currentArg.compare("/") != 0 && currentArg.compare("*") != 0)
			{
				throw WrongInputException();
			} else if (this->size() < 2) {
				throw WrongOperandNumberException();
			} else if (this->top() == 0 && currentArg[0] == '/') {
				throw DivByZeroException();
			} else {
				this->pushResult(currentArg[0]);
			}
		}
	}

	while (this->size() > 0)
	{
		std::cout << this->top() << std::endl;
		this->pop();
	}

	return;
}

void    RPN::pushResult( char const & op )
{
	float	nb2, nb1;

	nb2 = this->top();
	this->pop();

	nb1 = this->top();
	this->pop();

	switch (op)
	{
		case '+': this->push(nb1 + nb2); break;
		case '-': this->push(nb1 - nb2); break;
		case '/': this->push(nb1 / nb2); break;
		case '*': this->push(nb1 * nb2); break;
	}

	return ;
}

const char *RPN::WrongArgNumberException::what() const throw()
{
	return ("This program accepts only one inverted Polish mathematical expression as an argument.");
}

const char *RPN::WrongInputException::what() const throw()
{
	return ("This program's argument should include digits between 0 and 9 with the following tokens: + - / *.");
}

const char *RPN::WrongOperandNumberException::what() const throw()
{
	return ("An operator needs at least 2 operands.");
}

const char *RPN::DivByZeroException::what() const throw()
{
	return ("Dividing a number by 0 is impossible -> a '/' preceded by a 0.");
}