#ifndef LIST_TESTER_HPP
# define LIST_TESTER_HPP

# include "List.hpp"
# include <list>
# include <iostream>
# include <iomanip>
# include <vector>
# include <cmath>
# include <iterator>

namespace list_tester
{
	void	construct_test();
	void	copy_operator_test();
	void	begin_test();
	void	end_test();
	void	rbegin_test();
	void	rend_test();
	void	empyt_test();
	void	size_test();
	void	max_size_test();
	void	front_test();
	void	back_test();
	void	assign_test();
	void	push_front_test();
	void	pop_front_test();
	void	push_back_test();
	void	pop_back_test();
	void	insert_test();
	void	erase_test();
	void	swap_test();
	void	resize_test();
	void	clear_test();
	void	splice_test();
	void	remove_test();
	void	remove_if_test();
	void	unique_test();
	void	merge_test();
	void	sort_test();
	void	reverse_test();
	void	relational_test();
	void	non_mem_swap_test();
	int		main();
}

#endif