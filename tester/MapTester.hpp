#ifndef MAP_TESTER_HPP
# define MAP_TESTER_HPP

# include "Map.hpp"
# include <iostream>
# include <iomanip>

namespace map_tester
{
	void	construct_test();
	void	copy_operator_test();
	void	begin_test();
	void	rbegin_test();
	void	empty_test();
	void	size_test();
	void	max_size_test();
	void	operator_test();
	void	insert_test();
	void	erase_test();
	void	swap_test();
	void	clear_test();
	void	key_compare_test();
	void	value_compare_test();
	void	find_test();
	void	count_test();
	void	bound_test();
	void	range_test();
	int		main();
}


#endif