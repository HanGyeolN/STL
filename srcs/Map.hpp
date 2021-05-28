#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "MapNode.hpp"
# include "MapIterator.hpp"
# include "ReverseMapIterator.hpp"

namespace ft
{
	// Map
	// Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

	// In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key. The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:

	// typedef pair<const Key, T> value_type;

		


	// Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).

	// map containers are generally slower than unordered_map containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.

	// The mapped values in a map can be accessed directly by their corresponding key using the bracket operator ((operator[]).

	// Maps are typically implemented as binary search trees.

	// Container properties

	// Associative
	// 	Elements in associative containers are referenced by their key and not by their absolute position in the container.
	// Ordered
	// 	The elements in the container follow a strict order at all times. All inserted elements are given a position in this order.
	// Map
	// 	Each element associates a key to a mapped value: Keys are meant to identify the elements whose main content is the mapped value.
	// Unique keys
	// 	No two elements in the container can have equivalent keys.
	// Allocator-aware
	// 	The container uses an allocator object to dynamically handle its storage needs.


	// Template parameters

	// Key
	// 	Type of the keys. Each element in a map is uniquely identified by its key value.
	// 	Aliased as member type map::key_type.
	// T
	// 	Type of the mapped value. Each element in a map stores some data as its mapped value.
	// 	Aliased as member type map::mapped_type.
	// Compare
	// 	A binary predicate that takes two element keys as arguments and returns a bool. The expression comp(a,b), where comp is an object of this type and a and b are key values, shall return true if a is considered to go before b in the strict weak ordering the function defines.
	// 	The map object uses this expression to determine both the order the elements follow in the container and whether two element keys are equivalent (by comparing them reflexively: they are equivalent if !comp(a,b) && !comp(b,a)). No two elements in a map container can have equivalent keys.
	// 	This can be a function pointer or a function object (see constructor for an example). This defaults to less<T>, which returns the same as applying the less-than operator (a<b).
	// 	Aliased as member type map::key_compare.
	// Alloc
	// 	Type of the allocator object used to define the storage allocation model. By default, the allocator class template is used, which defines the simplest memory allocation model and is value-independent.
	// 	Aliased as member type map::allocator_type.


	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{

	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef	std::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;
		// typedef ???										value_compare;
		typedef Alloc										allocator_type;
		typedef allocator_type::reference					reference;
		typedef allocator_type::const_reference				const_reference;
		typedef allocator_type::pointer						pointer;
		typedef allocator_type::const_pointer				const_pointer;
		typedef MapIterator<value_type>						iterator;
		typedef const MapIterator<value_type>				const_iterator;
		typedef ReverseMapIterator<value_type>				reverse_iterator;
		typedef const ReverseMapIterator<value_type>		const_reverse_iterator;
		typedef	ptrdiff_t									difference_type;
		typedef size_t										size_type;

	private:
		allocator_type		_allocator;
		pointer				_root;
		pointer				_begin;
		pointer				_end;
		size_type			_size;

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

		explicit Map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()) : _allocator(alloc)
		{
		}

		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{

		}

		Map (const Map& x);

// This destroys all container elements, and deallocates all the storage capacity allocated by the map container using its allocator.
		~Map();

// Copy container content
// Assigns new contents to the container, replacing its current content.

// Copies all the elements from x into the container, changing its size accordingly.

// The container preserves its current allocator, which is used to allocate additional storage if needed.

// The elements stored in the container before the call are either assigned to or destroyed.

// Parameters

// x
//     A map object of the same type (i.e., with the same template parameters, key, T, Compare and Alloc).
// il
//     An initializer_list object. The compiler will automatically construct such objects from initializer list declarators.
//     Member type value_type is the type of the elements in the container, defined in map as an alias of pair<const key_type, mapped_type> (see map member types).


// Return value
// *this 
		Map& operator=(const Map& x);

// Return iterator to beginning
// Returns an iterator referring to the first element in the map container.

// Because map containers keep their elements ordered at all times, begin points to the element that goes first following the container's sorting criterion.

// If the container is empty, the returned iterator value shall not be dereferenced.

// Parameters
// none

// Return Value
// An iterator to the first element in the container.

// If the map object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.

// Member types iterator and const_iterator are bidirectional iterator types pointing to elements (of type value_type).
// Notice that value_type in map containers is an alias of pair<const key_type, mapped_type>.

		iterator begin()
		{
			pointer		begin;

			begin = _root;
			while (begin->_left)
			{
				begin = begin->_left;
			}
			return (begin);
		}

		const_iterator begin() const
		{
			pointer		begin;

			begin = _root;
			while (begin->_left)
			{
				begin = begin->_left;
			}
			return (begin);
		}


// Return iterator to end
// Returns an iterator referring to the past-the-end element in the map container.

// The past-the-end element is the theoretical element that would follow the last element in the map container. It does not point to any element, and thus shall not be dereferenced.

// Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with map::begin to specify a range including all the elements in the container.

// If the container is empty, this function returns the same as map::begin.

// Parameters
// none

// Return Value
// An iterator to the past-the-end element in the container.

// If the map object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.

// Member types iterator and const_iterator are bidirectional iterator types pointing to elements.

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
			pointer		end;

			end = _root;
			while (end->_right)
			{
				end = end->_right;
			}
			return (end);
		}

		const_reverse_iterator rbegin() const
		{
			pointer		end;

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
			if (_size == 0)
				return (true);
			else
				return (false);
		}

		size_type	size() const
		{
			return (_size);
		}

		size_type	max_size() const
		{
			return (_allocator.max_size());
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

// Member type mapped_type is the type of the mapped values in the container, defined in map as an alias of its second template parameter (T).

		mapped_type&	operator[](const key_type& k)
		{
			iterator	target;

			target = find(k);
			if (target._element)
				return (target->second);
			else
			{
				return ((insert(value_type(k, 0))->_data).second);
			}
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
// The single element versions (1) return a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map. The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.

// The versions with a hint (2) return an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map.

// Member type iterator is a bidirectional iterator type that points to elements.
// pair is a class template declared in <utility> (see pair).


		std::pair<iterator, bool>	insert_value(pointer node, const value_type& val)
		{
			if (val.first < (node->_data).first)
			{
				if (node->_left == 0)
				{
					++_size;
					node->_left = _allocator.allocate(1);
					_allocator.construct(node->_left, MapNode<T>(val));
					node->_left->_parent = _node->_left;
					return (std::pair<iterator, bool>(node, true));
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
					++_size;
					node->_right = _allocator.allocate(1);
					_allocator.construct(node->_right, MapNode<T>(val));
					node->_right->_parent = _node->_right;
					return (std::pair<iterator, bool>(node, true));
				}
				else
				{
					return (insert_value(node->_right, val));
				}
			}
			else
			{
				return (std::pair<iterator, bool>(node, false));
			}
		}

		std::pair<iterator, bool> insert(const value_type& val)
		{
			if (_size == 0)
			{
				++_size;
				_root = _allocator.allocate(1);
				_allocator.construct(_root, MapNode<T>(val));
				return (std::pair<iterator, bool>(_root, true));
			}
			else
			{
				return (insert_value(_root, val));
			}
		}

		iterator insert(iterator position, const value_type &val)
		{
			return (insert_value(position._element, val));
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

		void		delete(const pointer &p)
		{
			_allocator.destroy(p);
			_allocator.deallocate(p);
		}

		void		erase(iterator position)
		{
			if (position->_left && position->_right) // 자식 노드가 두개 있는 경우
			{
				iterator		successor(position->_right);

				while (successor->_left)
				{
					successor = successor->_left;
				}
				position->_data = successor->_data;
				erase(successor);
			}
			else if (position->_left || position->_right) // 자식 노드가 하나 있는 경우
			{
				if (position->_left)
				{
					if (position->_parent)
					{
						if (position->_parent->_left == position._element)
							position->_parent->_left = position->_left;
						else
							position->_parent->_right = position->_left;
						position->_left->_parent = position->_parent;
					}
					else
					{
						_root = position->_left;
						position->_left->_parent = position->_parent;
					}
				}
				else
				{
					if (position->_parent)
					{
						if (position->_parent->_left == position._element)
							position->_parent->_left = position->_right;
						else
							position->_parent->_right = position->_right;
						position->_right->_parent = position->_parent;
					}
					else
					{
						_root = position->_right;
						position->_right->_parent = position->_parent;
					}
				}
				delete(position._element);
				--size;
			}
			else // 자식 노드가 없는경우
			{
				if (position->_parent)
				{
					if (position->_parent->_left == position._element)
						position->_parent->_left = 0;
					else
						position->_parent->_right = 0;
				}
				else
					_root = 0;
				delete(position._element);
				--size;
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
				erase(first);
				++first;
			}
		}

// Swap content
// Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.

// After the call to this member function, the elements in this container are those which were in x before the call, 
// and the elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.

// Notice that a non-member function exists with the same name, swap, overloading that algorithm with an optimization that behaves like this member function.

// Whether the internal container allocators and comparison objects are swapped is undefined.

// Parameters
// x
// Another map container of the same type as this 
// (i.e., with the same template parameters, Key, T, Compare and Alloc) whose content is swapped with that of this container.

// Return value
// none
		template <typename T>
		void	swap(const T& a, const T& b)
		{
			T		temp;

			temp = a;
			a = b;
			b = temp;
		}

		void swap (map& x)
		{
			swap(this->_allocator, x._allocator);
			swap(this->_size, x._size);
			swap(this->_root, x._root);
		}

// Clear content
// Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.

// Parameters
// none

// Return value
// none

		void clear()
		{
			iterator	begin;
			iterator	temp;

			begin = begin();
			while (begin != end())
			{
				temp = ++begin;
				_allocator.destroy(begin->_element);
				_allocator.deallocate(begin->_element);
				begin = temp;
			}
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


		key_compare key_comp() const;

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

		value_compare value_comp() const;

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
		pointer		find_key(const pointer &node, const key_type &k)
		{
			if (k < node->first)
			{
				if (node->_left)
					find_key(node->_left, k);
				else
					return (0);
			}
			else if (k > node->first)
			{
				if (node->_right)
					find_key(node->_right, k);
				else
					return (0);
			}
			else
			{
				return (node);
			}
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
			return (++find(_root, k));
		}

		const_iterator upper_bound (const key_type& k) const
		{
			return (++find(_root, k));
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

		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}

		std::pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return (std::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
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

	};
}

#endif