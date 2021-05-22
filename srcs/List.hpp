#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "ListIterator.hpp"
// # include "ReverseListIterator.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class List
	{
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ListIterator<T>							iterator;
		typedef const ListIterator<T>						const_iterator;
		// typedef ReverseListIterator<T>					reverse_iterator;
		// typedef const ReverseListIterator<T>				const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

	private:
		// allocator_type	_allocator;
		std::allocator<T>	_allocator; // 자동완성때문에 잠깐 바꿔놓음 위에꺼로 해야됨
		pointer				_begin;
		pointer				_last;
		pointer				_end;
		size_t				_size;

	public:
		explicit List(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0), _begin(0), _end(0), _last(0)
		{
			_end = _allocator.allocate(1);
			_allocator.construct(_end, Node<T>(0));
		}
		explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0), _begin(0), _end(0), _last(0)
		{
			for (size_type i = 0; i < n; ++i)
				push_back(val);
		}
		template <typename InputIterator>
		List(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0), _begin(0), _end(0), _last(0)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		List(const List &copy) : _allocator(copy._allocator), _size(copy._size), _begin(copy._begin), _end(copy._end), _last(copy._last)
		{
		}
		~List()
		{
			_allocator.destroy(_end);
			_allocator.deallocate(_end);
		}
		List				&operator=(const List &copy)
		{
			this->_allocator = copy._allocator;
		}
	
		/* Iterator */
		iterator			begin()
		{
			return (_begin);
		}

		iterator			end()
		{
			return (_end);
		}

		// reverse_iterator	rbegin()
		// {
		// 	return (_end);
		// }

		// reverse_iterator	rend();

		size_type			size() const
		{
			return (_size);
		}

		size_type			max_size() const
		{
			return (_allocator.max_size());
		}
		bool				empty() const
		{
			if (_size == 0)
				return (true);
			else
				return (false);
		}

		reference			front();
		const_reference		front() const;
		reference			back();
		const_reference		back() const;

		template <typename InputIterator>
		void				assign(InputIterator first, InputIterator last);
		void				assign(size_type n, const value_type &val);
		void				push_back(const value_type &value)
		{
			if (_last == 0)
			{
				_begin = _allocator.allocate(1);
				_allocator.construct(_begin, Node<T>(value));
				_last = _begin;
				_last->next = _end;
				_last->prev = _end;
				_end->_prev = _last;
				_end->_next = _begin;
			}
			else
			{
				_last->_next = _allocator.allocate(1);
				_allocator.construct(_last->_next, Node<T>(value));
				_last->_next->_prev = _last;
				_last = _last->_next;
				_last->_next = _end;
				_end->_prev = _last;
			}
			++_size;

		};
		void				pop_back()
		{
			if (_begin == 0)
				return ;
			else
			{
				pointer		temp;

				temp = _last;
				_last = _last->_prev;
				_last->_next = _end;
				_allocator.destroy(temp);
				_allocator.deallocate(temp);
				_end->_prev = _last;
				--_size;
			}
		}
		iterator			insert(iterator position, const value_type &val)
		{
			pointer		temp;

			temp = position->_prev;
			position->_prev = _allocator.allocate(1);
			_allocator.construct(position->_prev, Node<T>(val));
			temp->_next = position->_prev;
			position->_prev->_next = position->_element;
			position->_prev->_prev = temp;
			++_size;
		}
		void				insert(iterator position, size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; ++i)
				insert(position, val);
		}
		template <class InputIterator>
		void				insert(iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *first);
				++first;
				++position;
			}
		}
		iterator			erase(iterator position)
		{
			pointer		temp;

			temp = position->_next;
			if (position == begin())
			{
				_begin = position->_next;
				position->_prev->_next = position->_next;
				position->_next->_prev = position->_prev;
				_allocator.destroy(position->_element);
				_allocator.deallocate(position->_element);
			}
			else
			{
				position->_prev->_next = position->_next;
				position->_next->_prev = position->_prev;
				_allocator.destroy(position->_element);
				_allocator.deallocate(position->_element);
			}
			return (temp);
		}
		iterator			erase(iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first);
				++first;
			}
		}
		template <typename T>
		static void				swap(T &a, T &b)
		{
			T		temp;

			temp = a;
			a = b;
			b = temp;
		}
		void				swap(List& x)
		{
			swap(this->_allocator, x._allocator);
			swap(this->_begin, x._begin);
			swap(this->_end, x._end);
			swap(this->_last, x._last);
			swap(this->_size, x._size);
		}
		void				clear()
		{
			pointer		temp;

			while (_begin)
			{
				temp = _begin->_next;
				_allocator.destroy(_begin);
				_allocator.deallocate(_begin);
				_begin = temp;
			}
		};
	};
}

#endif