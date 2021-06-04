#include "QueueTester.hpp"

namespace queue_tester
{
	void		construct_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "CONSTRUCT" << std::endl;
		std::deque<int> mydeck (3,100);        // deque with 3 elements
		std::list<int> mylist (2,200);         // list with 2 elements

		ft::Queue<int> first;                 // empty queue
		ft::Queue<int,std::deque<int> > second (mydeck);       // queue initialized to copy of deque

		ft::Queue<int,std::list<int> > third; // empty queue with list as underlying container
		ft::Queue<int,std::list<int> > fourth (mylist);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}

	void		empty_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "EMPTY" << std::endl;
		ft::Queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
			sum += myqueue.front();
			myqueue.pop();
		}

		std::cout << "total: " << sum << '\n';
	}

	void		size_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "SIZE" << std::endl;
		ft::Queue<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}

	void		front_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "FRONT" << std::endl;
		ft::Queue<int> myqueue;

		myqueue.push(77);
		myqueue.push(16);

		myqueue.front() -= myqueue.back();    // 77-16=61

		std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
	}

	void		back_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "BACK" << std::endl;
		ft::Queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);   // this is now the back

		myqueue.back() -= myqueue.front();

		std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
	}

	void		push_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "PUSH" << std::endl;
		ft::Queue<int> myqueue;
		int myint;

		for (myint = 3; myint < 10; ++myint)
		{
			std::cout << myint << '\n';
			myqueue.push(myint);
		}

	}

	void		pop_test()
	{
		std::cout << std::setfill('-') << std::setw(20) << "POP" << std::endl;
		ft::Queue<int> myqueue;
		int myint;

		for (myint = 3; myint < 10; ++myint)
			myqueue.push(myint);

		while (!myqueue.empty())
		{
			std::cout << myqueue.front() << '\n';
			myqueue.pop();
		}
		std::cout << '\n';
	}

	int main(void)
	{
		construct_test();
		empty_test();
		size_test();
		front_test();
		back_test();
		push_test();
		pop_test();
		
		return (0);
	}
}