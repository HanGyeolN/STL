#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Stack
	{
	private:
		Container				_container;

	public:
		typedef T								value_type;
		typedef Container						container_type;
		typedef size_t							size_type;

	public:

		explicit Stack (const container_type& ctnr = container_type())
		{
			_container = ctnr;
		}

		bool				empty() const
		{
			return (_container.empty());
		}

		size_type			size() const
		{
			return (_container.size());
		}

		value_type			&top()
		{
			return (_container.back());
		}
		const value_type	&top() const
		{
			return (_container.back());
		}

		void push (const value_type& val)
		{
			_container.push_back(val);
		}

		void pop()
		{
			_container.pop_back();
		}

// Relational operators for stack
// Performs the appropriate comparison operation between lhs and rhs.

// Each of these operator overloads calls the same operator on the underlying container objects.

// Parameters

// lhs, rhs
//     stack objects (to the left- and right-hand side of the operator, respectively).


// Return Value
// true if the condition holds, and false otherwise.

		friend bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{
			return (lhs._container == rhs._container);
		}

		friend bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{
			return (lhs._container != rhs._container);
		}

		friend bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{
			return (lhs._container < rhs._container);
		}

		friend bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{
			return (lhs._container <= rhs._container);
		}

		friend bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{
			return (lhs._container > rhs._container);
		}

		friend bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
		{
			return (lhs._container >= rhs._container);
		}
	};
}

#endif
