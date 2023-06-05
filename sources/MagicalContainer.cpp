/**
* this file contains implementation for magical contaier functionality
* @author Lior Vinman
* @since 05/06/2023
*/

#include "MagicalContainer.hpp"


bool MagicalContainer::isPrime(int p)
{
	int i = 2;
	
	if (p <= 1) // base condition
	{
		return false;
	}

	for (; i * i <= p; i++) // iterating until sqrt(p)
	{
		if (p % i == 0)
		{
			return false;
		}
	}

	return true;
}


void MagicalContainer::addElement(int value)
{
	auto magical_iterator = std::lower_bound(container.begin(), container.end(), value);

	container.insert(magical_iterator, value);

	if(isPrime(value) == true)
	{
		int *p = new int(value);
		
		auto magical_iterator_pointer = std::lower_bound(this->primes.begin(),
								 this->primes.end(),
								 p,
								 [](const int* a, const int* b)
								 {
								 	return *a < *b; 
								 });
		
		primes.insert(magical_iterator_pointer, p);
	}
}


void MagicalContainer::removeElement(int value)
{
	for (auto i = container.begin(); i != container.end(); i++) // iterating over container
	{
		if(*i == value)
		{
		    this->container.erase(i); // removing the value
		    
		    return; // breaking function
		}
	}

	throw std::runtime_error("Runtime-error occured.");
}


size_t MagicalContainer::size() const
{
    	return (this->container.size());
}


