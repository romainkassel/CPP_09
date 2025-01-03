/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:47:29 by debian            #+#    #+#             */
/*   Updated: 2024/12/18 06:34:39 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

// common

PmergeMe::PmergeMe( void ) : 
_nbOfNbs(0),
_prevStepIndex(1),
_currentStepIndex(3),
_index(3),
_insertArea(3),
_totalNumberOfIndexes(0)
{
	//std::cout << "Default constructor (void) from PmergeMe called" << std::endl;
	return ;
}

PmergeMe::PmergeMe( PmergeMe const & src )
{
	std::cout << "Copy constructor from PmergeMe called" << std::endl;

	*this = src;

	return ;
}

PmergeMe::~PmergeMe( void )
{
	//std::cout << "Destructor from PmergeMe called" << std::endl;
	return ;
}

PmergeMe    &PmergeMe::operator=( PmergeMe const & rhs )
{
	std::cout << "Affectation operator from PmergeMe called" << std::endl;

	this->_start = rhs._start;
	this->_end = rhs._end;
    this->_nbOfNbs = rhs._nbOfNbs;
	this->_prevStepIndex = rhs._prevStepIndex;
	this->_currentStepIndex = rhs._currentStepIndex;
	this->_index = rhs._index;
	this->_insertArea = rhs._insertArea;
	this->_totalNumberOfIndexes = rhs._totalNumberOfIndexes;

	std::vector< std::vector<int> >	tmpVector(rhs._vector);
	this->_vector.swap(tmpVector);

	std::list< std::list<int> >		tmpList(rhs._list);
	this->_list.swap(tmpList);

	return (*this);
}

void    PmergeMe::printBefore( char **intSequence )
{
	int	i = 1;

	std::cout << "Before:" << "\t";

	while (intSequence[i])
		std::cout << intSequence[i++] << " ";

	std::cout << std::endl << std::endl;
	
	return ;
}

void    PmergeMe::printTime( std::string container ) const
{
	std::cout << "Time to process a range of " << this->_nbOfNbs - 1 << " elements with std::" << container << ": ";
	std::cout << std::fixed << double(this->_end - this->_start) / double(CLOCKS_PER_SEC) << std::setprecision(5) << " sec" << std::endl;

	std::cout << std::endl;
	
	return ;
}

void	PmergeMe::setEndTime( void )
{
	this->_end = clock();
	return ;
}

const char *PmergeMe::BadIntergerRangeException::what() const throw()
{
	return ("This program must be able to use a positive integer sequence as argument.");
}

const char *PmergeMe::WrongArgNumberException::what() const throw()
{
	return ("At least 1 positive number required as argument.");
}

// vector

void    PmergeMe::printVector( std::string title )
{
	std::vector< std::vector<int> >::iterator	it;
	std::vector<int>::iterator					itSub;

	std::cout << "AFTER: " << title << std::endl << std::endl;

	for (it = this->_vector.begin(); it != this->_vector.end(); ++it)
	{
		std::cout << "{ ";

		for (itSub = (*it).begin(); itSub != (*it).end(); itSub++)
		{
			std::cout << *itSub;
			if (itSub + 1 != (*it).end())
				std::cout << " , ";
		}

		std::cout << " }" << " ";
	}

	std::cout << std::endl << std::endl << std::endl;

	return ;
}

void    PmergeMe::sortNumbersVector( char **intSequence )
{
	this->_start = clock();

	this->splitIntoPairsVector(intSequence);
	//this->printVector("splitIntoPairsVector");
 
	this->sortPairsIndividuallyVector();
	//this->printVector("sortPairsIndividuallyVector");

	//this->sortPairsRecursivelyParamVector(0); // works but stack overflow from ~ 150 numbers
	//this->printVector("sortPairsRecursivelyParamVector");

	//this->sortPairsRecursivelyStaticVector(); // works but stack overflow from ~ 150 numbers
	//this->printVector("sortPairsRecursivelyStaticVector");

	this->sortPairsIterativelyVector();
	//this->printVector("sortPairsIterativelyVector");

	this->insertAIntoMainChainVector();
	//this->printVector("insertAIntoMainChainVector");

	this->insertFirstBIntoMainChainVector();
	//this->printVector("insertFirstBIntoMainChainVector");

	this->getTotalNumberOfIndexesVector();

	if (this->_totalNumberOfIndexes == 1)
		return ;

	if (this->_totalNumberOfIndexes == 2 && (*this->_vector.rbegin()).size() == 1)
	{
		this->insertLastBIntoMainChainVector();
		//this->printVector("insertLastBIntoMainChainVector");
		return ;
	}

	if (this->_totalNumberOfIndexes == 2 || (this->_totalNumberOfIndexes == 3 && (*this->_vector.rbegin()).size() == 1))
	{
		this->_index = 2;
		this->_insertArea = 2;
	}

	this->insertAllBIntoMainChainVector();
	//this->printVector("insertAllBIntoMainChainVector");

	this->insertLastBIntoMainChainVector();
	//this->printVector("insertLastBIntoMainChainVector");

	// (*this->_vector.begin()).insert((*this->_vector.begin()).end(), 1); // test case, sequence not sorted because of last number
	// (*this->_vector.begin()).insert((*this->_vector.begin()).begin(), 100001); // test case, sequence not sorted because of first number

	return ;
}

void    PmergeMe::splitIntoPairsVector( char **intSequence )
{
	std::stringstream	ss;
	long int			nb;
	std::vector<int>	subVector;

	int	i = 1;
	while (intSequence[i])
	{
		ss.clear();
		ss << intSequence[i++];
		ss >> nb;
		if (nb < 1 || nb > INT_MAX)
			throw PmergeMe::BadIntergerRangeException();
		subVector.push_back(nb);
		if ((i != 1 && i % 2 == 1) || (intSequence[i] == NULL))
		{
			this->_vector.push_back(subVector);
			subVector.clear();
		}
	}

	this->_nbOfNbs = i;

	return ;
}

void	PmergeMe::sortPairsIndividuallyVector( void )
{
	std::vector< std::vector<int> >::iterator	it;
	int											tmpNb;

	for (it = this->_vector.begin(); it != this->_vector.end(); ++it)
	{
		if (*it->rbegin() > *it->begin())
		{
			tmpNb = *(it->begin());
			*it->begin() = *it->rbegin();
			*it->rbegin() = tmpNb;
		}
	}

	return ;
}

/*void	PmergeMe::sortPairsRecursivelyParamVector( int index )
{
	if (this->_vector.begin() + index + 1 == this->_vector.end() || (*(this->_vector.begin() + index + 1)).size() == 1)
		return ;

	if (*(*(this->_vector.begin() + index + 1)).begin() >= *(*(this->_vector.begin() + index)).begin())
		return ( this->sortPairsRecursivelyParamVector(index + 1) );
	else
	{
		(*(this->_vector.begin() + index + 1)).swap(*(this->_vector.begin() + index));
		return ( this->sortPairsRecursivelyParamVector(0) );
	}
}*/

/*void	PmergeMe::sortPairsRecursivelyStaticVector( void )
{
	static int	index = 0;

	if (this->_vector.begin() + index + 1 == this->_vector.end() || (*(this->_vector.begin() + index + 1)).size() == 1)
		return ;

	if (*(*(this->_vector.begin() + index + 1)).begin() >= *(*(this->_vector.begin() + index)).begin())
	{
		index++;
		return ( this->sortPairsRecursivelyStaticVector() );
	}
	else
	{
		(*(this->_vector.begin() + index + 1)).swap(*(this->_vector.begin() + index));
		index = 0;
		return ( this->sortPairsRecursivelyStaticVector() );
	}
}*/

void	PmergeMe::sortPairsIterativelyVector( void )
{
	std::vector< std::vector<int> >::iterator	it = this->_vector.begin();
	std::vector< std::vector<int> >::iterator	ite = this->_vector.end();

	while (it + 1 != ite)
	{
		if (*((*it).begin()) <= *(*(it + 1)).begin() || (*(it + 1)).size() == 1)
			it++;
		else
		{
			(*it).swap(*(it + 1));
			it = this->_vector.begin();
		}
	}

	return ;
}

void    PmergeMe::insertAIntoMainChainVector( void )
{
	std::vector<int>							subVector;
	std::vector< std::vector<int> >::iterator	it;
	std::vector<int>::iterator	it2;

	for (it = this->_vector.begin(); it != this->_vector.end(); it++)
		if ((*it).size() == 2)
			subVector.push_back(*(*it).begin());

	this->_vector.insert(this->_vector.begin(), subVector);

	return ;
}

void	PmergeMe::insertFirstBIntoMainChainVector( void )
{
	std::vector< std::vector<int> >::iterator	it = this->_vector.begin();

	(*it).insert((*it).begin(), *(*(it + 1)).rbegin());
	return ;
}

void	PmergeMe::insertPendNumberVector( void )
{
	int		pendNumberToInsert;
	int		itRange;
	bool	numberFound;

	pendNumberToInsert = *(*(this->_vector.begin() + this->_index)).rbegin();

	/*this->printVector("insertAllBIntoMainChainVector");

	std::cout << "pendNumberToInsert: " << pendNumberToInsert << std::endl;
	std::cout << "this->_index: " << this->_index << std::endl;
	std::cout << "this->_currentStepIndex: " << this->_currentStepIndex << std::endl;
	std::cout << "this->_insertArea: " << this->_insertArea << std::endl;*/

	std::vector<int>::iterator	itMainChain = (*this->_vector.begin()).begin();
	std::vector<int>::iterator	iteMainChain = itMainChain + (this->_insertArea - 1);
	std::vector<int>::iterator	itmMainChain;

	numberFound = 0;

	while (numberFound == 0)
	{
		itRange = std::distance(itMainChain, iteMainChain) + 1;
		itmMainChain = itMainChain + (itRange / 2);

		if (itmMainChain == (*this->_vector.begin()).end())
			itmMainChain = iteMainChain;

		/*std::cout << "itRange: " << itRange << std::endl;
		if (itMainChain != (*this->_vector.begin()).end())
			std::cout << "*itMainChain: " << *itMainChain << std::endl;
		std::cout << "*itmMainChain: " << *itmMainChain << std::endl;
		std::cout << "*iteMainChain: " << *iteMainChain << std::endl;
		std::cout << std::endl;*/
	
		if (itRange <= 1 || *itmMainChain == pendNumberToInsert)
		{
			if (*itmMainChain < pendNumberToInsert)
				(*this->_vector.begin()).insert(itmMainChain + 1, pendNumberToInsert);
			else
				(*this->_vector.begin()).insert(itmMainChain, pendNumberToInsert);
			numberFound = 1;
		}
		else if (*itmMainChain < pendNumberToInsert && itRange != 1)
			itMainChain = itmMainChain + 1;
		else
			iteMainChain = itmMainChain - 1;
	}

	return ;
}

void    PmergeMe::getTotalNumberOfIndexesVector( void )
{
	this->_totalNumberOfIndexes = std::distance(this->_vector.begin() + 1, this->_vector.end());

	return ;
}

void	PmergeMe::insertAllBIntoMainChainVector( void )
{
	int	prevStepIndexTmp;

	if (this->_prevStepIndex == this->_currentStepIndex)
		return ;

	while (this->_index > this->_prevStepIndex)
	{
		if ((*(this->_vector.begin() + this->_index)).size() == 2)
			this->insertPendNumberVector();
		this->_index--;
	}

	this->_insertArea *= 2;
	this->_insertArea++;

	prevStepIndexTmp = this->_prevStepIndex;
	this->_prevStepIndex = this->_currentStepIndex;
	this->_currentStepIndex = this->_currentStepIndex + (prevStepIndexTmp * 2);

	if (this->_currentStepIndex > this->_totalNumberOfIndexes)
	{
		this->_insertArea -= (this->_currentStepIndex - this->_totalNumberOfIndexes);
		if ((*this->_vector.rbegin()).size() == 1)
			this->_insertArea--;
		this->_currentStepIndex = this->_totalNumberOfIndexes;
	}
	this->_index = this->_currentStepIndex;

	return (this->insertAllBIntoMainChainVector());
}

void	PmergeMe::insertLastBIntoMainChainVector( void )
{
	if ((*(this->_vector.rbegin())).size() == 2)
		return ;

	this->_index = this->_totalNumberOfIndexes;
	this->_insertArea = (*this->_vector.begin()).size();
	this->insertPendNumberVector();

	return ;
}

void    PmergeMe::testSortedSequenceVector( void )
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite = (*this->_vector.begin()).end();

	std::cout << "Test sorted sequence Vector" << std::endl << std::endl;

	for (it = (*this->_vector.begin()).begin(); it != ite; ++it)
	{
		if ((it + 1) != ite && *it > *(it + 1))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Sequence not sorted!" << std::endl;
			std::cout << "Current number: " << *it << std::endl;
			std::cout << "Next number: " << *(it + 1) << std::endl;
			std::cout << std::endl;
			return ;
		}
		else
			std::cout << *it << " ";
	}

	std::cout << std::endl << std::endl;

	return ;
}

void    PmergeMe::printAfterVector( void )
{
	std::cout << "After:" << "\t";

	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite = (*this->_vector.begin()).end();

	for (it = (*this->_vector.begin()).begin(); it != ite; ++it)
		std::cout << *it << " ";

	std::cout << std::endl << std::endl;

	return ;
}

/// List /// 

void	PmergeMe::sortNumbersList( char **intSequence )
{
	this->_start = clock();

	this->splitIntoPairsList(intSequence);
	//this->printList("splitIntoPairsList");
 
	this->sortPairsIndividuallyList();
	//this->printList("sortPairsIndividuallyList");

	//this->sortPairsRecursivelyParamList(0); // works but stack overflow from ~ 190 numbers
	//this->printVector("sortPairsRecursivelyParamList");

	//this->sortPairsRecursivelyStaticList(); // works but stack overflow from ~ 190 numbers
	//this->printVector("sortPairsRecursivelyStaticList");

	this->sortPairsIterativelyList();
	//this->printList("sortPairsIterativelyList");

	this->insertAIntoMainChainList();
	//this->printList("insertAIntoMainChainList");

	this->insertFirstBIntoMainChainList();
	//this->printList("insertFirstBIntoMainChainList");

	this->getTotalNumberOfIndexesList();

	if (this->_totalNumberOfIndexes == 1)
		return ;

	if (this->_totalNumberOfIndexes == 2 && (*this->_list.rbegin()).size() == 1)
	{
		this->insertLastBIntoMainChainList();
		//this->printList("insertLastBIntoMainChainList");
		return ;
	}

	if (this->_totalNumberOfIndexes == 2 || (this->_totalNumberOfIndexes == 3 && (*this->_list.rbegin()).size() == 1))
	{
		this->_index = 2;
		this->_insertArea = 2;
	}

	this->insertAllBIntoMainChainList();
	//this->printList("insertAllBIntoMainChainList");

	this->insertLastBIntoMainChainList();
	//this->printList("insertLastBIntoMainChainList");

	// (*this->_list.begin()).insert((*this->_list.begin()).end(), 1); // test case, sequence not sorted because of last number
	// (*this->_list.begin()).insert((*this->_list.begin()).begin(), 100001); // test case, sequence not sorted because of first number

	return ;
}

void    PmergeMe::splitIntoPairsList( char **intSequence )
{
	std::stringstream	ss;
	long int			nb;
	std::list<int>		subList;

	int	i = 1;
	while (intSequence[i])
	{
		ss.clear();
		ss << intSequence[i++];
		ss >> nb;
		if (nb < 1 || nb > INT_MAX)
			throw PmergeMe::BadIntergerRangeException();
		subList.push_back(nb);
		if ((i != 1 && i % 2 == 1) || (intSequence[i] == NULL))
		{
			this->_list.push_back(subList);
			subList.clear();
		}
	}

	this->_nbOfNbs = i;

	return ;
}

void    PmergeMe::printList( std::string title )
{
	std::list< std::list<int> >::iterator	it;
	std::list<int>::iterator				itSub;

	std::cout << "AFTER: " << title << std::endl << std::endl;

	for (it = this->_list.begin(); it != this->_list.end(); ++it)
	{
		std::cout << "{ ";

		for (itSub = (*it).begin(); itSub != (*it).end(); itSub++)
		{
			std::cout << *itSub;
            itSub++;
			if (itSub != (*it).end())
				std::cout << " , ";
            itSub--;
		}

		std::cout << " }" << " ";
	}

	std::cout << std::endl << std::endl << std::endl;

	return ;
}

void	PmergeMe::sortPairsIndividuallyList( void )
{
	std::list< std::list<int> >::iterator	it;
	int										tmpNb;

	for (it = this->_list.begin(); it != this->_list.end(); ++it)
	{
		if (*it->rbegin() > *it->begin())
		{
			tmpNb = *(it->begin());
			*it->begin() = *it->rbegin();
			*it->rbegin() = tmpNb;
		}
	}

	return ;
}

/*void	PmergeMe::sortPairsRecursivelyParamList( int index )
{
    std::list< std::list<int> >::iterator	it1 = this->_list.begin();
    std::list< std::list<int> >::iterator	it2 = it1;
	int										i;

    for (i = 0; i < index; ++i)
    {
		it1++;
        it2++;
    }

    it2++;

	if (it2 == this->_list.end() || (*(it2)).size() == 1)
		return ;

	if (*(*(it2)).begin() >= *(*(it1)).begin())
		return ( this->sortPairsRecursivelyParamList(index + 1) );
	else
	{
		(*(it2)).swap(*(it1));
		return ( this->sortPairsRecursivelyParamList(0) );
	}
}*/

/*void	PmergeMe::sortPairsRecursivelyStaticList( void )
{
    std::list< std::list<int> >::iterator	it1 = this->_list.begin();
    std::list< std::list<int> >::iterator	it2 = it1;
	static int	                            index = 0;
	int										i;

    for (i = 0; i < index; ++i)
    {
		it1++;
        it2++;
    }

    it2++;

	if (it2 == this->_list.end() || (*(it2)).size() == 1)
		return ;

	if (*(*(it2)).begin() >= *(*(it1)).begin())
	{
		index++;
		return ( this->sortPairsRecursivelyStaticList() );
	}
	else
	{
		(*(it2)).swap(*(it1));
		index = 0;
		return ( this->sortPairsRecursivelyStaticList() );
	}
}*/

void	PmergeMe::sortPairsIterativelyList( void )
{
	std::list< std::list<int> >::iterator	it = this->_list.begin();
	std::list< std::list<int> >::iterator	ite = this->_list.end();
    int                                     tmpNb;
    std::list< std::list<int> >::iterator   tmpSubList;        

	ite--;
	while (it != ite)
	{
        tmpNb = *((*it).begin());
        tmpSubList = it;
        it++;
		if (tmpNb <= *(*(it)).begin() || (*(it)).size() == 1)
			continue;
		else
		{
			(*it).swap(*tmpSubList);
			it = this->_list.begin();
		}
	}

	return ;
}

void    PmergeMe::insertAIntoMainChainList( void )
{
	std::list<int>							subList;
	std::list< std::list<int> >::iterator	it;
	std::list<int>::iterator				it2;

	for (it = this->_list.begin(); it != this->_list.end(); it++)
		if ((*it).size() == 2)
			subList.push_back(*(*it).begin());

	this->_list.insert(this->_list.begin(), subList);

	return ;
}

void	PmergeMe::insertFirstBIntoMainChainList( void )
{
	std::list< std::list<int> >::iterator	it = this->_list.begin();

    it++;
	(*this->_list.begin()).insert((*this->_list.begin()).begin(), *(*(it)).rbegin());
	return ;
}

void    PmergeMe::getTotalNumberOfIndexesList( void )
{
    std::list< std::list<int> >::iterator	it = this->_list.begin();

    it++;
	this->_totalNumberOfIndexes = std::distance(it, this->_list.end());

	return ;
}

void	PmergeMe::insertLastBIntoMainChainList( void )
{
	if ((*(this->_list.rbegin())).size() == 2)
		return ;

	this->_index = this->_totalNumberOfIndexes;
	this->_insertArea = (*this->_list.begin()).size();
	this->insertPendNumberList();

	return ;
}

void	PmergeMe::insertPendNumberList( void )
{
	int		pendNumberToInsert;
	int		itRange;
	bool	numberFound;
	int		i;

	std::list< std::list<int> >::iterator it = this->_list.begin();

	for (i = 0; i < this->_index; ++i)
		it++;

	pendNumberToInsert = *(*it).rbegin();

	/*this->printList("insertAllBIntoMainChainList");

	std::cout << "pendNumberToInsert: " << pendNumberToInsert << std::endl;
	std::cout << "this->_index: " << this->_index << std::endl;
	std::cout << "this->_currentStepIndex: " << this->_currentStepIndex << std::endl;
	std::cout << "this->_insertArea: " << this->_insertArea << std::endl;*/

	std::list<int>::iterator	itMainChain = (*this->_list.begin()).begin();
	std::list<int>::iterator	iteMainChain = itMainChain;
	std::list<int>::iterator	itmMainChain;

	for (i = 0; i < (this->_insertArea - 1); ++i)
		iteMainChain++;

	numberFound = 0;

	while (numberFound == 0)
	{
		itRange = std::distance(itMainChain, iteMainChain) + 1;
		itmMainChain = itMainChain;

		for (i = 0; i < (itRange / 2); ++i)
			itmMainChain++;

		if (itmMainChain == (*this->_list.begin()).end())
			itmMainChain = iteMainChain;

		/*std::cout << "itRange: " << itRange << std::endl;
		if (itMainChain != (*this->_list.begin()).end())
			std::cout << "*itMainChain: " << *itMainChain << std::endl;
		std::cout << "*itmMainChain: " << *itmMainChain << std::endl;
		std::cout << "*iteMainChain: " << *iteMainChain << std::endl;
		std::cout << std::endl;*/
	
		if (itRange <= 1 || *itmMainChain == pendNumberToInsert)
		{
			if (*itmMainChain < pendNumberToInsert)
            {
                itmMainChain++;
				(*this->_list.begin()).insert(itmMainChain--, pendNumberToInsert);
            }
			else
				(*this->_list.begin()).insert(itmMainChain, pendNumberToInsert);
			numberFound = 1;
		}
		else if (*itmMainChain < pendNumberToInsert && itRange != 1)
		{
			itMainChain = itmMainChain;
			itMainChain++;
			if (*itMainChain > *iteMainChain)
				itMainChain--;
		}
		else
		{
			iteMainChain = itmMainChain;
			iteMainChain--;
		}
	}

	return ;
}

void	PmergeMe::insertAllBIntoMainChainList( void )
{
	std::list< std::list<int> >::iterator	it;
	int										prevStepIndexTmp;
	int										i;

	if (this->_prevStepIndex == this->_currentStepIndex)
		return ;

	while (this->_index > this->_prevStepIndex)
	{
		it = this->_list.begin();

		for (i = 0; i < this->_index; ++i)
			it++;

		if ((*(it)).size() == 2)
			this->insertPendNumberList();
		this->_index--;
	}

	this->_insertArea *= 2;
	this->_insertArea++;

	prevStepIndexTmp = this->_prevStepIndex;
	this->_prevStepIndex = this->_currentStepIndex;
	this->_currentStepIndex = this->_currentStepIndex + (prevStepIndexTmp * 2);

	if (this->_currentStepIndex > this->_totalNumberOfIndexes)
	{
		this->_insertArea -= (this->_currentStepIndex - this->_totalNumberOfIndexes);
		if ((*this->_list.rbegin()).size() == 1)
			this->_insertArea--;
		this->_currentStepIndex = this->_totalNumberOfIndexes;
	}
	this->_index = this->_currentStepIndex;

	return (this->insertAllBIntoMainChainList());
}


void    PmergeMe::testSortedSequenceList( void )
{
	std::list<int>::iterator	it;
	std::list<int>::iterator	ite = (*this->_list.begin()).end();
    int                         tmpNb;

	std::cout << "Test sorted sequence List" << std::endl << std::endl;

	for (it = (*this->_list.begin()).begin(); it != ite; ++it)
	{
        tmpNb = *it++;
		if ((it) != ite && tmpNb > *(it))
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Sequence not sorted!" << std::endl;
			std::cout << "Current number: " << tmpNb << std::endl;
			std::cout << "Next number: " << *(it) << std::endl;
			std::cout << std::endl;
			return ;
		}
		else
			std::cout << tmpNb << " ";
        it--;
	}

	std::cout << std::endl << std::endl;

	return ;
}

void    PmergeMe::printAfterList( void )
{
	std::cout << "After:" << "\t";

	std::list<int>::iterator	it;
	std::list<int>::iterator	ite = (*this->_list.begin()).end();

	for (it = (*this->_list.begin()).begin(); it != ite; ++it)
		std::cout << *it << " ";

	std::cout << std::endl << std::endl;

	return ;
}

// getters for copy tests

std::vector< std::vector<int> > &PmergeMe::getVector( void ) { return (this->_vector); }
std::list< std::list<int> >		&PmergeMe::getList( void ) { return (this->_list); }
clock_t	PmergeMe::getStart( void ) const { return (this->_start); }
clock_t	PmergeMe::getEnd( void ) const { return (this->_end); }
int		PmergeMe::getNbOfNbs( void ) const { return (this->_nbOfNbs); }
int     PmergeMe::getPrevStepIndex( void ) const { return (this->_prevStepIndex); }
int     PmergeMe::getCurrentStepIndex( void ) const { return (this->_currentStepIndex); }
int     PmergeMe::getIndex( void ) const { return (this->_index); }
int    	PmergeMe::getInsertArea( void ) const { return (this->_insertArea); }
int     PmergeMe::getTotalNumberOfIndexes( void ) const { return (this->_totalNumberOfIndexes); }

// setters for copy tests

void    PmergeMe::setStart( clock_t start ) { this->_start = start; }
void    PmergeMe::setEnd( clock_t end ) { this->_end = end; }
void    PmergeMe::setNbOfNbs( int nbOfNbs ) { this->_nbOfNbs = nbOfNbs; }
void    PmergeMe::setPrevStepIndex( int prevStepIndex ) { this->_prevStepIndex = prevStepIndex; }
void    PmergeMe::setCurrentStepIndex( int currentStepIndex ) { this->_currentStepIndex = currentStepIndex; }
void    PmergeMe::setIndex( int index ) { this->_index = index; }
void    PmergeMe::setInsertArea( int insertArea ) { this->_insertArea = insertArea; }
void    PmergeMe::setTotalNumberOfIndexes( int totalNumberOfIndexes ) { this->_totalNumberOfIndexes = totalNumberOfIndexes; }