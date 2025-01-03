/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/18 06:38:33 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_H__
#define __RPN_H__

#include <iostream>
#include <stack>
#include <exception>
#include <sstream>
#include <bits/stdc++.h>

typedef std::stack<float> stack;

class RPN : public stack {

public:

    RPN( void );
    RPN( RPN const & src );
    ~RPN( void );

    RPN     &operator=( RPN const & rhs );

    void    processExpression( std::string input );
    void    pushResult( char const & op );

    class   WrongArgNumberException : public std::exception {

        public:

            virtual const char *what() const throw();

    };

    class   WrongInputException : public std::exception {

        public:

            virtual const char *what() const throw();

    };

    class   WrongOperandNumberException : public std::exception {

        public:

            virtual const char *what() const throw();

    };

     class   DivByZeroException : public std::exception {

        public:

            virtual const char *what() const throw();

    };

};

#endif