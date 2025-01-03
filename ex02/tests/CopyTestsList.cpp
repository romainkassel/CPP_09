/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CopyTestsList.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 06:25:50 by debian            #+#    #+#             */
/*   Updated: 2025/01/02 06:41:08 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void    testListCopyByAffectationFilled()
{
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test List copy by affectation (from filled to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a PmergeMe instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	PmergeMe    list1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this PmergeMe instance with 5 lists of 2 int each" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::list<int>    subList;

    subList.push_back(65);
    subList.push_back(689);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(34);
    subList.push_back(89);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(879);
    subList.push_back(234);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(7);
    subList.push_back(9);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(65);
    subList.push_back(90);

    list1.getList().push_back(subList);
    subList.clear();

    std::list< std::list<int> >::iterator   it;
    
    for (it = list1.getList().begin(); it != list1.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Updating list1 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    list1.setStart(clock());
    list1.setEnd(clock());
    list1.setNbOfNbs(1);
    list1.setPrevStepIndex(1);
    list1.setCurrentStepIndex(1);
    list1.setIndex(1);
    list1.setInsertArea(1);
    list1.setTotalNumberOfIndexes(1);

    std::cout << "list1.getStart(): " << list1.getStart() << std::endl;
    std::cout << "list1.getEnd(): " << list1.getEnd() << std::endl;
    std::cout << "list1.getNbOfNbs(): " << list1.getNbOfNbs() << std::endl;
    std::cout << "list1.getPrevStepIndex(): " << list1.getPrevStepIndex() << std::endl;
    std::cout << "list1.getCurrentStepIndex(): " << list1.getCurrentStepIndex() << std::endl;
    std::cout << "list1.getIndex(): " << list1.getIndex() << std::endl;
    std::cout << "list1.getInsertArea(): " << list1.getInsertArea() << std::endl;
    std::cout << "list1.getTotalNumberOfIndexes(): " << list1.getTotalNumberOfIndexes() << std::endl;

    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a PmergeMe instance (copy)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	PmergeMe    list2;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this PmergeMe instance with 5 lists of 2 int each" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    subList.push_back(43);
    subList.push_back(8);

    list2.getList().push_back(subList);
    subList.clear();

    subList.push_back(987);
    subList.push_back(432);

    list2.getList().push_back(subList);
    subList.clear();

    subList.push_back(98);
    subList.push_back(11);

    list2.getList().push_back(subList);
    subList.clear();

    subList.push_back(70);
    subList.push_back(90);

    list2.getList().push_back(subList);
    subList.clear();

    subList.push_back(12);
    subList.push_back(11);

    list2.getList().push_back(subList);
    subList.clear();
    
    for (it = list2.getList().begin(); it != list2.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Updating list2 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    list2.setStart(clock());
    list2.setEnd(clock());
    list2.setNbOfNbs(2);
    list2.setPrevStepIndex(2);
    list2.setCurrentStepIndex(2);
    list2.setIndex(2);
    list2.setInsertArea(2);
    list2.setTotalNumberOfIndexes(2);

    std::cout << "list2.getStart(): " << list2.getStart() << std::endl;
    std::cout << "list2.getEnd(): " << list2.getEnd() << std::endl;
    std::cout << "list2.getNbOfNbs(): " << list2.getNbOfNbs() << std::endl;
    std::cout << "list2.getPrevStepIndex(): " << list2.getPrevStepIndex() << std::endl;
    std::cout << "list2.getCurrentStepIndex(): " << list2.getCurrentStepIndex() << std::endl;
    std::cout << "list2.getIndex(): " << list2.getIndex() << std::endl;
    std::cout << "list2.getInsertArea(): " << list2.getInsertArea() << std::endl;
    std::cout << "list2.getTotalNumberOfIndexes(): " << list2.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Affecting list1 to list2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	list2 = list1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "list2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
    for (it = list2.getList().begin(); it != list2.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "list2.getStart(): " << list2.getStart() << std::endl;
    std::cout << "list2.getEnd(): " << list2.getEnd() << std::endl;
    std::cout << "list2.getNbOfNbs(): " << list2.getNbOfNbs() << std::endl;
    std::cout << "list2.getPrevStepIndex(): " << list2.getPrevStepIndex() << std::endl;
    std::cout << "list2.getCurrentStepIndex(): " << list2.getCurrentStepIndex() << std::endl;
    std::cout << "list2.getIndex(): " << list2.getIndex() << std::endl;
    std::cout << "list2.getInsertArea(): " << list2.getInsertArea() << std::endl;
    std::cout << "list2.getTotalNumberOfIndexes(): " << list2.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Adding one list to list1 should not affect list2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	subList.push_back(1000);
    subList.push_back(1000);

    list1.getList().push_back(subList);
    subList.clear();

    std::cout << BOLD << WHITE << "List1 after update:" << END << std::endl;
    for (it = list1.getList().begin(); it != list1.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;

    std::cout << std::endl;

    std::cout << BOLD << WHITE << "List2 after update:" << END << std::endl;
    for (it = list2.getList().begin(); it != list2.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Adding one list to list2 should not affect list1" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	subList.push_back(400);
    subList.push_back(400);

    list2.getList().push_back(subList);
    subList.clear();

    std::cout << BOLD << WHITE << "List1 after update:" << END << std::endl;
    for (it = list1.getList().begin(); it != list1.getList().end(); ++it)
        std::cout << *(*it).begin() << " " << *(*it).rbegin() << std::endl;
    
    std::cout << std::endl;

    std::cout << BOLD << WHITE << "List2 after update:" << END << std::endl;
    for (it = list2.getList().begin(); it != list2.getList().end(); ++it)
        std::cout << *(*it).begin() << " " << *(*it).rbegin() << std::endl;
    
    std::cout << std::endl;
        
    return ;
}

void    testListCopyByAffectationEmpty()
{
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test List copy by affectation (from empty to filled)" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a PmergeMe instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	PmergeMe    list1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Filling this PmergeMe instance with 5 lists of 2 int each" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::list<int>    subList;

    subList.push_back(65);
    subList.push_back(689);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(34);
    subList.push_back(89);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(879);
    subList.push_back(234);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(7);
    subList.push_back(9);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(65);
    subList.push_back(90);

    list1.getList().push_back(subList);
    subList.clear();

    std::list< std::list<int> >::iterator   it;
    
    for (it = list1.getList().begin(); it != list1.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////s////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Updating list1 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    list1.setStart(clock());
    list1.setEnd(clock());
    list1.setNbOfNbs(1);
    list1.setPrevStepIndex(1);
    list1.setCurrentStepIndex(1);
    list1.setIndex(1);
    list1.setInsertArea(1);
    list1.setTotalNumberOfIndexes(1);

    std::cout << "list1.getStart(): " << list1.getStart() << std::endl;
    std::cout << "list1.getEnd(): " << list1.getEnd() << std::endl;
    std::cout << "list1.getNbOfNbs(): " << list1.getNbOfNbs() << std::endl;
    std::cout << "list1.getPrevStepIndex(): " << list1.getPrevStepIndex() << std::endl;
    std::cout << "list1.getCurrentStepIndex(): " << list1.getCurrentStepIndex() << std::endl;
    std::cout << "list1.getIndex(): " << list1.getIndex() << std::endl;
    std::cout << "list1.getInsertArea(): " << list1.getInsertArea() << std::endl;
    std::cout << "list1.getTotalNumberOfIndexes(): " << list1.getTotalNumberOfIndexes() << std::endl;

    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Creation of a PmergeMe instance (copy) with empty list" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	PmergeMe    list2;

    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Updating list2 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    list2.setStart(clock());
    list2.setEnd(clock());
    list2.setNbOfNbs(2);
    list2.setPrevStepIndex(2);
    list2.setCurrentStepIndex(2);
    list2.setIndex(2);
    list2.setInsertArea(2);
    list2.setTotalNumberOfIndexes(2);

    std::cout << "list2.getStart(): " << list2.getStart() << std::endl;
    std::cout << "list2.getEnd(): " << list2.getEnd() << std::endl;
    std::cout << "list2.getNbOfNbs(): " << list2.getNbOfNbs() << std::endl;
    std::cout << "list2.getPrevStepIndex(): " << list2.getPrevStepIndex() << std::endl;
    std::cout << "list2.getCurrentStepIndex(): " << list2.getCurrentStepIndex() << std::endl;
    std::cout << "list2.getIndex(): " << list2.getIndex() << std::endl;
    std::cout << "list2.getInsertArea(): " << list2.getInsertArea() << std::endl;
    std::cout << "list2.getTotalNumberOfIndexes(): " << list2.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Affecting list1 to list2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	list2 = list1;

	////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "list2 copy after affectation" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
    for (it = list2.getList().begin(); it != list2.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    std::cout << std::endl;

    std::cout << "list2.getStart(): " << list2.getStart() << std::endl;
    std::cout << "list2.getEnd(): " << list2.getEnd() << std::endl;
    std::cout << "list2.getNbOfNbs(): " << list2.getNbOfNbs() << std::endl;
    std::cout << "list2.getPrevStepIndex(): " << list2.getPrevStepIndex() << std::endl;
    std::cout << "list2.getCurrentStepIndex(): " << list2.getCurrentStepIndex() << std::endl;
    std::cout << "list2.getIndex(): " << list2.getIndex() << std::endl;
    std::cout << "list2.getInsertArea(): " << list2.getInsertArea() << std::endl;
    std::cout << "list2.getTotalNumberOfIndexes(): " << list2.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Adding one list to list1 should not affect list2" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	subList.push_back(1000);
    subList.push_back(1000);

    list1.getList().push_back(subList);
    subList.clear();

    std::cout << BOLD << WHITE << "List1 after update:" << END << std::endl;
    for (it = list1.getList().begin(); it != list1.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    std::cout << std::endl;

    std::cout << BOLD << WHITE << "List2 after update:" << END << std::endl;
    for (it = list2.getList().begin(); it != list2.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << MAGENTA;
	std::cout << "Adding one list to list2 should not affect list1" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	subList.push_back(400);
    subList.push_back(400);

    list2.getList().push_back(subList);
    subList.clear();

    std::cout << BOLD << WHITE << "List1 after update:" << END << std::endl;
    for (it = list1.getList().begin(); it != list1.getList().end(); ++it)
        std::cout << *(*it).begin() << " " << *(*it).rbegin() << std::endl;
    
    std::cout << std::endl;
    
    std::cout << BOLD << WHITE << "List2 after update:" << END << std::endl;
    for (it = list2.getList().begin(); it != list2.getList().end(); ++it)
        std::cout << *(*it).begin() << " " << *(*it).rbegin() << std::endl;
    
    std::cout << std::endl;
        
    return ;
}

void	testConstructorByCopyList(PmergeMe list1)
{
    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Display of copy list with attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::list< std::list<int> >::iterator   it;
    
    for (it = list1.getList().begin(); it != list1.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "list1.getStart(): " << list1.getStart() << std::endl;
    std::cout << "list1.getEnd(): " << list1.getEnd() << std::endl;
    std::cout << "list1.getNbOfNbs(): " << list1.getNbOfNbs() << std::endl;
    std::cout << "list1.getPrevStepIndex(): " << list1.getPrevStepIndex() << std::endl;
    std::cout << "list1.getCurrentStepIndex(): " << list1.getCurrentStepIndex() << std::endl;
    std::cout << "list1.getIndex(): " << list1.getIndex() << std::endl;
    std::cout << "list1.getInsertArea(): " << list1.getInsertArea() << std::endl;
    std::cout << "list1.getTotalNumberOfIndexes(): " << list1.getTotalNumberOfIndexes() << std::endl;

    std::cout << std::endl;

    return ;
}


void    testListCopyByConstructor()
{
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test List copy by constructor" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of a PmergeMe instance (that will be copied)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
	PmergeMe    list1;

	////////////////////////////////////
	
	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Filling this PmergeMe instance with 5 lists of 2 int each" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::list<int>    subList;

    subList.push_back(65);
    subList.push_back(689);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(34);
    subList.push_back(89);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(879);
    subList.push_back(234);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(7);
    subList.push_back(9);

    list1.getList().push_back(subList);
    subList.clear();

    subList.push_back(65);
    subList.push_back(90);

    list1.getList().push_back(subList);
    subList.clear();

    std::list< std::list<int> >::iterator   it;
    
    for (it = list1.getList().begin(); it != list1.getList().end(); ++it)
        std::cout << *(*it).begin() << "\t" << *(*it).rbegin() << std::endl;
    
    ////////////////////////////////////
    
    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Updating list1 attributes" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    list1.setStart(clock());
    list1.setEnd(clock());
    list1.setNbOfNbs(1);
    list1.setPrevStepIndex(1);
    list1.setCurrentStepIndex(1);
    list1.setIndex(1);
    list1.setInsertArea(1);
    list1.setTotalNumberOfIndexes(1);

    std::cout << "list1.getStart(): " << list1.getStart() << std::endl;
    std::cout << "list1.getEnd(): " << list1.getEnd() << std::endl;
    std::cout << "list1.getNbOfNbs(): " << list1.getNbOfNbs() << std::endl;
    std::cout << "list1.getPrevStepIndex(): " << list1.getPrevStepIndex() << std::endl;
    std::cout << "list1.getCurrentStepIndex(): " << list1.getCurrentStepIndex() << std::endl;
    std::cout << "list1.getIndex(): " << list1.getIndex() << std::endl;
    std::cout << "list1.getInsertArea(): " << list1.getInsertArea() << std::endl;
    std::cout << "list1.getTotalNumberOfIndexes(): " << list1.getTotalNumberOfIndexes() << std::endl;
    
    ////////////////////////////////////

	std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Calling copy constructor" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    testConstructorByCopyList(list1);
        
    return ;
}
