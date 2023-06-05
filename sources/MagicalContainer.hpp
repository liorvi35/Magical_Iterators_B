/**
* this file contains declarations for magical container
* @author Lior Vinman
* @since 05/06/2023
*/

#ifndef MAGICAL_CONTAINER_HPP
	
	/**
	* flag to insure header is not included more than once in total
	*/
	#define MAGICAL_CONTAINER_HPP
	
	#include <iostream>
	#include <vector>
	#include <algorithm>
	
	/**
	* mentioning the namespace
	*/
	namespace ariel {}
	
	
	/**
	* class for magical container, including all the values
	*/
	class MagicalContainer
	{
		public:
		
			/**
			* used to store all literals
			*/
			std::vector<int> container;
			
			/**
			* used to store all prime literals
			*/
			std::vector<int*> primes;

			/**
			* standard ctor
			*/
			MagicalContainer() {}
			
			/**
			* non-default destructor
			*/
			~MagicalContainer()
			{
				for (int* ptr : primes)
				{
					delete ptr;
				}
			}
			
			/**
			* adding elem to container
			*/
			void addElement(int);
			
			/**
			* removing elem from container
			*/
			void removeElement(int);
			
			/**
			* getter for container's size
			*/
			size_t size() const;
			
			/**
			* checking if given number is a prime
			*/
			bool isPrime(int);
			
			/**
			* ascending iterator over magical container
			*/
			class AscendingIterator
			{
				public:
					
					/**
					* address of magical container to iterate over it
					*/
					MagicalContainer *container;
					
					/**
					* index
					*/
					size_t index;
					
					/**
					* type
					*/
					int type = 1;

					/**
					* default ctor
					*/
					AscendingIterator(MagicalContainer&);
					
					/**
					* building ctor
					*/
					AscendingIterator(MagicalContainer&, size_t);
					
					/**
					* copy ctor
					*/
					AscendingIterator(const AscendingIterator&);
					
					/**
					* defaultive destructor
					*/
					~AscendingIterator() {}
					
					/**
					* iterator begin
					*/
					AscendingIterator begin() const;
					
					/**
					* iterator end
					*/
					AscendingIterator end() const;

					/**
					* application operator
					*/
					AscendingIterator& operator=(const AscendingIterator&);
					
					/**
					* equallity operator
					*/
					bool operator==(const AscendingIterator&) const;
				
					/**
					* non-equallity operator
					*/	
					bool operator!=(const AscendingIterator&) const;
					
					/**
					* `smaller` operator
					*/
					bool operator<(const AscendingIterator&) const;
					
					/**
					* `bigger` operator
					*/
					bool operator>(const AscendingIterator&) const;
					
					/**
					* multiplication operator
					*/
					int operator*();
					
					/**
					* `advance` operator
					*/
					AscendingIterator& operator++();
			};
			
			/**
			* prime iterator over magical container
			*/
			class PrimeIterator
			{
				public:
					
					/**
					* address of magical container to iterate over it
					*/
					MagicalContainer* container;
					
					/**
					* index
					*/
					size_t index;
					
					/**
					* type
					*/
					int type = 2;

					/**
					* default ctor
					*/
					PrimeIterator(MagicalContainer&);
					
					/**
					* building ctor
					*/	
					PrimeIterator(MagicalContainer&, size_t);
					
					/**
					* copy ctor
					*/
					PrimeIterator(const PrimeIterator&);
					
					/**
					* defaultive destructor
					*/
					~PrimeIterator() {}

					/**
					* iterator begin
					*/
					PrimeIterator begin() const;
					
					/**
					* iterator end
					*/
					PrimeIterator end() const;

					/**
					* application operator
					*/
					PrimeIterator& operator=(const PrimeIterator&);
					
					/**
					* equallity operator
					*/
					bool operator==(const PrimeIterator&) const;
					
					/**
					* non-equallity operator
					*/
					bool operator!=(const PrimeIterator&) const;
					
					/**
					* `smaller` operator
					*/					
					bool operator<(const PrimeIterator&) const;

					/**
					* `bigger` operator
					*/					
					bool operator>(const PrimeIterator&) const;

					/**
					* multiplication operator
					*/					
					int operator*();

					/**
					* `advance` operator
					*/					
					PrimeIterator& operator++();
			};
			
			/**
			* side cross iterator over magical container
			*/
			class SideCrossIterator
			{
				public:
					
					/**
					* address of magical container to iterate over it
					*/
					MagicalContainer* container;
					
					/**
					* index
					*/
					size_t index;
					
					/**
					* side cross index
					*/
					size_t side_cross_index;
					
					/**
					* default ctor
					*/
					SideCrossIterator(MagicalContainer&);
					
					/**
					* building ctor
					*/	
					SideCrossIterator(MagicalContainer&, size_t);
					
					/**
					* copy ctor
					*/
					SideCrossIterator(const SideCrossIterator&);
					
					/**
					* defaultive destructor
					*/
					~SideCrossIterator() {}
					
					/**
					* iterator begin
					*/
					SideCrossIterator begin() const;
					
					/**
					* iterator end
					*/
					SideCrossIterator end() const;

					/**
					* application operator
					*/
					SideCrossIterator& operator=(const SideCrossIterator&);
					
					/**
					* equallity operator
					*/
					bool operator==(const SideCrossIterator&) const;
					
					/**
					* non-equallity operator
					*/
					bool operator!=(const SideCrossIterator&) const;
					
					/**
					* `smaller` operator
					*/
					bool operator<(const SideCrossIterator&) const;
					
					/**
					* `bigger` operator
					*/
					bool operator>(const SideCrossIterator&) const;
					
					/**
					* multiplication operator
					*/
					int operator*();
					
					/**
					* `advance` operator
					*/
					SideCrossIterator& operator++();
			};
	};
	
	
#endif

