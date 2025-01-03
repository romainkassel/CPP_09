/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CopyTestsVector.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 04:40:40 by debian            #+#    #+#             */
/*   Updated: 2025/01/02 06:39:32 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void    testVectorCopyByAffectationFilled()
{
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test Vector copy by affectation (from filled to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a PmergeMe instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	PmergeMe    vector1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this PmergeMe instance with 5 vectors of 2 int each" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::vector<int>    subVector;

    subVector.push_back(65);
    subVector.push_back(689);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(34);
    subVector.push_back(89);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(879);
    subVector.push_back(234);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(7);
    subVector.push_back(9);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(65);
    subVector.push_back(90);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    std::vector< std::vector<int> >::iterator   it;

    for (it = vector1.getVector().begin(); it != vector1.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
	
    std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Updating vector1 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    vector1.setStart(clock());
    vector1.setEnd(clock());
    vector1.setNbOfNbs(1);
    vector1.setPrevStepIndex(1);
    vector1.setCurrentStepIndex(1);
    vector1.setIndex(1);
    vector1.setInsertArea(1);
    vector1.setTotalNumberOfIndexes(1);

    std::cout << "vector1.getStart(): " << vector1.getStart() << std::endl;
    std::cout << "vector1.getEnd(): " << vector1.getEnd() << std::endl;
    std::cout << "vector1.getNbOfNbs(): " << vector1.getNbOfNbs() << std::endl;
    std::cout << "vector1.getPrevStepIndex(): " << vector1.getPrevStepIndex() << std::endl;
    std::cout << "vector1.getCurrentStepIndex(): " << vector1.getCurrentStepIndex() << std::endl;
    std::cout << "vector1.getIndex(): " << vector1.getIndex() << std::endl;
    std::cout << "vector1.getInsertArea(): " << vector1.getInsertArea() << std::endl;
    std::cout << "vector1.getTotalNumberOfIndexes(): " << vector1.getTotalNumberOfIndexes() << std::endl;

    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a PmergeMe instance (copy)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	PmergeMe    vector2;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this PmergeMe instance with 5 vectors of 2 int each" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    subVector.push_back(43);
    subVector.push_back(8);

    vector2.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(987);
    subVector.push_back(432);

    vector2.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(98);
    subVector.push_back(11);

    vector2.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(70);
    subVector.push_back(90);

    vector2.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(12);
    subVector.push_back(11);

    vector2.getVector().push_back(subVector);
    subVector.clear();

    for (it = vector2.getVector().begin(); it != vector2.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Updating vector2 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    vector2.setStart(clock());
    vector2.setEnd(clock());
    vector2.setNbOfNbs(2);
    vector2.setPrevStepIndex(2);
    vector2.setCurrentStepIndex(2);
    vector2.setIndex(2);
    vector2.setInsertArea(2);
    vector2.setTotalNumberOfIndexes(2);

    std::cout << "vector2.getStart(): " << vector2.getStart() << std::endl;
    std::cout << "vector2.getEnd(): " << vector2.getEnd() << std::endl;
    std::cout << "vector2.getNbOfNbs(): " << vector2.getNbOfNbs() << std::endl;
    std::cout << "vector2.getPrevStepIndex(): " << vector2.getPrevStepIndex() << std::endl;
    std::cout << "vector2.getCurrentStepIndex(): " << vector2.getCurrentStepIndex() << std::endl;
    std::cout << "vector2.getIndex(): " << vector2.getIndex() << std::endl;
    std::cout << "vector2.getInsertArea(): " << vector2.getInsertArea() << std::endl;
    std::cout << "vector2.getTotalNumberOfIndexes(): " << vector2.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Affecting vector1 to vector2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	vector2 = vector1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "vector2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
    for (it = vector2.getVector().begin(); it != vector2.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;

    std::cout << std::endl;

    std::cout << "vector2.getStart(): " << vector2.getStart() << std::endl;
    std::cout << "vector2.getEnd(): " << vector2.getEnd() << std::endl;
    std::cout << "vector2.getNbOfNbs(): " << vector2.getNbOfNbs() << std::endl;
    std::cout << "vector2.getPrevStepIndex(): " << vector2.getPrevStepIndex() << std::endl;
    std::cout << "vector2.getCurrentStepIndex(): " << vector2.getCurrentStepIndex() << std::endl;
    std::cout << "vector2.getIndex(): " << vector2.getIndex() << std::endl;
    std::cout << "vector2.getInsertArea(): " << vector2.getInsertArea() << std::endl;
    std::cout << "vector2.getTotalNumberOfIndexes(): " << vector2.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Adding one vector to vector1 should not affect vector2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	subVector.push_back(1000);
    subVector.push_back(1000);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    std::cout << BOLD << WHITE << "Vector1 after update:" << END << std::endl;
    for (it = vector1.getVector().begin(); it != vector1.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;

    std::cout << std::endl;

    std::cout << BOLD << WHITE << "Vector2 after update:" << END << std::endl;
    for (it = vector2.getVector().begin(); it != vector2.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Adding one vector to vector2 should not affect vector1" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	subVector.push_back(400);
    subVector.push_back(400);

    vector2.getVector().push_back(subVector);
    subVector.clear();

    std::cout << BOLD << WHITE << "Vector1 after update:" << END << std::endl;
    for (it = vector1.getVector().begin(); it != vector1.getVector().end(); ++it)
        std::cout << *(*it).begin() << " " << *(*it).rbegin() << std::endl;

    std::cout << std::endl;

    std::cout << BOLD << WHITE << "Vector2 after update:" << END << std::endl;
    for (it = vector2.getVector().begin(); it != vector2.getVector().end(); ++it)
        std::cout << *(*it).begin() << " " << *(*it).rbegin() << std::endl;

    std::cout << std::endl;
        
    return ;
}

void    testVectorCopyByAffectationEmpty()
{
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test Vector copy by affectation (from empty to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a PmergeMe instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	PmergeMe    vector1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this PmergeMe instance with 5 vectors of 2 int each" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::vector<int>    subVector;

    subVector.push_back(65);
    subVector.push_back(689);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(34);
    subVector.push_back(89);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(879);
    subVector.push_back(234);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(7);
    subVector.push_back(9);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(65);
    subVector.push_back(90);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    std::vector< std::vector<int> >::iterator   it;
    
    for (it = vector1.getVector().begin(); it != vector1.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Updating vector1 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    vector1.setStart(clock());
    vector1.setEnd(clock());
    vector1.setNbOfNbs(1);
    vector1.setPrevStepIndex(1);
    vector1.setCurrentStepIndex(1);
    vector1.setIndex(1);
    vector1.setInsertArea(1);
    vector1.setTotalNumberOfIndexes(1);

    std::cout << "vector1.getStart(): " << vector1.getStart() << std::endl;
    std::cout << "vector1.getEnd(): " << vector1.getEnd() << std::endl;
    std::cout << "vector1.getNbOfNbs(): " << vector1.getNbOfNbs() << std::endl;
    std::cout << "vector1.getPrevStepIndex(): " << vector1.getPrevStepIndex() << std::endl;
    std::cout << "vector1.getCurrentStepIndex(): " << vector1.getCurrentStepIndex() << std::endl;
    std::cout << "vector1.getIndex(): " << vector1.getIndex() << std::endl;
    std::cout << "vector1.getInsertArea(): " << vector1.getInsertArea() << std::endl;
    std::cout << "vector1.getTotalNumberOfIndexes(): " << vector1.getTotalNumberOfIndexes() << std::endl;

    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a PmergeMe instance (copy) with empty vector" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	PmergeMe    vector2;

    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Updating vector2 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    vector2.setStart(clock());
    vector2.setEnd(clock());
    vector2.setNbOfNbs(2);
    vector2.setPrevStepIndex(2);
    vector2.setCurrentStepIndex(2);
    vector2.setIndex(2);
    vector2.setInsertArea(2);
    vector2.setTotalNumberOfIndexes(2);

    std::cout << "vector2.getStart(): " << vector2.getStart() << std::endl;
    std::cout << "vector2.getEnd(): " << vector2.getEnd() << std::endl;
    std::cout << "vector2.getNbOfNbs(): " << vector2.getNbOfNbs() << std::endl;
    std::cout << "vector2.getPrevStepIndex(): " << vector2.getPrevStepIndex() << std::endl;
    std::cout << "vector2.getCurrentStepIndex(): " << vector2.getCurrentStepIndex() << std::endl;
    std::cout << "vector2.getIndex(): " << vector2.getIndex() << std::endl;
    std::cout << "vector2.getInsertArea(): " << vector2.getInsertArea() << std::endl;
    std::cout << "vector2.getTotalNumberOfIndexes(): " << vector2.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Affecting vector1 to vector2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	vector2 = vector1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "vector2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
    for (it = vector2.getVector().begin(); it != vector2.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;

    std::cout << std::endl;

    std::cout << "vector2.getStart(): " << vector2.getStart() << std::endl;
    std::cout << "vector2.getEnd(): " << vector2.getEnd() << std::endl;
    std::cout << "vector2.getNbOfNbs(): " << vector2.getNbOfNbs() << std::endl;
    std::cout << "vector2.getPrevStepIndex(): " << vector2.getPrevStepIndex() << std::endl;
    std::cout << "vector2.getCurrentStepIndex(): " << vector2.getCurrentStepIndex() << std::endl;
    std::cout << "vector2.getIndex(): " << vector2.getIndex() << std::endl;
    std::cout << "vector2.getInsertArea(): " << vector2.getInsertArea() << std::endl;
    std::cout << "vector2.getTotalNumberOfIndexes(): " << vector2.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Adding one vector to vector1 should not affect vector2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	subVector.push_back(1000);
    subVector.push_back(1000);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    std::cout << BOLD << WHITE << "Vector1 after update:" << END << std::endl;
    for (it = vector1.getVector().begin(); it != vector1.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;

    std::cout << std::endl;

    std::cout << BOLD << WHITE << "Vector2 after update:" << END << std::endl;
    for (it = vector2.getVector().begin(); it != vector2.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Adding one vector to vector2 should not affect vector1" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	subVector.push_back(400);
    subVector.push_back(400);

    vector2.getVector().push_back(subVector);
    subVector.clear();

    std::cout << BOLD << WHITE << "Vector1 after update:" << END << std::endl;
    for (it = vector1.getVector().begin(); it != vector1.getVector().end(); ++it)
        std::cout << *(*it).begin() << " " << *(*it).rbegin() << std::endl;

    std::cout << std::endl;

    std::cout << BOLD << WHITE << "Vector2 after update:" << END << std::endl;
    for (it = vector2.getVector().begin(); it != vector2.getVector().end(); ++it)
        std::cout << *(*it).begin() << " " << *(*it).rbegin() << std::endl;

    std::cout << std::endl;
        
    return ;
}

void	testConstructorByCopyVector(PmergeMe vector1)
{
    std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Display of copy vector with attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::vector< std::vector<int> >::iterator   it;

    for (it = vector1.getVector().begin(); it != vector1.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;

    std::cout << std::endl;

    std::cout << "vector1.getStart(): " << vector1.getStart() << std::endl;
    std::cout << "vector1.getEnd(): " << vector1.getEnd() << std::endl;
    std::cout << "vector1.getNbOfNbs(): " << vector1.getNbOfNbs() << std::endl;
    std::cout << "vector1.getPrevStepIndex(): " << vector1.getPrevStepIndex() << std::endl;
    std::cout << "vector1.getCurrentStepIndex(): " << vector1.getCurrentStepIndex() << std::endl;
    std::cout << "vector1.getIndex(): " << vector1.getIndex() << std::endl;
    std::cout << "vector1.getInsertArea(): " << vector1.getInsertArea() << std::endl;
    std::cout << "vector1.getTotalNumberOfIndexes(): " << vector1.getTotalNumberOfIndexes() << std::endl;

    std::cout << std::endl;

    return ;
}


void    testVectorCopyByConstructor()
{
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test Vector copy by constructor" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a PmergeMe instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	PmergeMe    vector1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this PmergeMe instance with 5 vectors of 2 int each" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::vector<int>    subVector;

    subVector.push_back(65);
    subVector.push_back(689);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(34);
    subVector.push_back(89);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(879);
    subVector.push_back(234);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(7);
    subVector.push_back(9);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    subVector.push_back(65);
    subVector.push_back(90);

    vector1.getVector().push_back(subVector);
    subVector.clear();

    std::vector< std::vector<int> >::iterator   it;

    for (it = vector1.getVector().begin(); it != vector1.getVector().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Updating vector1 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    vector1.setStart(clock());
    vector1.setEnd(clock());
    vector1.setNbOfNbs(1);
    vector1.setPrevStepIndex(1);
    vector1.setCurrentStepIndex(1);
    vector1.setIndex(1);
    vector1.setInsertArea(1);
    vector1.setTotalNumberOfIndexes(1);

    std::cout << "vector1.getStart(): " << vector1.getStart() << std::endl;
    std::cout << "vector1.getEnd(): " << vector1.getEnd() << std::endl;
    std::cout << "vector1.getNbOfNbs(): " << vector1.getNbOfNbs() << std::endl;
    std::cout << "vector1.getPrevStepIndex(): " << vector1.getPrevStepIndex() << std::endl;
    std::cout << "vector1.getCurrentStepIndex(): " << vector1.getCurrentStepIndex() << std::endl;
    std::cout << "vector1.getIndex(): " << vector1.getIndex() << std::endl;
    std::cout << "vector1.getInsertArea(): " << vector1.getInsertArea() << std::endl;
    std::cout << "vector1.getTotalNumberOfIndexes(): " << vector1.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Calling copy constructor" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    testConstructorByCopyVector(vector1);
        
    return ;
}