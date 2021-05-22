#include <iostream>
#include <vector>
#include "Vector.hpp"

template <typename T>
void	show_vector(ft::Vector<T> &vec)
{
	for (typename ft::Vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " [size: " << vec.size() << ", capacity: " << vec.capacity() << "]\n";
}

// Constructor Test
void	constructor_test()
{
	ft::Vector<int> first;                                // empty vector of ints
	ft::Vector<int> second(4, 100);                       // four ints with value 100
	ft::Vector<int> third(second.begin() + 1,second.end());  // iterating through second
	ft::Vector<int> fourth(third);                       // a copy of third
	std::cout << '\n';

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::Vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "first:";
	show_vector(first);

	std::cout << "second:";
	show_vector(second);

	std::cout << "third:";
	show_vector(third);

	std::cout << "fourth:";
	show_vector(fourth);

	std::cout << "fifth:";
	show_vector(fifth);
}

class	Pos
{
public:
	int		_x;
	int		_y;
	Pos(int x, int y)
	{
		_x = x;
		_y = y;
	};
	~Pos()
	{};
};

// Class test
void	class_test()
{
	int						i;
	ft::Vector<Pos>				vec;
	ft::Vector<Pos>::iterator	iter;
	ft::Vector<Pos>::iterator	end;

	vec.push_back(Pos(3, 5));
	vec.push_back(Pos(2, 4));
	iter = vec.begin();
	end = vec.end();

	while (iter != end)
	{
		std::cout << (*iter)._x << ", " << (*iter)._y << "\n";
		iter++;
	}
}

// capacity max case
void	test03()
{
	int						i;
	ft::Vector<int>				vec;
	ft::Vector<int>::iterator	iter;
	ft::Vector<int>::iterator	end;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	i = 0;
	iter = vec.begin();
	end = vec.end();
	while (iter != vec.end())
	{
		std::cout << *iter << "\n";
		iter++;
		i++;
	}
	if (i != 10)
		throw ("test03\n");
}

// capacity max case
void	test01_ex()
{
	int								i;
	std::vector<int>				vec;
	std::vector<int>::iterator		iter;
	std::vector<int>::iterator		end;

	vec.push_back(1);
	i = 0;
	iter = vec.begin();
	end = vec.end();
	while (iter != vec.end())
	{
		std::cout << *iter << "\n";
		iter++;
		i++;
	}
	std::cout << *iter << "\n";
}

// capacity exceed case
void	test04()
{
	int						i;
	ft::Vector<int>				vec;
	ft::Vector<int>::iterator	iter;
	ft::Vector<int>::iterator	end = vec.end();

	for (int i = 0; i < 32; i++)
	{
		vec.push_back(i);
	}
	i = 0;
	iter = vec.begin();
	while (iter != end)
	{
		std::cout << *iter << "\n";
		iter++;
		i++;
	}
	if (i != 32)
		throw ("test04\n");
}

// end를 미리 정하고 값을 집어넣으면?
// 무한루프
void	test04_ex()
{
	int							i;
	std::vector<int>			vec;
	std::vector<int>::iterator	iter;
	std::vector<int>::iterator	end = vec.end();

	for (int i = 0; i < 32; i++)
	{
		vec.push_back(i);
	}
	i = 0;
	iter = vec.begin();
	while (iter != end)
	{
		std::cout << *iter << "\n";
		iter++;
		i++;
		if (i > 32)
			return ;
	}
	if (i != 32)
		throw ("test04\n");
}

// void	input_iterator_test()
// {
// 	int range_array[5] = { 45, 87846, 12, 965, 5 };

// 	std::vector<int>				vec;
// 	std::vector<int>::iterator		iter;
// 	std::vector<int>::iterator		end;

// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);
// 	vec.push_back(5);
// 	vec.push_back(6);
// 	vec.push_back(7);
// 	vec.push_back(8);

// 	iter = vec.rbegin()
// 	end = vec.end();
	
// }

void	reverse_iterator_test()
{
	std::vector<int>				vec;
	std::vector<int>::reverse_iterator		riter;
	std::vector<int>::reverse_iterator		rend;
	std::vector<int>::iterator				iter;
	std::vector<int>::iterator				end;

	ft::Vector<int>								o_vec;
	ft::Vector<int>::reverse_iterator			o_riter;
	ft::Vector<int>::reverse_iterator			o_rend;
	ft::Vector<int>::iterator					o_iter;
	ft::Vector<int>::iterator					o_end;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	o_vec.push_back(1);
	o_vec.push_back(2);
	o_vec.push_back(3);
	o_vec.push_back(4);

	riter = vec.rbegin();
	rend = vec.rend();
	iter = vec.begin();
	end = vec.end();
	if (riter < rend)
		std::cout << "reverse\n";
	if (iter < end)
		std::cout << "iter\n";

	o_riter = o_vec.rbegin();
	o_rend = o_vec.rend();
	o_iter = o_vec.begin();
	o_end = o_vec.end();
	if (o_riter < o_rend)
		std::cout << "o_reverse\n";
	if (o_iter < o_end)
		std::cout << "o_iter\n";
	while (o_riter != o_rend)
	{
		std::cout << *o_riter;
		o_riter++;
	}
}

int		main()
{
	try
	{
		// constructor_test();
		class_test();
	}
	catch(const char *err)
	{
		std::cerr << err << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}