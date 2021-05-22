#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "ListIterator.hpp"
# include "ReverseListIterator.hpp"

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
		typedef ReverseListIterator<T>					reverse_iterator;
		typedef const ReverseListIterator<T>				const_reverse_iterator;
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
	
		// Return iterator to beginning
		// Returns an iterator pointing to the first element in the list container.

		// Notice that, unlike member list::front, which returns a reference to the first element, this function returns a bidirectional iterator pointing to it.

		// If the container is empty, the returned iterator value shall not be dereferenced.

		// Parameters
		// none

		// Return Value
		// An iterator to the beginning of the sequence container.

		// If the list object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.

		// Member types iterator and const_iterator are bidirectional iterator types (pointing to an element and to a const element, respectively).
		iterator			begin()
		{
			return (_begin);
		}

		const_iterator		begin() const
		{
			return (_begin);
		}

		// Return iterator to end
		// Returns an iterator referring to the past-the-end element in the list container.

		// The past-the-end element is the theoretical element that would follow the last element in the list container. It does not point to any element, and thus shall not be dereferenced.

		// Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with list::begin to specify a range including all the elements in the container.

		// If the container is empty, this function returns the same as list::begin.

		// Parameters
		// none

		// Return Value
		// An iterator to the element past the end of the sequence.

		// If the list object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.

		// Member types iterator and const_iterator are bidirectional iterator types (pointing to an element and to a const element, respectively).
		iterator			end()
		{
			return (_end);
		}

		const_iterator		end() const
		{
			return (_end);
		}

		// Return reverse iterator to reverse beginning
		// Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).

		// Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container.

		// rbegin points to the element right before the one that would be pointed to by member end.

		// Notice that unlike member list::back, which returns a reference to this same element, this function returns a reverse bidirectional iterator.

		// Parameters
		// none

		// Return Value
		// A reverse iterator to the reverse beginning of the sequence container.

		// If the list object is const-qualified, the function returns a const_reverse_iterator. Otherwise, it returns a reverse_iterator.

		// Member types reverse_iterator and const_reverse_iterator are reverse bidirectional iterator types (pointing to an element and to a const element, respectively). See list member types.
		reverse_iterator rbegin()
		{
			return (_end->_prev);
		}

		const_reverse_iterator rbegin() const
		{
			return (_end->_prev);
		}


		// Return reverse iterator to reverse end
		// Returns a reverse iterator pointing to the theoretical element preceding the first element in the list container (which is considered its reverse end).

		// The range between list::rbegin and list::rend contains all the elements of the container (in reverse order).

		// Parameters
		// none

		// Return Value
		// A reverse iterator to the reverse end of the sequence container.

		// If the list object is const-qualified, the function returns a const_reverse_iterator. Otherwise, it returns a reverse_iterator.

		// Member types reverse_iterator and const_reverse_iterator are reverse bidirectional iterator types (pointing to an element and to a const element, respectively). See list member types.

		reverse_iterator rend()
		{
			return (_end);
		}
		const_reverse_iterator rend() const
		{
			return (_end);
		}


		// Return size
		// Returns the number of elements in the list container.

		// Parameters
		// none

		// Return Value
		// The number of elements in the container.

		// Member type size_type is an unsigned integral type.

		size_type			size() const
		{
			return (_size);
		}

		// Return maximum size
		// Returns the maximum number of elements that the list container can hold.

		// This is the maximum potential size the container can reach due to known system or library implementation limitations, but the container is by no means guaranteed to be able to reach that size: it can still fail to allocate storage at any point before that size is reached.

		// Parameters
		// none

		// Return Value
		// The maximum number of elements the object can hold as content.

		// Member type size_type is an unsigned integral type.

		size_type			max_size() const
		{
			return (_allocator.max_size());
		}

		// Test whether container is empty
		// Returns whether the list container is empty (i.e. whether its size is 0).
		// This function does not modify the container in any way. To clear the content of a list container, see list::clear.
		// Parameters
		// none
		// Return Value
		// true if the container size is 0, false otherwise.
		bool				empty() const
		{
			if (_size == 0)
				return (true);
			else
				return (false);
		}

		// Access first element
		// Returns a reference to the first element in the list container.

		// Unlike member list::begin, which returns an iterator to this same element, this function returns a direct reference.

		// Calling this function on an empty container causes undefined behavior.

		// Parameters
		// none

		// Return value
		// A reference to the first element in the list container.

		// If the list object is const-qualified, the function returns a const_reference. Otherwise, it returns a reference.

		// Member types reference and const_reference are the reference types to the elements of the container (see list member types).
		reference			front()
		{
			return (*_begin);
		}
		const_reference		front() const
		{
			return (*_begin);
		}


		reference			back()
		{
			return (*_last);
		}
		const_reference		back() const
		{
			return (*_last);
		}


// Assign new content to container
// Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly.

// In the range version (1), the new contents are elements constructed from each of the elements in the range between first and last, in the same order.

// In the fill version (2), the new contents are n elements, each initialized to a copy of val.

// Any storage needed for the assigned elements is allocated using the internal allocator.

// Any elements held in the container before the call are destroyed and replaced by newly constructed elements (no assignments of elements take place).

// Parameters
// first, last
// Input iterators to the initial and final positions in a sequence. The range used is [first,last), which includes all the elements between first and last, including the element pointed by first but not the element pointed by last.
// The function template argument InputIterator shall be an input iterator type that points to elements of a type from which value_type objects can be constructed.
// n
// New size for the container.
// Member type size_type is an unsigned integral type.
// val
// Value to fill the container with. Each of the n elements in the container will be initialized to a copy of this value.
// Member type value_type is the type of the elements in the container, defined in list as an alias of its first template parameter (T).
// il
// An initializer_list object. The compiler will automatically construct such objects from initializer list declarators.
// Member type value_type is the type of the elements in the container, defined in list as an alias of its first template parameter (T).

// Return value
// none
		template <typename InputIterator>
		void				assign(InputIterator first, InputIterator last)
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		void				assign(size_type n, const value_type &val)
		{
			clear();
			for (size_type i = 0; i < n; ++i)
				push_back(val);
		}
	
// Insert element at beginning
// Inserts a new element at the beginning of the list, right before its current first element. The content of val is copied (or moved) to the inserted element.

// This effectively increases the container size by one.

// Parameters
// val
// Value to be copied (or moved) to the inserted element.
// Member type value_type is the type of the elements in the container, defined in list as an alias of its first template parameter (T).

// Return value
// none

// The storage for the new elements is allocated using the container's allocator, which may throw exceptions on failure (for the default allocator, bad_alloc is thrown if the allocation request does not succeed).
		void	push_front(const value_type &val)
		{
			pointer		temp;

			if (_size == 0)
			{
				_begin = _allocator.allocate(1);
				_allocator.construct(_begin, val);
				_last = _begin;
				_last->_next = _end;
				_last->_prev = _end;
				_end->_next = _last;
				_end->_prev = _last;
			}
			else
			{
				temp = _begin;
				_begin = _allocator.allocate(1);
				_allocator.construct(_begin, val);
				_begin->_next = temp;
				_begin->_prev = _end;
				_end->_next = _begin;
				temp->_prev = _begin;
			}
			++_size;
		}

// Delete last element
// Removes the last element in the list container, effectively reducing the container size by one.

// This destroys the removed element.
		void	pop_front()
		{
			pointer		temp;
			if (_size == 0)
				return ;
			

			temp = _begin;
			_begin = _begin->_next;
			_begin->_prev = _end;
			_end->_next = _begin;
			_allocator.destroy(temp);
			_allocator.deallocate(temp);
			--_size;
		}

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
			position->_prev->_next = position._element;
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
				_allocator.destroy(position._element);
				_allocator.deallocate(position._element);
			}
			else
			{
				position->_prev->_next = position->_next;
				position->_next->_prev = position->_prev;
				_allocator.destroy(position->_element);
				_allocator.deallocate(position->_element);
			}
			--_size;
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

// Clear content
// Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.

		void				clear()
		{
			while (_size)
			{
				pop_back();
			}
		};

// Change size
// Resizes the container so that it contains n elements.

// If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).

// If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

// Notice that this function changes the actual content of the container by inserting or erasing elements from it.

// Parameters

// n
//     New container size, expressed in number of elements.
//     Member type size_type is an unsigned integral type.
// val
//     Object whose content is copied to the added elements in case that n is greater than the current container size.
//     If not specified, the default constructor is used instead.
//     Member type value_type is the type of the elements in the container, defined in list as an alias of the first template parameter (T).


// Return Value
// none

// In case of growth, the storage for the new elements is allocated using the container's allocator, which may throw exceptions on failure (for the default allocator, bad_alloc is thrown if the allocation request does not succeed).
		void resize (size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				while (n < _size)
				{
					pop_back();
				}
			}
			else
			{
				while (n > _size)
				{
					push_back(val);
				}
			}
		}

// Transfer elements from list to list
// Transfers elements from x into the container, inserting them at position.

// This effectively inserts those elements into the container and removes them from x, altering the sizes of both containers. 
// The operation does not involve the construction or destruction of any element. 
// They are transferred, no matter whether x is an lvalue or an rvalue, or whether the value_type supports move-construction or not.

// The first version (1) transfers all the elements of x into the container.
// The second version (2) transfers only the element pointed by i from x into the container.
// The third version (3) transfers the range [first,last) from x into the container.

// Parameters

// position
//     Position within the container where the elements of x are inserted.
//     Member types iterator and const_iterator are bidirectional iterator types that point to elements.
// x
//     A list object of the same type (i.e., with the same template parameters, T and Alloc).
//     This parameter may be *this if position points to an element not actually being spliced (for the first version, this is never the case, but for the other versions this is possible).
// i
//     Iterator to an element in x. Only this single element is transferred.
//     iterator is a member type, defined as a bidirectional iterator type.
//     Member types iterator and const_iterator are bidirectional iterator types that point to elements.
// first,last
//     Iterators specifying a range of elements in x. Transfers the elements in the range [first,last) to position.
//     Notice that the range includes all the elements between first and last, including the element pointed by first but not the one pointed by last.
//     Member types iterator and const_iterator are bidirectional iterator types that point to elements.

		void splice (iterator position, list& x) // entire list (1)
		{
			position->_prev->_next = x._begin;
			(x._begin)->_prev = position->_prev;
			position->_prev = x._last;
			x._last->_next = position._element;
			_size += x.size();
			
			x.clear();
		}

		void splice (iterator position, list& x, iterator i); // single element (2)
		{
			i->_prev->_next = i->_next;
			i->_next->_prev = i->_prev;
			--(x._size);

			position->_prev->_next = i._element;
			i->_prev = position->_prev;
			i->_next = position._element;
			position->_prev = i._element;
			++_size;
		}

		void splice (iterator position, list& x, iterator first, iterator last); // element range (3)
		{
			size_type		size;

			size = 0;
			first->_prev->_next = last._element;
			last->_prev = first->_prev;

			position->_prev->_next = first._element;
			first->_prev = position->_prev;
			last->_prev->_next = position._element;
			position->_prev = last._prev;

			while (first != last)
			{
				++first;
				++size;
			}
			x._size -= size;
			_size += size;
		}

// Remove elements with specific value
// Removes from the container all the elements that compare equal to val. This calls the destructor of these objects and reduces the container size by the number of elements removed.

// Unlike member function list::erase, which erases elements by their position (using an iterator), this function (list::remove) removes elements by their value.

// A similar function, list::remove_if, exists, which allows for a condition other than an equality comparison to determine whether an element is removed.

// Parameters

// val
//     Value of the elements to be removed.
//     Member type value_type is the type of the elements in the container, defined in list as an alias of its first template parameter (T).
		void remove (const value_type& val)
		{
			iterator	iter;

			if (_size == 0)
				return ;
			iter = begin();
			while (iter != end())
			{
				if (*iter == val)
				{
					erase(iter);
				}
				++iter;
			}
		}


// Remove elements fulfilling condition
// Removes from the container all the elements for which Predicate pred returns true. 
// This calls the destructor of these objects and reduces the container size by the number of elements removed.

// The function calls pred(*i) for each element (where i is an iterator to that element). 
// Any of the elements in the list for which this returns true, are removed from the container.

// Parameters

// pred
//     Unary predicate that, taking a value of the same type as those contained in the forward_list object, returns true for those values to be removed from the container, and false for those remaining.
//     This can either be a function pointer or a function object.
		template <class Predicate>
		void remove_if (Predicate pred)
		{
			iterator	iter;

			if (_size == 0)
				return ;
			iter = begin();
			while (iter != end())
			{
				if (pred(*iter))
				{
					erase(iter);
				}
				++iter;
			}
		}

// Remove duplicate values
// The version with no parameters (1), removes all but the first element from every consecutive group of equal elements in the container.

// Notice that an element is only removed from the list container if it compares equal to the element immediately preceding it. Thus, this function is especially useful for sorted lists.

// The second version (2), takes as argument a specific comparison function that determine the "uniqueness" of an element. In fact, 
// any behavior can be implemented (and not only an equality comparison), but notice that the function will call binary_pred(*i,*(i-1)) 
// for all pairs of elements (where i is an iterator to an element, starting from the second) and remove i from the list if the predicate returns true.

// The elements removed are destroyed.

// Paramaters

// binary_pred
//     Binary predicate that, taking two values of the same type than those contained in the list, returns true to remove the element passed as first argument 
// from the container, and false otherwise.
//     This shall be a function pointer or a function object.

		void unique()
		{
			iterator	iter;

			if (_size == 0)
				return ;
			iter = begin() + 1;
			while (iter != end())
			{
				if (*iter == *(iter - 1))
					erase(iter);
				++iter;
			}
		}

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			iterator	iter;

			if (_size == 0)
				return ;
			iter = begin() + 1;
			while (iter != end())
			{
				if (binary_pred(*iter, *(iter - 1)))
					erase(iter);
				++iter;
			}
		}


// Merge sorted lists
// Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered).

// This effectively removes all the elements in x (which becomes empty), and inserts them into their ordered position within container (which expands in size by the number of elements transferred). The operation is performed without constructing nor destroying any element: they are transferred, no matter whether x is an lvalue or an rvalue, or whether the value_type supports move-construction or not.

// The template versions with two parameters (2), have the same behavior, but take a specific predicate (comp) to perform the comparison operation between elements. This comparison shall produce a strict weak ordering of the elements (i.e., a consistent transitive comparison, without considering its reflexiveness).

// This function requires that the list containers have their elements already ordered by value (or by comp) before the call. For an alternative on unordered lists, see list::splice.

// Assuming such ordering, each element of x is inserted at the position that corresponds to its value according to the strict weak ordering defined by operator< or comp. The resulting order of equivalent elements is stable (i.e., equivalent elements preserve the relative order they had before the call, and existing elements precede those equivalent inserted from x).

// The function does nothing if (&x == this).

// Parameters

// x
//     A list object of the same type (i.e., with the same template parameters, T and Alloc).
//     Note that this function modifies x no matter whether an lvalue or rvalue reference is passed.
// comp
//     Binary predicate that, taking two values of the same type than those contained in the list, returns true if the first argument is considered to go before the second in the strict weak ordering it defines, and false otherwise.
//     This shall be a function pointer or a function object.
		void merge (list& x)
		{

		}

		template <class Compare>
		void merge (list& x, Compare comp);

// Sort elements in container
// Sorts the elements in the list, altering their position within the container.

// The sorting is performed by applying an algorithm that uses either operator< (in version (1)) or comp (in version (2)) to compare elements. This comparison shall produce a strict weak ordering of the elements (i.e., a consistent transitive comparison, without considering its reflexiveness).

// The resulting order of equivalent elements is stable: i.e., equivalent elements preserve the relative order they had before the call.

// The entire operation does not involve the construction, destruction or copy of any element object. Elements are moved within the container.

// Parameters

// comp
//     Binary predicate that, taking two values of the same type of those contained in the list, returns true if the first argument goes before the second argument in the strict weak ordering it defines, and false otherwise.
//     This shall be a function pointer or a function object.
		void sort()
		{
			iterator		iter;
			iterator		iter2;

			iter = begin();
			while (iter != end())
			{
				iter2 = iter + 1;
				while (iter2 != end())
				{
					if (iter < iter - 1)
						swap(*iter, *(iter - 1));
					++iter;
				}
			}
		}

		template <class Compare>
		void sort (Compare comp);


// Reverse the order of elements
// Reverses the order of the elements in the list container.
		void reverse();

// Get allocator
// Returns a copy of the allocator object associated with the list container.

// Parameters
// none

// Return Value
// The allocator.

// Member type allocator_type is the type of the allocator used by the container, defined in list as an alias of its second template parameter (Alloc).
		allocator_type get_allocator() const;


		template <class T, class Alloc>
		bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
		{
			if (lhs.size() == rhs.size())
				return (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
			else
				return (false);
		}

		template <class T, class Alloc>
		bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

		template <class T, class Alloc>
		bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
		{
			return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class T, class Alloc>
		bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
		{
			return (!(rhs < lhs));
		}

		template <class T, class Alloc>
		bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}

		template <class T, class Alloc>
		bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}
	};
}

#endif