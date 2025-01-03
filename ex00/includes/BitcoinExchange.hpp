/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/18 06:38:33 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_H__
#define __BITCOINEXCHANGE_H__

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <exception>
#include <sys/stat.h>

typedef std::map<std::string, float> map;
typedef std::pair<std::string, float> pair;

class BitcoinExchange : public map {

public:

    BitcoinExchange( void );
    BitcoinExchange( BitcoinExchange const & src );
    ~BitcoinExchange( void );

    BitcoinExchange    &operator=( BitcoinExchange const & rhs );
    
    static void checkInputFile( char *argv1 );
    void        eatDatabase( void );
    bool        checkDate( std::string date ) const;
    void        printResult( char *argv1 );

    class   CouldNotOpenFileException : public std::exception {

        virtual const char *what() const throw();

    };

    class   InvalidInputFileContentException : public std::exception {

        virtual const char *what() const throw();

    };

};

#endif