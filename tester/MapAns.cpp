#include <map>
#include <iostream>
#include <iomanip>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

// template <typename T1, typename T2>
// void		show_map(const std::map<T1, T2> &map)
// {
// 	typename std::map<T1,T2>::iterator	iter;

// 	iter = map.begin();
// 	while (iter != map.end())
// 	{
// 		std::cout << "key: " << (*iter).first << ", val: " << (*iter).second << '\n';
// 		// std::cout << "parent: " << iter._element->_parent << '\n';
// 		// std::cout << "left: " << iter._element->_left << "right: " << iter._element->_right << '\n';
// 		++iter;
// 	}
// }

void		construct_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "CONSTRUCT" << std::endl;
	std::map<char,int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::map<char,int> second (first.begin(),first.end());

	std::map<char,int> third (second);

	//std::map<char,int,classcomp> fourth;                 // class as Compare

	//bool(*fn_pt)(char,char) = fncomp;
	//std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
}

void		copy_operator_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "OPERATOR=" << std::endl;
	std::map<char,int> first;
	std::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=std::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}

void		begin_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "BEGIN, END" << std::endl;
	std::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void		rbegin_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "RBEGIN, REND" << std::endl;
	std::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

void		empty_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "EMPTY" << std::endl;
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
}

void		size_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "SIZE" << std::endl;
	std::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
}

void		max_size_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "MAX_SIZE" << std::endl;
	int i;
	std::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";
}

void		operator_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "OPERATOR[]" << std::endl;
	std::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

void		insert_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "INSERT" << std::endl;
	std::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void		erase_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "ERASE" << std::endl;
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void		swap_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "SWAP" << std::endl;
	std::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void		clear_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "CLEAR" << std::endl;
	std::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void		key_compare_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "KEY_COMP" << std::endl;
	std::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
}

void		value_compare_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "VALUE_COMP" << std::endl;
	std::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();          // last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}

void		find_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "FIND" << std::endl;
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void		count_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "COUNT" << std::endl;
	std::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}
}

void		bound_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "LOWER_BOUND, UPPER_BOUND" << std::endl;
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void		range_test()
{
	std::cout << std::setfill('-') << std::setw(20) << "EQUAL_RANGE" << std::endl;
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

int main(void)
{
	construct_test();
	copy_operator_test();
	begin_test();
	rbegin_test();
	empty_test();
	size_test();
	max_size_test();
	operator_test();
	insert_test();
	erase_test();
	swap_test();
	clear_test();
	key_compare_test();
	value_compare_test();
	find_test();
	count_test();
	bound_test();
	range_test();

	return (0);
}
