#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"

// LIFO stack
// Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.

// stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.

// The underlying container may be any of the standard container class templates or some other specifically designed container class. The container shall support the following operations:

//     empty
//     size
//     back
//     push_back
//     pop_back


// The standard container classes vector, deque and list fulfill these requirements. By default, if no container class is specified for a particular stack class instantiation, the standard container deque is used.
namespace ft
{
// T
//     Type of the elements.
//     Aliased as member type stack::value_type.
// Container
//     Type of the internal underlying container object where the elements are stored.
//     Its value_type shall be T.
//     Aliased as member type stack::container_type. 
	template <class T, class Container = ft::Vector<T> >
	class Stack
	{
	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t			size_type;

	public:
// Construct stack
// Constructs a stack container adaptor object.

// A container adaptor keeps internally a container object as data. This container object is a copy of the ctnr argument passed to the constructor, if any, otherwise it is an empty container.

// Parameters

// ctnr
//     Container object.
//     container_type is the type of the underlying container type (defined as an alias of the second class template parameter, Container; see member types).
// alloc
//     Allocator object.
//     Alloc shall be a type for which uses_allocator::value is true (for other types, the constructor does not even participate in overload resolution).
// x
//     A stack of the same type (i.e., with the same template arguments, T and Container).
		explicit stack (const container_type& ctnr = container_type());


//Test whether container is empty
// Returns whether the stack is empty: i.e. whether its size is zero.

// This member function effectively calls member empty of the underlying container object.
		bool				empty() const;
		size_type			size() const;

// Access next element
// Returns a reference to the top element in the stack.

// Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.

// This member function effectively calls member back of the underlying container object.

// Parameters
// none

// Return value
// A reference to the top element in the stack.
		value_type			&top();
		const value_type	&top() const;

// Insert element
// Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.

// This member function effectively calls the member function push_back of the underlying container object.

// Parameters

// val
//     Value to which the inserted element is initialized.
//     Member type value_type is the type of the elements in the container (defined as an alias of the first class template parameter, T).


// Return value
// none
		void push (const value_type& val);

// Remove top element
// Removes the element on top of the stack, effectively reducing its size by one.

// The element removed is the latest element inserted into the stack, whose value can be retrieved by calling member stack::top.

// This calls the removed element's destructor.

// This member function effectively calls the member function pop_back of the underlying container object.

// Parameters
// none

// Return value
// none

		void pop();

// Relational operators for stack
// Performs the appropriate comparison operation between lhs and rhs.

// Each of these operator overloads calls the same operator on the underlying container objects.

// Parameters

// lhs, rhs
//     stack objects (to the left- and right-hand side of the operator, respectively).


// Return Value
// true if the condition holds, and false otherwise.

		template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);


		template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);


		template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		~Stack();
	};
}

Stack::Stack(/* args */)
{
}

Stack::~Stack()
{
}


#endif
