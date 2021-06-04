#ifndef QUEUE_TESTER_HPP
# define QUEUE_TESTER_HPP

#include <iomanip>
#include <deque>
#include <list>
#include "Queue.hpp"
#include <iostream>

namespace queue_tester
{
	void	construct_test();
	void	empty_test();
	void	size_test();
	void	front_test();
	void	back_test();
	void	push_test();
	void	pop_test();
	int		main();
}

#endif