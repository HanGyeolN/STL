#include <list>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <iterator>

bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (std::fabs(first-second)<5.0); }
};

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

template <typename T>
void	show_list(std::list<T> &l)
{
	typename std::list<T>::iterator			iter;
	std::cout << "size: " << l.size() << "\n";
	
	// std::cout << l._begin;
	iter = l.begin();
	while (iter != l.end())
	{
		// std::cout << "a";
		std::cout << *iter << " ";
		++iter;
	}
	std::cout << "\n------------------------------------\n";
}

void		construct_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "CONSTRUCT" << std::endl;
	std::list<int> first;                                // empty list of ints
	// show_list(first);
	std::list<int> second (4,100);   // four ints with value 100
	show_list(second);
	std::list<int> third (second.begin(),second.end());  // iterating through second
	show_list(third);
	std::list<int> fourth (third);                       // a copy of third
	show_list(fourth);

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fourth are: ";
	for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';

	std::cout << '\n';
}

void		copy_operator_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "OPERATOR=" << std::endl;
	std::list<int> first (3);      // list of 3 zero-initialized ints
	show_list(first);
	std::list<int> second (5);     // list of 5 zero-initialized ints
	show_list(second);

	second = first;
	show_list(second);

	first = std::list<int>();
	show_list(first);
	show_list(second);

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
}

void		begin_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "BEGIN" << std::endl;
	int myints[] = {75,23,65,42,13};
	std::list<int> mylist (myints,myints+5);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void		end_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "END" << std::endl;
	int myints[] = {75,23,65,42,13};
	std::list<int> mylist (myints,myints+5);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void		rbegin_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "RBEGIN" << std::endl;
	std::list<int> mylist;
	for (int i=1; i<=5; ++i) mylist.push_back(i);

	std::cout << "mylist backwards:";
	for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;

	std::cout << '\n';
}

void		rend_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "REND" << std::endl;
	std::list<int> mylist;
	for (int i=1; i<=5; ++i) mylist.push_back(i);

	std::cout << "mylist backwards:";
	for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;

	std::cout << '\n';
}

void		empyt_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "EMPTY" << std::endl;
	std::list<int> mylist;
	int sum (0);

	for (int i=1;i<=10;++i) mylist.push_back(i);

	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}

	std::cout << "total: " << sum << '\n';
}

void		size_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "SIZE" << std::endl;
	std::list<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.begin(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void		max_size_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "MAX_SIZE" << std::endl;
	std::cout << "max_size(): " << std::list<int>().max_size() << std::endl;
}

void		front_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "FRONT" << std::endl;
	std::list<int> mylist;

	mylist.push_back(77);
	mylist.push_back(22);

	// now front equals 77, and back 22

	mylist.front() -= mylist.back();

	std::cout << "mylist.front() is now " << mylist.front() << '\n';
}

void		back_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "BACK" << std::endl;
	std::list<int> mylist;

	mylist.push_back(10);

	while (mylist.back() != 0)
	{
		mylist.push_back ( mylist.back() -1 );
	}

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void		assign_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "ASSIGN" << std::endl;
	std::list<int> first;
	std::list<int> second;

	first.assign (7,100);                      // 7 ints with value 100

	second.assign (first.begin(),first.end()); // a copy of first

	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
}

void		push_front_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "PUSH_FRONT" << std::endl;
	std::list<int> mylist (2,100);         // two ints with a value of 100
	mylist.push_front (200);
	mylist.push_front (300);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void		pop_front_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "POP_FRONT" << std::endl;
	std::list<int> mylist;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	std::cout << "Popping out the elements in mylist:";
	while (!mylist.empty())
	{
		std::cout << ' ' << mylist.front();
		mylist.pop_front();
	}

	std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
}

void		push_back_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "PUSH_BACK" << std::endl;
	std::list<int> mylist;

	for (int i = 10; i < 50; i += 10)
		mylist.push_back (i);

	std::cout << "mylist stores " << mylist.size() << " numbers.\n";
}

void		pop_back_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "POP_BACK" << std::endl;
	std::list<int> mylist;
	int sum (0);
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	while (!mylist.empty())
	{
		sum+=mylist.back();
		mylist.pop_back();
	}

	std::cout << "The elements of mylist summed " << sum << '\n';
}

void		insert_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "INSERT" << std::endl;
	std::list<int> mylist;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^

	mylist.insert (it,10);                        // 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

	--it;       // it points now to the second 20            ^

	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
	// 1 10 20 30 30 20 2 3 4 5
	//               ^
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		erase_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "ERASE" << std::endl;
	std::list<int> mylist;
	std::list<int>::iterator it1,it2;

	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);

	// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); // ^^
	++it1;                      //    ^              ^

	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
	//    ^           ^

	it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
	//    ^           ^

	++it1;                      //       ^        ^
	--it2;                      //       ^     ^

	mylist.erase (it1,it2);     // 10 30 60 80 90
	//        ^

	std::cout << "mylist contains:";
	for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
}

void		swap_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "SWAP" << std::endl;
	std::list<int> first (3,100);   // three ints with a value of 100
	std::list<int> second (5,200);  // five ints with a value of 200

	first.swap(second);

	std::cout << "first contains:";
	for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		resize_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "RESIZE" << std::endl;
	std::list<int> mylist;

	// set some initial content:
	for (int i=1; i<10; ++i) mylist.push_back(i);

	mylist.resize(5);		// 1 2 3 4 5
	mylist.resize(8,100);// 1 2 3 4 5 100 100 100
	mylist.resize(12);		// 1 2 3 4 5 100 100 100 0 0 0 0

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void		clear_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "CLEAR" << std::endl;
	std::list<int> mylist;
	std::list<int>::iterator it;

	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.clear();
	mylist.push_back (1101);
	mylist.push_back (2202);

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		splice_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "SPLICE" << std::endl;
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2
	
	

	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
	show_list(mylist1);
	show_list(mylist2);
	// show_list(mylist1);
	// mylist2 (empty)
	// "it" still points to 2 (the 5th element)

	mylist2.splice (mylist2.begin(),mylist1, it);
	show_list(mylist1);
	show_list(mylist2);
	// mylist1: 1 10 20 30 3 4
	// mylist2: 2
	// "it" is now invalid.
	it = mylist1.begin();
	// std::cout << "check: " << it._element << '\n';
	// std::advance(it,3);           // "it" points now to 30
	++it;
	++it;
	++it;

	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
	show_list(mylist1);
	show_list(mylist2);
	// mylist1: 30 3 4 1 10 20

	std::cout << "mylist1 contains:";
	for (it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "mylist2 contains:";
	for (it=mylist2.begin(); it!=mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		remove_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "REMOVE" << std::endl;
	int myints[]= {17,89,7,14};
	std::list<int> mylist (myints,myints+4);

	mylist.remove(89);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		remove_if_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "REMOVE_IF" << std::endl;
	int myints[]= {15,36,7,17,20,39,4,1};
	std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

	mylist.remove_if (single_digit);           // 15 36 17 20 39

	mylist.remove_if (is_odd());               // 36 20

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		unique_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "UNIQUE" << std::endl;
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
							12.77, 73.35, 72.25, 15.3,  72.25 };
	std::list<double> mylist (mydoubles,mydoubles+10);
	show_list(mylist);

	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	// 15.3,  72.25, 72.25, 73.0,  73.35
	show_list(mylist);

	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
	// 15.3,  72.25, 73.0,  73.35
	show_list(mylist);

	mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
	// 15.3,  72.25, 73.0
	show_list(mylist);

	mylist.unique (is_near());           //  2.72, 12.15, 72.25
	show_list(mylist);

	std::cout << "mylist contains:";
	for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		merge_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "MERGE" << std::endl;
	std::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	first.merge(second);

	// (second is now empty)

	second.push_back (2.1);

	first.merge(second,mycomparison);

	std::cout << "first contains:";
	for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void		sort_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "SORT" << std::endl;
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");

	mylist.sort();

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.sort(compare_nocase);

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}



void		reverse_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "REVERSE" << std::endl;
	std::list<int> mylist;

	for (int i=1; i<10; ++i) mylist.push_back(i);

	mylist.reverse();

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void		relational_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "RELATIONAL" << std::endl;
	std::list<int> a;
	std::list<int> b;
	std::list<int> c;

	for (int i = 10; i < 40; ++i)
	{
		a.push_back(i); // 10 20 30
		b.push_back(i); // 10 20 30
		c.push_front(i);// 30 20 10
	}
	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";
}

void		non_mem_swap_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "NON_MEM_SWAP" << std::endl;
	std::list<int> foo (3,100);   // three ints with a value of 100
	std::list<int> bar (5,200);   // five ints with a value of 200

	std::swap(foo,bar);

	std::cout << "foo contains:";
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

int main(void)
{
	construct_test();
	copy_operator_test();
	begin_test();
	end_test();
	rbegin_test();

	rend_test();

	empyt_test();
	size_test();

	max_size_test();
	front_test();

	back_test();

	assign_test();
	push_front_test();

	pop_front_test();
	push_back_test();

	pop_back_test();

	insert_test();

	erase_test();
	swap_test();

	resize_test();

	clear_test();

	splice_test();

	remove_test();

	remove_if_test();

	unique_test();

	merge_test();

	sort_test();

	reverse_test();

	relational_test();

	non_mem_swap_test();

	return (0);
}