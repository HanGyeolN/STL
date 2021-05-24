#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "Vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Queue
	{
	public:
		typedef	T			value_type;
		typedef Container	contianer_type;
		typedef size_t		size_type;

	public:
		explicit		queue(const container_type& ctnr = container_type()) 
		{
			_container = ctnr;
		}

		bool			empty() const
		{
			return (_container.empty());
		}

		size_type		size() const
		{
			return (_container.size());
		}

		value_type&		front()
		{
			return (_container.front());
		}

		const value_type&	front() const
		{
			return (_container.front());
		}

		value_type&		back()
		{
			return (_container.back());
		}

		const value_type&	back() const
		{
			return (_container.back());
		}

		void push (const value_type& val)
		{
			_container.push_back(val);
		}

		void			pop()
		{
			_container.pop_back();
		}

		template <class T, class Container>
		bool operator== (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{
			return (lhs == rhs);
		}

		template <class T, class Container>
		bool operator!= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{
			return (lhs != rhs);
		}

		template <class T, class Container>
		bool operator<  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{
			return (lhs < rhs);
		}

		template <class T, class Container>
		bool operator<= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{
			return (lhs <= rhs);
		}

		template <class T, class Container>
		bool operator>  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{
			return (lhs > rhs);
		}

		template <class T, class Container>
		bool operator>= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs)
		{
			return (lhs >= rhs);
		}

	private:
		container_type		_container;
	};
}

#endif