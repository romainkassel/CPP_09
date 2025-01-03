/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/12/19 12:37:23 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Sources:

o Calculator: https://www.dcode.fr/reverse-polish-notation

*/

#include "RPN.hpp"

// start colors

#define BOLD "\033[1;"
#define NORMAL "\033[0;"

#define MAGENTA "35m"
#define GREEN "32m"

#define END "\033[0m"

// end colors

// Test functions

void	testRPNCopyByAffectationFilled( void );
void	testRPNCopyByAffectationEmpty( void );
void	testConstructorByCopy(RPN rpn);
void	testRPNCopyByConstructor( void );

int main( int argc, char **argv )
{	
	std::cout << std::endl;
	
	try
	{
		if (argc != 2)
			throw RPN::WrongArgNumberException();
		RPN	rpn;
		rpn.processExpression(argv[1]);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	testRPNCopyByAffectationFilled();
	testRPNCopyByAffectationEmpty();
	testRPNCopyByConstructor();
	
	return 0;
}

void    testRPNCopyByAffectationFilled()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test RPN copy by affectation (from filled to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a rpn instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	RPN	rpn1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this rpn instance with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rpn1.push(65);
    std::cout << rpn1.top() << ", ";
    rpn1.push(689);
    std::cout << rpn1.top() << ", ";
    rpn1.push(21);
    std::cout << rpn1.top() << ", ";
    rpn1.push(98);
    std::cout << rpn1.top() << ", ";
    rpn1.push(32);
    std::cout << rpn1.top();

    std::cout << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a rpn instance (copy)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	RPN	rpn2;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this rpn instance with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rpn2.push(90);
    std::cout << rpn2.top() << ", ";
    rpn2.push(43);
    std::cout << rpn2.top() << ", ";
    rpn2.push(1);
    std::cout << rpn2.top() << ", ";
    rpn2.push(9);
    std::cout << rpn2.top() << ", ";
    rpn2.push(78);
    std::cout << rpn2.top();

    std::cout << std::endl;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Affecting rpn1 to rpn2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rpn2 = rpn1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "rpn2 copy after affectation (reverse order)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::cout << rpn2.top() << ", ";
    rpn2.pop();
    std::cout << rpn2.top() << ", ";
    rpn2.pop();
    std::cout << rpn2.top() << ", ";
    rpn2.pop();
    std::cout << rpn2.top() << ", ";
    rpn2.pop();
    std::cout << rpn2.top();

	std::cout << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Removing items from rpn2 should not affect original instance" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top();

	std::cout << std::endl;

	std::cout << std::endl;
    
    return ;
}

void    testRPNCopyByAffectationEmpty()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test RPN copy by affectation (from filled to empty)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a rpn instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	RPN	rpn1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this rpn instance with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rpn1.push(65);
    std::cout << rpn1.top() << ", ";
    rpn1.push(689);
    std::cout << rpn1.top() << ", ";
    rpn1.push(21);
    std::cout << rpn1.top() << ", ";
    rpn1.push(98);
    std::cout << rpn1.top() << ", ";
    rpn1.push(32);
    std::cout << rpn1.top();

    std::cout << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a rpn instance (copy)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	RPN	rpn2;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Affecting rpn1 to rpn2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rpn2 = rpn1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "rpn2 copy after affectation (reverse order)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::cout << rpn2.top() << ", ";
    rpn2.pop();
    std::cout << rpn2.top() << ", ";
    rpn2.pop();
    std::cout << rpn2.top() << ", ";
    rpn2.pop();
    std::cout << rpn2.top() << ", ";
    rpn2.pop();
    std::cout << rpn2.top();

	std::cout << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Removing items from rpn2 should not affect original instance" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top();

	std::cout << std::endl;

	std::cout << std::endl;
    
    return ;
}

void    testRPNCopyByConstructor()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test RPN copy by constructor" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a rpn instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	RPN	rpn1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this rpn instance with 5 items" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	rpn1.push(65);
    std::cout << rpn1.top() << ", ";
    rpn1.push(689);
    std::cout << rpn1.top() << ", ";
    rpn1.push(21);
    std::cout << rpn1.top() << ", ";
    rpn1.push(98);
    std::cout << rpn1.top() << ", ";
    rpn1.push(32);
    std::cout << rpn1.top();

    std::cout << std::endl;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Calling constructor by copy" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	testConstructorByCopy(rpn1);
    
    return ;
}

void    testConstructorByCopy(RPN rpn1)
{
    ////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Copy after constructor call (reverse order)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top() << ", ";
    rpn1.pop();
    std::cout << rpn1.top();

	std::cout << std::endl;

	std::cout << std::endl;

    return ;
}