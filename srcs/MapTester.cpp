#include <iostream>
#include <string>
#include <map>

typedef std::map<std::string, std::string>		string_map;


int		main()
{
	string_map				map;
	string_map::iterator	iter;

	map.insert(std::pair<std::string, std::string>("key", "val"));
	iter = map.begin();
	std::cout << iter->first << '\n';

	return (0);
}