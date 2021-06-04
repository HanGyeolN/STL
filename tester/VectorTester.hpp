#ifndef VECTOR_TESTER_HPP
# define VECTOR_TESTER_HPP

#include "Vector.hpp"
#include <vector>
#include <iomanip>
#include <iostream>

namespace vector_tester
{
	void	constructor_test();
	void	copy_operator_test();
	void	begin_test();
	void	end_test();
	void	rbegin_test();
	void	rend_test();
	void	size_test();
	void	max_size_test();
	void	resize_test();
	void	capacity_test();
	void	empty_test();
	void	reserve_test();
	void	operator_test();
	void	at_test();
	void	front_test();
	void	back_test();
	void	assign_test();
	void	push_back_test();
	void	pop_back_test();
	void	insert_test();
	void	erase_test();
	void	swap_test();
	void	clear_test();
	void	relational_test();
	void	swap_test();
	void	erase_test();
	int		main();
}

#endif