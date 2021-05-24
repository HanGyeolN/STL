#ifndef MAP_HPP
# define MAP_HPP

# include <memory>

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
		typedef Key			key_type;
		typedef T			mapped_type;
		typedef	std::pair<const key_type, mapped_type>		value_type;
		typedef Compare		key_compare;
		// typedef ???		value_compare;
		typedef Alloc		allocator_type;
		typedef allocator_type::reference		reference;
		typedef allocator_type::const_reference	const_reference;
		typedef allocator_type::pointer			pointer;
		typedef allocator_type::const_pointer	const_pointer;
		// typedef MapIterator???					iterator;
		// typedef ???								const_iterator;
		// typedef ???								reverse_iterator;
		// typedef ???								const_reverse_iterator;
		typedef	ptrdiff_t						difference_type;
		typedef size_t							size_type;

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

		explicit Map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type());

		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

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
		Map& operator(const Map& x);

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

		iterator begin();
		const_iterator begin() const;


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

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

		bool		empty() const;
		size_type	size() const;
		size_type	max_size() const;

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

		mapped_type&	operator[](const key_type& k);

// Insert elements
// Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.

// Because element keys in a map are unique, the insertion operation checks whether each inserted element has a key equivalent to the one of an element already in the container, and if so, the element is not inserted, returning an iterator to this existing element (if the function returns a value).

// For a similar container allowing for duplicate elements, see multimap.

// An alternative way to insert elements in a map is by using member function map::operator[].

// Internally, map containers keep all their elements sorted by their key following the criterion specified by its comparison object. The elements are always inserted in its respective position following this ordering.

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
//     Notice that this is just a hint and does not force the new element to be inserted at that position within the map container (the elements in a map always follow a specific order depending on their key).
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

		pair<iterator, bool> insert(const value_type& val);
		iterator insert(iterator position, const value_type &val);
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last);


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
//     Iterators specifying a range within the map container to be removed: [first,last). i.e., the range includes all the elements between first and last, including the element pointed by first but not the one pointed by last.
//     Member types iterator and const_iterator are bidirectional iterator types that point to elements.


// Return value
// For the key-based version (2), the function returns the number of elements erased.

// Member type size_type is an unsigned integral type.

		void	erase(iterator position);
		size_type	erase(const key_type& k);
		void	erase(iterator first, iterator last);
	};
}

#endif