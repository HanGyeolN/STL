#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>

int		main()
{
	std::vector<char>				vec;
	std::vector<char>::iterator		iter;
	std::vector<char>::iterator		end;

	vec.push_back('a');
	iter = vec.begin();
	end = vec.end();

	// std::cout << "begin: " << *iter << "\n";
	// std::cout << "end: " << *end << "\n";
	
	return (0);
}