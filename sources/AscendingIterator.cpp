/**
* this file contains implementations for ascending number iterator for the magical container
* @author Lior Vinman
* @since 05/06/2023
*/

#include "MagicalContainer.hpp"

// ctor 1
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &c) : container(&c), index(0) {}

// ctor 2
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &c, size_t i) : container(&c), index(i) {}

// ctor 3
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &ai) : container(ai.container), index(ai.index) {}

// ctor 4
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator &ai)
{
	if(this->container != ai.container) // if sub containers are not comparable (not same), throw
	{
		throw std::runtime_error("Runtime-error occurred.");
	}
	
	if(this != &ai)
	{
		this->container = ai.container;
		this->index = ai.index;
	}
	
	return (*this);
}


bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &ai) const
{
	return (this->index == ai.index);
}


bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &ai) const
{
	return !((*this) == ai);
}


bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &ai) const
{
	return (this->index < ai.index);
}


bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& ai) const
{
	return (this->index > ai.index);
}


int MagicalContainer::AscendingIterator::operator*()
{
	return (*this->container).container[this->index];
}


MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
	this->index++;
	
	if(index > (*container).container.size())
	{
		throw std::runtime_error("Runtime-error occured.");
	}
	
	return (*this);
}


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
{
	return AscendingIterator(*this);
}


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
{
	return AscendingIterator(*(this->container), (*(this->container)).size());
}


