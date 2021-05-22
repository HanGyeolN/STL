#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "Vector.hpp"

class	Human
{
private:
	std::string		_name;
	int				_age;
public:
	Human(const std::string &name, int age)
	{
		_name = name;
		_age = age;
	}
	~Human()
	{}
	void	introduce()
	{
		std::cout << "name: " << _name << " age: " << _age << '\n';
	}
};

void	constructor_test()
{
	ft::Vector<Human>		l;
	

	l.push_back(Human("hna", 29));
	for (ft::Vector<Human>::iterator begin = l.begin(); begin != l.end(); begin++)
	{
		(*begin).introduce();
	}
}

void	constructor_test_answer()
{
	std::vector<Human>	l;
	

	l.push_back(Human("hna", 29));
	for (std::vector<Human>::iterator begin = l.begin(); begin != l.end(); begin++)
	{
		(*begin).introduce();
	}
}

int		main(int argc, char **argv)
{
	if (argc != 1)
	{
		constructor_test_answer();
	}
	else
	{
		constructor_test();
	}
	return (0);
}

