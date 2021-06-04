#include "StackTester.hpp"

namespace stack_tester
{
	void	construct_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "CONSTRUCT" << std::endl;
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		ft::Stack<int> first;                    				// empty stack
		ft::Stack< int, std::deque<int> > second (mydeque);        	 // stack initialized to copy of deque

		ft::Stack<int,std::vector<int> > third;  // empty stack using vector
		ft::Stack<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}

	void	empty_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "EMPTY" << std::endl;
		ft::Stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}

	void	size_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "SIZE" << std::endl;
		ft::Stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}

	void	top_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "TOP" << std::endl;
		ft::Stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}

	void	push_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "PUSH" << std::endl;
		ft::Stack<int> mystack;
		int	myint;

		for (myint = 3; myint < 10; ++myint)
		{
			std::cout << myint << '\n';
			mystack.push(myint);
		}
		std::cout << '\n';
	}

	void	pop_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "POP" << std::endl;
		ft::Stack<int> mystack;
		int		myint;

		
		for (myint = 3; myint < 10; ++myint)
		{
			mystack.push(myint);
		}

		while (!mystack.empty())
		{
			std::cout << mystack.top() << '\n';
			mystack.pop();
		}
		std::cout << '\n';
	}

	int main(void)
	{
		construct_test();
		empty_test();
		size_test();
		top_test();
		push_test();
		pop_test();

		return (0);
	}
}