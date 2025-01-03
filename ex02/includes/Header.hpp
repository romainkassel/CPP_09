/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 04:58:15 by debian            #+#    #+#             */
/*   Updated: 2025/01/02 06:40:02 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEADER_H__
#define __HEADER_H__

#include "PmergeMe.hpp"

// start colors

#define BOLD "\033[1;"
#define NORMAL "\033[0;"

#define MAGENTA "35m"
#define GREEN "32m"
#define WHITE "37m"

#define END "\033[0m"

// end colors

// TESTS

//// Vector

void	testVectorCopyByAffectationFilled( void );
void	testVectorCopyByAffectationEmpty( void );
void	testConstructorByCopyVector(PmergeMe vector1);
void    testVectorCopyByConstructor( void );

//// List

void	testListCopyByAffectationFilled( void );
void	testListCopyByAffectationEmpty( void );
void	testConstructorByCopyList(PmergeMe list1);
void    testListCopyByConstructor( void );

#endif