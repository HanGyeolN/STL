#include <iostream>
#include "VectorIterator.hpp"

int		main()
{
	VectorIterator<int>		iter1;
	VectorIterator<int>		iter2(iter1);
	VectorIterator<int>		iter3 = iter2;

	iter1
}