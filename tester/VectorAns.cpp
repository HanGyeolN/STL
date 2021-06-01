#include <vector>
#include <iomanip>
#include <iostream>

void		constructor_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "CONSTRUCT" << std::endl;
	std::vector<int> first;                                // empty Vector of ints
	std::vector<int> second (4,100);              // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::cout << "fifth" << std::endl;
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		copy_operator_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "OPERATOR=" << std::endl;
		std::vector<int> foo (3,0);
		std::vector<int> bar (5,0);

		bar = foo;
		foo = std::vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void		begin_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "BEGIN" << std::endl;
	std::vector<int> myVector;
	for (int i=1; i<=5; i++) myVector.push_back(i);

	std::cout << "myVector contains:";
	for (std::vector<int>::iterator it = myVector.begin() ; it != myVector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		end_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "END" << std::endl;
	std::vector<int> myVector;
	for (int i=1; i<=5; i++) myVector.push_back(i);

	std::cout << "myVector contains:";
	for (std::vector<int>::iterator it = myVector.begin() ; it != myVector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		rbegin_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "RBEGIN" << std::endl;
	std::vector<int> myVector (5);  // 5 default-constructed ints

	int i=0;

	std::vector<int>::reverse_iterator rit = myVector.rbegin();
	for (; rit!= myVector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myVector contains:";
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		rend_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "REND" << std::endl;
	std::vector<int> myVector (5);  // 5 default-constructed ints

	std::vector<int>::reverse_iterator rit = myVector.rbegin();

	int i=0;
	for (rit = myVector.rbegin(); rit!= myVector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myVector contains:";
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		size_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "SIZE" << std::endl;
	std::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void		max_size_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "MAX_SIZE" << std::endl;
	std::vector<int> myVector;

	// set some content in the Vector:
	for (int i=0; i<100; i++) myVector.push_back(i);

	std::cout << "size: " << myVector.size() << "\n";
	std::cout << "capacity: " << myVector.capacity() << "\n";
	std::cout << "max_size: " << myVector.max_size() << "\n";
}

void		resize_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "RESIZE" << std::endl;
	std::vector<int> myVector;

	// set some initial content:
	for (std::size_t i=1;i<10;i++) myVector.push_back(i);

	myVector.resize(5);
	myVector.resize(8,100);
	myVector.resize(12);

	std::cout << "myVector contains:";
	for (std::size_t i=0;i<myVector.size();i++)
		std::cout << ' ' << myVector[i];
	std::cout << '\n';
}

void		capacity_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "CAPACITY" << std::endl;
	std::vector<int> myVector;

	// set some content in the Vector:
	for (int i=0; i<100; i++) myVector.push_back(i);

	std::cout << "size: " << (int) myVector.size() << '\n';
	std::cout << "capacity: " << (int) myVector.capacity() << '\n';
	std::cout << "max_size: " << (int) myVector.max_size() << '\n';
}

void		empty_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "EMPTY" << std::endl;
	std::vector<int> myVector;
	int sum (0);

	for (int i=1;i<=10;i++) myVector.push_back(i);

	while (!myVector.empty())
	{
		sum += myVector.back();
		myVector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
}

void		reserve_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "RESERVE" << std::endl;
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		// std::cout << "i: " << i << ", cap: " << foo.capacity() << ", size: " << foo.size() << '\n';
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void		operator_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "OPERATOR[]" << std::endl;
	std::vector<int> myVector (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz = myVector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myVector[i]=i;

	// reverse Vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myVector[sz-1-i];
		myVector[sz-1-i]=myVector[i];
		myVector[i]=temp;
	}

	std::cout << "myVector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myVector[i];
	std::cout << '\n';
}

void		at_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "AT" << std::endl;
	std::vector<int> myVector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myVector.size(); i++)
		myVector.at(i)=i;

	std::cout << "myVector contains:";
	for (unsigned i=0; i<myVector.size(); i++)
		std::cout << ' ' << myVector.at(i);
	std::cout << '\n';
}

void		front_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "FRONT" << std::endl;
	std::vector<int> myVector;

	myVector.push_back(78);
	myVector.push_back(16);

	// now front equals 78, and back 16

	myVector.front() -= myVector.back();

	std::cout << "myVector.front() is now " << myVector.front() << '\n';
}

void		back_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "BACK" << std::endl;
	std::vector<int> myVector;

	myVector.push_back(10);

	while (myVector.back() != 0)
	{
		myVector.push_back ( myVector.back() -1 );
	}

	std::cout << "myVector contains:";
	for (unsigned i=0; i<myVector.size() ; i++)
		std::cout << ' ' << myVector[i];
	std::cout << '\n';
}

void		assign_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "ASSIGN" << std::endl;
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}

void		push_back_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "PUSH_BACK" << std::endl;
	std::vector<int> myVector;

	for (int i = 0; i < 10; ++i)
		myVector.push_back (i);

	std::cout << "myVector stores " << int(myVector.size()) << " numbers.\n";
}

void		pop_back_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "POP_BACK" << std::endl;
	std::vector<int> myVector;
	int sum (0);
	myVector.push_back (100);
	myVector.push_back (200);
	myVector.push_back (300);

	while (!myVector.empty())
	{
		sum+=myVector.back();
		myVector.pop_back();
	}

	std::cout << "The elements of myVector add up to " << sum << '\n';
}

template <typename T>
void		show(const std::vector<T>	&vec)
{
	typename 	std::vector<T>::iterator	iter;

	iter = vec.begin();
	std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << '\n';
	if (vec.size() != 0)
	{
		std::cout << "container: ";
		while (iter != vec.end())
		{
			std::cout << *iter << " ";
			++iter;
		}
		std::cout << '\n';
	}
}

void		insert_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "INSERT" << std::endl;
	std::vector<int> myVector (3,100);
	std::vector<int>::iterator it;

	it = myVector.begin();
	it = myVector.insert ( it , 200 );

	myVector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myVector.begin();

	std::vector<int> anotherVector (2,400);
	myVector.insert (it+2,anotherVector.begin(),anotherVector.end());

	int myarray [] = { 501,502,503 };
	myVector.insert (myVector.begin(), myarray, myarray+3);

	std::cout << "myVector contains:";
	for (it=myVector.begin(); it<myVector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		clear_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "CLEAR" << std::endl;
	std::vector<int> myVector;
	myVector.push_back (100);
	myVector.push_back (200);
	myVector.push_back (300);

	std::cout << "myVector contains:";
	for (unsigned i=0; i<myVector.size(); i++)
		std::cout << ' ' << myVector[i];
	std::cout << '\n';

	myVector.clear();
	myVector.push_back (1101);
	myVector.push_back (2202);

	std::cout << "myVector contains:";
	for (unsigned i=0; i<myVector.size(); i++)
		std::cout << ' ' << myVector[i];
	std::cout << '\n';
}

void		relational_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "RELATIONAL" << std::endl;
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void		swap_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "SWAP" << std::endl;
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		erase_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "ERASE" << std::endl;
	std::vector<int>		a;
	std::vector<int>	b;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	std::cout << "a: " << a.size() << '\n';
	std::cout << "b: " << b.size() << '\n';

	while (a.size())
	{
		std::cout << a.front() << " ";
		a.erase(a.begin());
	}

	while (b.size())
	{
		std::cout << b.front() << " ";
		b.erase(b.begin());
	}
}

int main(void)
{
	constructor_test();

	copy_operator_test();

	begin_test();

	end_test();

	rbegin_test();

	rend_test();

	size_test();

	max_size_test();

	resize_test();

	capacity_test();

	empty_test();

	reserve_test();

	operator_test();

	at_test();

	front_test();

	back_test();

	assign_test();

	push_back_test();

	pop_back_test();

	insert_test();

	erase_test();

	swap_test();

	clear_test();

	relational_test();

	swap_test();

	erase_test();

	return (0);
}