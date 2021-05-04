#ifndef LIST_HPP
# define LIST_HPP

/*
Member functions
(constructor)
Construct list (public member function )
(destructor)
List destructor (public member function )
operator=
Assign content (public member function )

Iterators:
begin
Return iterator to beginning (public member function )
end
Return iterator to end (public member function )
rbegin
Return reverse iterator to reverse beginning (public member function )
rend
Return reverse iterator to reverse end (public member function )
cbegin 
Return const_iterator to beginning (public member function )
cend 
Return const_iterator to end (public member function )
crbegin 
Return const_reverse_iterator to reverse beginning (public member function )
crend 
Return const_reverse_iterator to reverse end (public member function )

Capacity:
empty
Test whether container is empty (public member function )
size
Return size (public member function )
max_size
Return maximum size (public member function )

Element access:
front
Access first element (public member function )
back
Access last element (public member function )

Modifiers:
assign
Assign new content to container (public member function )
emplace_front 
Construct and insert element at beginning (public member function )
push_front
Insert element at beginning (public member function )
pop_front
Delete first element (public member function )
emplace_back 
Construct and insert element at the end (public member function )
push_back
Add element at the end (public member function )
pop_back
Delete last element (public member function )
emplace 
Construct and insert element (public member function )
insert
Insert elements (public member function )
erase
Erase elements (public member function )
swap
Swap content (public member function )
resize
Change size (public member function )
clear
Clear content (public member function )

Operations:
splice
Transfer elements from list to list (public member function )
remove
Remove elements with specific value (public member function )
remove_if
Remove elements fulfilling condition (public member function template )
unique
Remove duplicate values (public member function )
merge
Merge sorted lists (public member function )
sort
Sort elements in container (public member function )
reverse
Reverse the order of elements (public member function )

Observers:
get_allocator
Get allocator (public member function )

Non-member function overloads
relational operators (list)
Relational operators for list (function )
swap (list)
Exchanges the contents of two lists (function template )

*/

#include "Node.hpp"
#include "Iterator.hpp"
#include <memory> // allocator


namespace ft
{
	template < typename T, typename Alloc = std::allocator<T> >
	class List
	{
	public:
		typedef T										value_type;
		typedef Alloc									allocator_type;
		typedef allocator_type::reference				reference;
		typedef allocator_type::const_reference			const_reference;
		typedef allocator_type::pointer					pointer;
		typedef allocator_type::const_pointer			const_pointer;
		typedef bidirectional_iterator_tag	iterator;
		typedef bidirectional_iterator_tag	const_iterator;
		// typedef typename reverse_iterator<iterator>		reverse_iterator;
		// typedef typename reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;
	private:
		Node<value_type>	_begin;
		Node<value_type>	_end;
		size_type			_size;

	public:
	// Constuctor
		explicit List(const allocator_type& alloc = allocator_type()); // default

		List(const List &);
	// Destructor
		~List();
	// etc
		List	&operator=(const List &);
	};

	// 깊은 복사 필요
	template <typename T, typename Alloc>
	List<T, Alloc>::List(const List<T, Alloc> &copy) : _begin(copy._begin), _end(copy._end), _size(copy._size)
	{
	}

	// 노드 모두 제거
	template <typename T>
	List<T>::~List()
	{
		std::cout << "List destructor called." << std::endl; // test
	}

	
}

#endif