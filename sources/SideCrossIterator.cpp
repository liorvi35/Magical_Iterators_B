/**
* this file contains implementations for side cross number iterator for the magical container
* @author Lior Vinman
* @since 05/06/2023
*/

#include "MagicalContainer.hpp"


MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &c) : container(&c), index(0) {}


MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &c, size_t i) : container(&c), index(i) {}


MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &sci) : container(sci.container), index(sci.index) {}


MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &sci)
{
	if (this->container != sci.container)
	{
		throw std::runtime_error("Runtime-error occurred.");
	}

	if (this != &sci)
	{
		this->container = sci.container;
		this->index = sci.index;
	}

	return (*this);
}


bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &sci) const
{
	return (this->index == sci.index);
}


bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &sci) const
{
	return !((*this) == sci);
}


bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &sci) const
{
	return (this->index < sci.index);
}


bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& sci) const
{
	return (this->index > sci.index);
}


int MagicalContainer::SideCrossIterator::operator*()
{
	return (*(this->container)).container[this->side_cross_index];
}


MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
	if (this->index >= (*(this->container)).container.size())
	{
		throw std::runtime_error("Runtime-error occurred.");
	}
	
	++this->index;
	
	if (this->index % 2 != 0)
	{
		side_index = (*(this->container)).container.size() - 1 - this->index / 2;
	}
	else
	{
		side_index = this->index / 2;
	}

	return (*this);
}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
{
	return SideCrossIterator((*this->container), 0);
}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
{
	return SideCrossIterator(*(this->container), (*(this->container)).size());
}


