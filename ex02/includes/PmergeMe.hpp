/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/18 06:38:33 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_H__
#define __PMERGEME_H__

#include <iostream>
#include <exception>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <limits.h>
#include <bits/stdc++.h>

class PmergeMe {

private:

    clock_t _start;
    clock_t _end;
    int     _nbOfNbs;

    std::vector< std::vector<int> > _vector;
    std::list< std::list<int> >     _list;

    int	_prevStepIndex;
	int	_currentStepIndex;
	int _index;
    int _insertArea;
    int _totalNumberOfIndexes;

public:

    PmergeMe( void );
    PmergeMe( PmergeMe const & src );
    ~PmergeMe( void );

    PmergeMe     &operator=( PmergeMe const & rhs );

    // vector

    void    printVector( std::string title );
    void    sortNumbersVector( char **intSequence );
    void    splitIntoPairsVector( char **intSequence );
    void    sortPairsIndividuallyVector( void );
    //void    sortPairsRecursivelyParamVector( int index );
    //void    sortPairsRecursivelyStaticVector( void );
    void    sortPairsIterativelyVector( void );
    void    insertAIntoMainChainVector( void );
    void    insertFirstBIntoMainChainVector( void );
    void    insertPendNumberVector( void );
    void    getTotalNumberOfIndexesVector( void );
    void    insertAllBIntoMainChainVector( void );
    void    insertLastBIntoMainChainVector( void );
    void    testSortedSequenceVector( void );
    void    printAfterVector( void );

    // list

    void    printList( std::string title );
    void    sortNumbersList( char **intSequence );
    void    splitIntoPairsList( char **intSequence );
    void    sortPairsIndividuallyList( void );
    //void    sortPairsRecursivelyParamList( int index );
    //void    sortPairsRecursivelyStaticList( void );
    void    sortPairsIterativelyList( void );
    void    insertAIntoMainChainList( void );
    void    insertFirstBIntoMainChainList( void );
    void    insertPendNumberList( void );
    void    getTotalNumberOfIndexesList( void );
    void    insertAllBIntoMainChainList( void );
    void    insertLastBIntoMainChainList( void );
    void    testSortedSequenceList( void );
    void    printAfterList( void );

    // getters for copy tests

    std::vector< std::vector<int> > &getVector( void );
    std::list< std::list<int> >     &getList( void );

    clock_t getStart( void ) const;
    clock_t getEnd( void ) const;
    int     getNbOfNbs( void ) const;
    int     getPrevStepIndex( void ) const;
    int     getCurrentStepIndex( void ) const;
    int     getIndex( void ) const;
    int     getInsertArea( void ) const;
    int     getTotalNumberOfIndexes( void ) const;

    // setters for copy tests

    void    setStart( clock_t start );
    void    setEnd( clock_t end );
    void    setNbOfNbs( int nbOfNbs );
    void    setPrevStepIndex( int prevStepIndex );
    void    setCurrentStepIndex( int currentStepIndex );
    void    setIndex( int index );
    void    setInsertArea( int insertArea );
    void    setTotalNumberOfIndexes( int totalNumberOfIndexes );

    // common

    void    printBefore( char **intSequence );
    void    setEndTime( void );
    void    printTime( std::string container ) const;

    class   BadIntergerRangeException : public std::exception {

        public:

            virtual const char *what() const throw();

    };

     class   WrongArgNumberException : public std::exception {

        public:

            virtual const char *what() const throw();

    };
};

#endif