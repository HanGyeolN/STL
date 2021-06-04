#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "MapNode.hpp"
# include "MapIterator.hpp"
# include "ReverseMapIterator.hpp"
# include "utils.hpp"

namespace ft
{

	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::Pair<Key, T> > >
	class Map
	{

	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef	ft::Pair<key_type, mapped_type>		value_type;
		typedef Compare										key_compare;

		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
			friend class Map<key_type, mapped_type, key_compare, Alloc>;
			
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			
			public:

				bool operator() (const value_type& x, const value_type& y) const
				{ return (comp(x.first, y.first)); }
		};

		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef MapIterator<value_type>						iterator;
		typedef const MapIterator<value_type>				const_iterator;
		typedef ReverseMapIterator<value_type>				reverse_iterator;
		typedef const ReverseMapIterator<value_type>		const_reverse_iterator;
		typedef	ptrdiff_t									difference_type;
		typedef size_t										size_type;

	private:
		typedef typename allocator_type::template
				rebind< MapNode<value_type> >::other		node_allocator;
		typedef typename node_allocator::pointer			node_pointer;

		allocator_type			_allocator;
		node_allocator			_node_allocator;
		key_compare				_key_comp;
		MapNode<value_type>*	_root;

	public:

// Construct map
// Constructs a map container object, initializing its contents depending on the constructor version used:

// (1) empty container constructor (default constructor)
//     Constructs an empty container, with no elements.
// (2) range constructor
//     Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range.
// (3) copy constructor
//     Constructs a container with a copy of each of the elements in x.


// The container keeps an internal copy of alloc and comp, which are used to allocate storage and to sort the elements throughout its lifetime.
// The copy constructor (3) creates a container that keeps and uses copies of x's allocator and comparison object.

// The storage for the elements is allocated using this internal allocator.

// The elements are sorted according to the comparison object. If more than one element with equivalent keys is passed to the constructor, only the first one is preserved.

// Parameters

// comp
//     Binary predicate that, taking two element keys as argument, returns true if the first argument goes before the second argument in the strict weak ordering it defines, and false otherwise.
//     This shall be a function pointer or a function object.
//     Member type key_compare is the internal comparison object type used by the container, defined in map as an alias of its third template parameter (Compare).
//     If key_compare uses the default less (which has no state), this parameter is not relevant.
// alloc
//     Allocator object.
//     The container keeps and uses an internal copy of this allocator.
//     Member type allocator_type is the internal allocator type used by the container, defined in map as an alias of its fourth template parameter (Alloc).
//     If allocator_type is an instantiation of the default allocator (which has no state), this parameter is not relevant.
// first, last
//     Input iterators to the initial and final positions in a range. The range used is [first,last), which includes all the elements between first and last, including the element pointed by first but not the element pointed by last.
//     The function template argument InputIterator shall be an input iterator type that points to elements of a type from which value_type objects can be constructed (in map, value_type is an alias of pair<const key_type, mapped_type>)
// x
//     Another map object of the same type (with the same class template arguments Key, T, Compare and Alloc), whose contents are either copied or acquired.
// il
//     An initializer_list object.
//     These objects are automatically constructed from initializer list declarators.
//     Member type value_type is the type of the elements in the container, defined in map as an alias of pair<const key_type, mapped_type> (see map types).

		explicit Map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()) 
			: _allocator(alloc), _key_comp(comp), _root(0)
		{
			
		}

		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _allocator(alloc), _key_comp(comp), _root(0)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		Map (const Map& copy) : _allocator(copy._allocator), _key_comp(copy._key_comp), _root(0)
		{
			this->insert(copy.begin(), copy.end());
		}

		~Map()
		{
			clear();
		}


		Map& operator=(const Map& x)
		{
			if (_root != 0)
				this->clear();
			this->insert(x.begin(), x.end());
			return (*this);
		}

		iterator begin()
		{
			iterator			begin(_root);

			if (_root == 0)
				return (0);
			while (begin._element->_left)
			{
				begin._element = begin._element->_left;
			}
			return (begin);
		}

		const_iterator begin() const
		{
			node_pointer		begin;

			if (_root == 0)
				return (0);
			begin = _root;
			while (begin->_left)
			{
				begin = begin->_left;
			}
			return (begin);
		}

		iterator end()
		{
			return (0);
		}

		const_iterator end() const
		{
			return (0);
		}

		reverse_iterator rbegin()
		{
			node_pointer		end;

			if (_root == 0)
				return (0);
			end = _root;
			while (end->_right)
			{
				end = end->_right;
			}
			return (end);
		}

		const_reverse_iterator rbegin() const
		{
			node_pointer		end;

			if (_root == 0)
				return (0);
			end = _root;
			while (end->_right)
			{
				end = end->_right;
			}
			return (end);
		}

		reverse_iterator rend()
		{
			return (0);
		}

		const_reverse_iterator rend() const
		{
			return (0);
		}

		bool		empty() const
		{
			if (size() == 0)
				return (true);
			else
				return (false);
		}

		size_type	size() const
		{
			iterator		iter;
			size_type		i;

			if (_root == 0)
				return (0);
			i = 0;
			iter = begin();
			while (iter != end())
			{
				++iter;
				++i;
			}
			return (i);
		}

		size_type	max_size() const
		{
			return (_node_allocator.max_size());
		}

// Access element
// If k matches the key of an element in the container, the function returns a reference to its mapped value.

// If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value. Notice that this always increases the container size by one, even if no mapped value is assigned to the element (the element is constructed using its default constructor).

// A similar member function, map::at, has the same behavior when an element with the key exists, but throws an exception when it does not.

// A call to this function is equivalent to:
// (*((this->insert(make_pair(k,mapped_type()))).first)).second

// Parameters

// k
//     Key value of the element whose mapped value is accessed.
//     Member type key_type is the type of the keys for the elements stored in the container, defined in map as an alias of its first template parameter (Key).
//     If an rvalue (second version), the key is moved instead of copied when a new element is inserted.


// Return value
// A reference to the mapped value of the element with a key value equivalent to k.

// Member type mapped_type is the type of the mapped values in the container, 
// defined in map as an alias of its second template parameter (T).

		mapped_type&	operator[](const key_type& k)
		{
			iterator	target;

			if (_root)
			{
				target = find(k);
				if (target._element)
					return (target->second);
				else
					return ((insert(value_type(k, mapped_type())).first)->second);
			}
			else
				return ((insert(value_type(k, mapped_type())).first)->second);
		}

// Insert elements
// Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.

// Because element keys in a map are unique, the insertion operation checks whether each inserted element has a key equivalent to the one of an element already in the container,
//  and if so, the element is not inserted, returning an iterator to this existing element (if the function returns a value).

// For a similar container allowing for duplicate elements, see multimap.

// An alternative way to insert elements in a map is by using member function map::operator[].

// Internally, map containers keep all their elements sorted by their key following the criterion specified by its comparison object. 
// The elements are always inserted in its respective position following this ordering.

// The parameters determine how many elements are inserted and to which values they are initialized:

// Parameters

// val
//     Value to be copied to (or moved as) the inserted element.
//     Member type value_type is the type of the elements in the container, defined in map as pair<const key_type,mapped_type> (see map member types).

//         C++98
//         C++14

//     The template parameter P shall be a type convertible to value_type.
//     If P is instantiated as a reference type, the argument is copied.
// position
//     Hint for the position where the element can be inserted.

//         C++98
//         C++11

//     The function optimizes its insertion time if position points to the element that will precede the inserted element.
//     Notice that this is just a hint and does not force the new element to be inserted at that position within the map container 
// 	   (the elements in a map always follow a specific order depending on their key).
//     Member types iterator and const_iterator are defined in map as bidirectional iterator types that point to elements.
// first, last
//     Iterators specifying a range of elements. Copies of the elements in the range [first,last) are inserted in the container.
//     Notice that the range includes all the elements between first and last, including the element pointed by first but not the one pointed by last.
//     The function template argument InputIterator shall be an input iterator type that points to elements of a type from which value_type objects can be constructed.
// il
//     An initializer_list object. Copies of these elements are inserted.
//     These objects are automatically constructed from initializer list declarators.
//     Member type value_type is the type of the elements contained in the container, defined in map as pair<const key_type,mapped_type> (see map member types).


// Return value
// The single element versions (1) return a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map. 
// The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.

// The versions with a hint (2) return an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map.

// Member type iterator is a bidirectional iterator type that points to elements.
// pair is a class template declared in <utility> (see pair).


		ft::Pair<iterator, bool>	insert(const value_type& val)
		{
			if (_root == 0)
			{
				_root = _node_allocator.allocate(1);
				_node_allocator.construct(_root, MapNode<value_type>(val));
				return (ft::Pair<iterator, bool>(_root, true));
			}
			else
			{
				return (insert_value(_root, val));
			}
		}

		iterator insert(iterator position, const value_type &val)
		{
			return (insert_value(position._element, val).first);
		}

		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}


// Erase elements
// Removes from the map container either a single element or a range of elements ([first,last)).

// This effectively reduces the container size by the number of elements removed, which are destroyed.

// Parameters

// position
//     Iterator pointing to a single element to be removed from the map.
//     This shall point to a valid and dereferenceable element.
//     Member types iterator and const_iterator are bidirectional iterator types that point to elements.
// k
//     Key of the element to be removed from the map.
//     Member type key_type is the type of the elements in the container, defined in map as an alias of its first template parameter (Key).
// first, last
//     Iterators specifying a range within the map container to be removed: [first,last). i.e., the range includes all the elements between first and last,
//	   including the element pointed by first but not the one pointed by last.
//     Member types iterator and const_iterator are bidirectional iterator types that point to elements.


// Return value
// For the key-based version (2), the function returns the number of elements erased.

// Member type size_type is an unsigned integral type.

		void		erase(iterator position)
		{
			if (position._element->_left && position._element->_right) // 자식 노드가 두개 있는 경우
			{
				iterator		successor(position._element->_right);

				while (successor._element->_left)
				{
					successor = successor._element->_left;
				}
				position._element->_data = successor._element->_data;
				erase(successor);
			}
			else if (position._element->_left || position._element->_right) // 자식 노드가 하나 있는 경우
			{
				if (position._element->_left)
				{
					if (position._element->_parent)
					{
						if (position._element->_parent->_left == position._element)
							position._element->_parent->_left = position._element->_left;
						else
							position._element->_parent->_right = position._element->_left;
						position._element->_left->_parent = position._element->_parent;
					}
					else
					{
						_root = position._element->_left;
						position._element->_left->_parent = position._element->_parent;
					}
				}
				else
				{
					if (position._element->_parent)
					{
						if (position._element->_parent->_left == position._element)
							position._element->_parent->_left = position._element->_right;
						else
							position._element->_parent->_right = position._element->_right;
						position._element->_right->_parent = position._element->_parent;
					}
					else
					{
						_root = position._element->_right;
						position._element->_right->_parent = position._element->_parent;
					}
				}
				_node_allocator.destroy(position._element);
				_node_allocator.deallocate(position._element, 1);
			}
			else // 자식 노드가 없는경우
			{
				if (position._element->_parent)
				{
					if (position._element->_parent->_left == position._element)
						position._element->_parent->_left = 0;
					else
						position._element->_parent->_right = 0;
				}
				else
					_root = 0;
				_node_allocator.destroy(position._element);
				_node_allocator.deallocate(position._element, 1);
			}
		}

		size_type	erase(const key_type& k)
		{
			iterator	target;

			target = find(k);
			if (target._element == 0)
				return (0);
			else
			{
				erase(target);
				return (1);
			}
		}

		void		erase(iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first++);
			}
		}

		void	swap(Map& x)
		{
			ft::swap(_allocator, x._allocator);
			ft::swap(this->_root, x._root);
			ft::swap(this->_key_comp, x._key_comp);
		}

		void clear()
		{
			this->erase(this->begin(), this->end());
		}

// Return key comparison object
// Returns a copy of the comparison object used by the container to compare keys.

// The comparison object of a map object is set on construction. Its type (member key_compare) is the third template parameter of the map template. By default, this is a less object, which returns the same as operator<.

// This object determines the order of the elements in the container: it is a function pointer or a function object that takes two arguments of the same type as the element keys, and returns true if the first argument is considered to go before the second in the strict weak ordering it defines, and false otherwise.

// Two keys are considered equivalent if key_comp returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).

// Parameters
// none

// Return value
// The comparison object.
// Member type key_compare is the type of the comparison object associated to the container, defined in map as an alias of its third template parameter (Compare).


		key_compare key_comp() const
		{
			return (key_compare());
		}

// Return value comparison object
// Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.

// The arguments taken by this function object are of member type value_type (defined in map as an alias of pair<const key_type,mapped_type>), but the mapped_type part of the value is not taken into consideration in this comparison.

// The comparison object returned is an object of the member type map::value_compare, which is a nested class that uses the internal comparison object to generate the appropriate comparison functional class. It is defined with the same behavior as:

// The public member of this comparison class returns true if the key of the first argument is considered to go before that of the second (according to the strict weak ordering specified by the container's comparison object, key_comp), and false otherwise.

// Notice that value_compare has no public constructor, therefore no objects can be directly created from this nested class outside map members.
// Parameters
// none

// Return value
// The comparison object for element values.
// Member type value_compare is a nested class type (described above).

		value_compare value_comp() const
		{
			return (value_compare(key_compare()));
		}

// Get iterator to element
// Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.

// Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).

// Another member function, map::count, can be used to just check whether a particular key exists.

// Parameters
// k
// Key to be searched for.
// Member type key_type is the type of the keys for the elements in the container, defined in map as an alias of its first template parameter (Key).

// Return value
// An iterator to the element, if an element with specified key is found, or map::end otherwise.

// If the map object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.

// Member types iterator and const_iterator are bidirectional iterator types pointing to elements (of type value_type).
// Notice that value_type in map containers is an alias of pair<const key_type, mapped_type>.
		MapNode<value_type>*		find_key(MapNode<value_type> *node, const key_type &k) const
		{
			if (k < (node->_data).first)
			{
				if (node->_left)
					return (find_key(node->_left, k));
				else
					return (0);
			}
			else if (k > (node->_data).first)
			{
				if (node->_right)
					return (find_key(node->_right, k));
				else
					return (0);
			}
			return (node);
		}

		iterator find (const key_type& k)
		{
			return (find_key(_root, k));
		}

		const_iterator find (const key_type& k) const
		{
			return (find_key(_root, k));
		}

// Count elements with a specific key
// Searches the container for elements with a key equivalent to k and returns the number of matches.

// Because all elements in a map container are unique, the function can only return 1 (if the element is found) or zero (otherwise).

// Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).

// Parameters
// k
// Key to search for.
// Member type key_type is the type of the element keys in the container, defined in map as an alias of its first template parameter (Key).

// Return value
// 1 if the container contains an element whose key is equivalent to k, or zero otherwise.

// Member type size_type is an unsigned integral type.

		size_type count (const key_type& k) const
		{
			if (find_key(_root, k))
				return (1);
			else
				return (0);
		}

// Return iterator to lower bound
// Returns an iterator pointing to the first element in the container whose key is not considered to go before k 
// (i.e., either it is equivalent or goes after).

// The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(element_key,k) would return false.

// If the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is not less than k.

// A similar member function, upper_bound, has the same behavior as lower_bound, except in the case that the map contains an element with a key equivalent to k: In this case, lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.

// Parameters
// k
// Key to search for.
// Member type key_type is the type of the elements in the container, defined in map as an alias of its first template parameter (Key).

// Return value
// An iterator to the the first element in the container whose key is not considered to go before k, or map::end if all keys are considered to go before k.

// If the map object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.

// Member types iterator and const_iterator are bidirectional iterator types pointing to elements (of type value_type).
// Notice that value_type in map containers is itself also a pair type: pair<const key_type, mapped_type>.


		iterator lower_bound (const key_type& k)
		{
			return (find_key(_root, k));
		}

		const_iterator lower_bound (const key_type& k) const
		{
			return (find_key(_root, k));
		}


// Return iterator to upper bound
// Returns an iterator pointing to the first element in the container whose key is considered to go after k.

// The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(k,element_key) would return true.

// If the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is greater than k.

// A similar member function, lower_bound, has the same behavior as upper_bound, except in the case that the map contains an element with a key equivalent to k: In this case lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.

// Parameters
// k
// Key to search for.
// Member type key_type is the type of the elements in the container, defined in map as an alias of its first template parameter (Key).

// Return value
// An iterator to the the first element in the container whose key is considered to go after k, or map::end if no keys are considered to go after k.

// If the map object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.

// Member types iterator and const_iterator are bidirectional iterator types pointing to elements.

		iterator upper_bound (const key_type& k)
		{
			return (++find(k));
		}

		const_iterator upper_bound (const key_type& k) const
		{
			return (++find(k));
		}

// Get range of equal elements
// Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.

// Because the elements in a map container have unique keys, the range returned will contain a single element at most.

// If no matches are found, the range returned has a length of zero, with both iterators pointing to the first element that has a key considered to go after k according to the container's internal comparison object (key_comp).

// Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).

// Parameters
// k
// Key to search for.
// Member type key_type is the type of the elements in the container, defined in map as an alias of its first template parameter (Key).

// Return value
// The function returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).

// If the map object is const-qualified, the function returns a pair of const_iterator. Otherwise, it returns a pair of iterator.

// Member types iterator and const_iterator are bidirectional iterator types pointing to elements (of type value_type).
// Notice that value_type in map containers is itself also a pair type: pair<const key_type, mapped_type>.

		ft::Pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (ft::Pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}

		ft::Pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return (ft::Pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

// Get allocator
// Returns a copy of the allocator object associated with the map.

// Parameters
// none

// Return Value
// The allocator.

// Member type allocator_type is the type of the allocator used by the container, defined in map as an alias of its fourth template parameter (Alloc).

		allocator_type get_allocator() const
		{
			return (_allocator);
		}

	private:

		ft::Pair<iterator, bool>	insert_value(MapNode<value_type> *node, const value_type& val)
		{
			if (val.first < (node->_data).first)
			{
				if (node->_left == 0)
				{
					node->_left = _node_allocator.allocate(1);
					_node_allocator.construct(node->_left, MapNode<value_type>(val));
					node->_left->_parent = node;
					return (ft::Pair<iterator, bool>(node->_left, true));
				}
				else
				{
					return (insert_value(node->_left, val));
				}
			}
			else if (val.first > (node->_data).first)
			{
				if (node->_right == 0)
				{
					node->_right = _node_allocator.allocate(1);
					_node_allocator.construct(node->_right, MapNode<value_type>(val));
					node->_right->_parent = node;
					return (ft::Pair<iterator, bool>(node->_right, true));
				}
				else
				{
					return (insert_value(node->_right, val));
				}
			}
			else
			{
				return (ft::Pair<iterator, bool>(node, false));
			}
		}
	};
}

#endif