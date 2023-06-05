/**
* this file contains implementations for prime number iterator for the magical container
* @author Lior Vinman
* @since 05/06/2023
*/

#include "MagicalContainer.hpp"


// ctor 1
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &c) : container(&c), index(0) {}


// ctor 2
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &c, size_t i) : container(&c), index(i) {}


// ctor 3
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &pi) : container(pi.container), index(pi.index) {}


// ctor 4
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator &pi)
{
	if (this->container != pi.container) // if sub containers are not comparable (not same), throw
	{
		throw std::runtime_error("Runtime-error occurred.");
	}

	if (this != &pi) // checking if address are not same
	{
		this->container = pi.container;
		this->index = pi.index;
	}

	return (*this);
}


// comparing operator
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &pi) const
{
	return (this->index == pi.index);
}

// not-equal operator
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &pi) const
{
	return !((*this) == pi);
}

// smaller operator
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &pi) const
{
	return (this->index < pi.index);
}

// bigger operator
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& pi) const
{
	return (this->index > pi.index);
}


int MagicalContainer::PrimeIterator::operator*()
{
	return *(*(this->container)).primes[this->index];
}

// advancing operator
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
	this->index++; // continue to next literal 

	if (index > (*container).primes.size()) // if wanting to go over top bound
	{
		throw std::runtime_error("Runtime-error occurred.");
	}

	return (*this);
}

// begin
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
{
	return PrimeIterator(*this);
}

// end
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
{
	return PrimeIterator(*(this->container), (*(this->container)).primes.size());
}


