#include <iostream>
#include <vector>
#include "Vector.hpp"

// normal case
void	test01()
{
	int						i = 0;
	Vector<int>				vec;
	Vector<int>::iterator	iter;
	Vector<int>::iterator	end;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	iter = vec.begin();
	end = vec.end();

	while (iter != end)
	{
		std::cout << *iter << "\n";
		iter++;
		i++;
	}
	// std::cout << *(iter + 12131230) << "\n";
	if (i != 3)
		throw ("test01\n");
}

// empty case
void	test02()
{
	int						i;
	Vector<int>				vec;
	Vector<int>::iterator	iter;
	Vector<int>::iterator	end;

	iter = vec.begin();
	end = vec.end();

	while (iter != end)
	{
		std::cout << *iter << "\n";
		iter++;
		throw ("test02\n");
	}
}

// capacity max case
void	test03()
{
	int						i;
	Vector<int>				vec;
	Vector<int>::iterator	iter;
	Vector<int>::iterator	end;

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

	// for (i = 0; i < 10; i++)
	// {
	// 	vec.push_back(i);
	// }
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
	// if (i != 10)
	// 	throw ("test03\n");
}

// capacity exceed case
void	test04()
{
	int						i;
	Vector<int>				vec;
	Vector<int>::iterator	iter;
	Vector<int>::iterator	end = vec.end();

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

	Vector<int>								o_vec;
	Vector<int>::reverse_iterator			o_riter;
	Vector<int>::reverse_iterator			o_rend;
	Vector<int>::iterator					o_iter;
	Vector<int>::iterator					o_end;

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
		// test01();
		// test02();
		// test03();
		// test04();
		// test04_ex();
		reverse_iterator_test();
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