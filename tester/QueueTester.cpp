#include <iomanip>
#include <deque>

#include "list.hpp"
#include "queue.hpp"

int main(void)
{
	{
		std::cout << std::setfill('-') << std::setw(20) << "CONSTRUCT" << std::endl;
		std::deque<int> mydeck (3,100);        // deque with 3 elements
		ft::List<int> mylist (2,200);         // list with 2 elements

		ft::Queue<int> first;                 // empty queue
		ft::Queue<int,std::deque<int> > second (mydeck);       // queue initialized to copy of deque

		ft::Queue<int,ft::List<int> > third; // empty queue with list as underlying container
		ft::Queue<int,ft::List<int> > fourth (mylist);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
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
	{
		std::cout << std::setfill('-') << std::setw(20) << "SIZE" << std::endl;
		ft::Queue<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	{
		std::cout << std::setfill('-') << std::setw(20) << "FRONT" << std::endl;
		ft::Queue<int> myqueue;

		myqueue.push(77);
		myqueue.push(16);

		myqueue.front() -= myqueue.back();    // 77-16=61

		std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
	}
	{
		std::cout << std::setfill('-') << std::setw(20) << "BACK" << std::endl;
		ft::Queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);   // this is now the back

		myqueue.back() -= myqueue.front();

		std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
	}
	{
		std::cout << std::setfill('-') << std::setw(20) << "PUSH" << std::endl;
		ft::Queue<int> myqueue;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myqueue.push (myint);
		} while (myint);

		std::cout << "myqueue contains: ";
		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
		}
		std::cout << '\n';
	}
	{
		std::cout << std::setfill('-') << std::setw(20) << "POP" << std::endl;
		ft::Queue<int> myqueue;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myqueue.push (myint);
		} while (myint);

		std::cout << "myqueue contains: ";
		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
		}
		std::cout << '\n';
	}
}