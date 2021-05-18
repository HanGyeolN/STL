#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "VectorIterator.hpp"
# include "ReverseVectorIterator.hpp"

template < typename T, typename Alloc = std::allocator<T> >
class Vector
{
public:
	// cplusplus에 정의되어 있는 type
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef VectorIterator<T>							iterator;
	typedef const VectorIterator<T>						const_iterator;
	typedef ReverseVectorIterator<T>					reverse_iterator;
	typedef const ReverseVectorIterator<T>				const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

private:
	// allocator_type	_allocator;
	std::allocator<T>	_allocator;
	pointer				_begin;
	size_t				_capacity;
	size_t				_size;

public:
	explicit Vector(const allocator_type& alloc = allocator_type());
	explicit Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

	template <typename InputIterator>
	Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	Vector(const Vector &);

	~Vector();

	Vector				&operator=(const Vector &copy);
	iterator			begin();
	iterator			end();
	reverse_iterator	rbegin();
	reverse_iterator	rend();

	size_type			size() const;
	size_type			max_size() const;
	void				resize(size_type n, value_type val = value_type());
	size_type			capacity() const;
	bool				empty() const;
	void				reserve(size_type n);

	reference			operator[](size_type n);
	const_reference		operator[](size_type n) const;
	reference			at(size_type n);
	const_reference		at(size_type n) const;
	reference			front();
	const_reference		front() const;
	reference			back();
	const_reference		back() const;


	template <typename InputIterator>
	void				assign(InputIterator first, InputIterator last);
	void				assign(size_type n, const value_type &val);
	void				push_back(const value_type &value);
	void				pop_back();
	iterator			insert(iterator position, const value_type &val);
	void				insert(iterator position, size_type n, const value_type& val);
	template <class InputIterator>
	void				insert(iterator position, InputIterator first, InputIterator last);
	iterator			erase(iterator position);
	iterator			erase(iterator first, iterator last);
	void				swap(Vector& x);
	void				clear();
};

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(const allocator_type& alloc) : _capacity(10), _size(0)
{
	_begin = _allocator.allocate(_capacity);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(size_type n, const value_type& val, const allocator_type& alloc) : _capacity(n), _size(n)
{
	_begin = _allocator.allocate(_capacity);
}

template <typename T, typename Alloc>
	template <typename InputIterator>
Vector<T, Alloc>::Vector (InputIterator first, InputIterator last, const allocator_type& alloc) : _capacity(10), _size(0), _allocator(alloc)
{
	_begin = _allocator.allocate(_capacity);
	while (first != last)
	{
		push_back(*first);
		first++;
	}
}

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(const Vector &copy) : _capacity(copy._capacity), _size(copy._size), _allocator(copy._allocator)
{
}

template <typename T, typename Alloc>
Vector<T, Alloc>::~Vector()
{
	_allocator.destroy(_begin);
	_allocator.deallocate(_begin, _capacity);
}

template <typename T, typename Alloc>
VectorIterator<T>		Vector<T, Alloc>::begin()
{
	return (_begin);
}

template <typename T, typename Alloc>
VectorIterator<T>		Vector<T, Alloc>::end()
{
	return (_begin + _size);
}

template <typename T, typename Alloc>
ReverseVectorIterator<T>	Vector<T, Alloc>::rbegin()
{
	return (_begin + _size - 1);
}

template <typename T, typename Alloc>
ReverseVectorIterator<T>	Vector<T, Alloc>::rend()
{
	return (_begin - 1);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::size_type		Vector<T, Alloc>::size() const
{
	return (_size);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::size_type		Vector<T, Alloc>::max_size() const
{
	return (_allocator.max_size());
}

// 크기 조절
template <typename T, typename Alloc>
void		Vector<T, Alloc>::resize(size_type n, value_type val)
{

}

template <typename T, typename Alloc>
Vector<T, Alloc>::size_type			Vector<T, Alloc>::capacity() const
{
	return (_capacity);
}

template <typename T, typename Alloc>
bool				Vector<T, Alloc>::empty() const
{
	if (_size == 0)
		return (true);
	else
		return (false);
}

// capacity 재설정
template <typename T, typename Alloc>
void				Vector<T, Alloc>::reserve(size_type n)
{

}

//
template <typename T, typename Alloc>
Vector<T, Alloc>::reference				Vector<T, Alloc>::operator[](size_type n)
{
	if (empty() || n >= _size)
		throw (std::out_of_range());
	else
		return (*(_begin + n));
}

template <typename T, typename Alloc>
Vector<T, Alloc>::const_reference				Vector<T, Alloc>::operator[](size_type n) const
{
	if (empty() || n >= _size)
		throw (std::out_of_range());
	else
		return (*(_begin + n));
}

template <typename T, typename Alloc>
Vector<T, Alloc>::reference				Vector<T, Alloc>::at(size_type n)
{
	if (n >= _size)
		throw (std::out_of_range());
	else
		return (*(_begin + n));
}

template <typename T, typename Alloc>
Vector<T, Alloc>::const_reference				Vector<T, Alloc>::at(size_type n) const
{
	if (empty())
		throw (std::out_of_range());
	else
		return (*(_begin + n));
}

template <typename T, typename Alloc>
Vector<T, Alloc>::reference				Vector<T, Alloc>::front()
{
	if (empty())
		throw (std::out_of_range());
	else
		return (*(_begin));
}

template <typename T, typename Alloc>
Vector<T, Alloc>::const_reference				Vector<T, Alloc>::front() const
{
	if (empty())
		throw (std::out_of_range());
	else
		return (*(_begin));
}

template <typename T, typename Alloc>
Vector<T, Alloc>::reference				Vector<T, Alloc>::back()
{
	if (empty())
		throw (std::out_of_range());
	else
		return (*(_begin + _size - 1));
}

template <typename T, typename Alloc>
Vector<T, Alloc>::const_reference				Vector<T, Alloc>::back() const
{
	if (empty())
		throw (std::out_of_range());
	else
		return (*(_begin + _size - 1));
}

/* Modifier */

template <typename T, typename Alloc>
	template <typename InputIterator>
void				Vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	
}


template <typename T, typename Alloc>
void				Vector<T, Alloc>::assign(size_type n, const value_type &val)
{
	if (n > _capacity)
	{
		pointer		temp;

		temp = _begin;
	}
	else
	{
gi
	}
}

template <typename T, typename Alloc>
void					Vector<T, Alloc>::push_back(const value_type &value)
{
	if (_size < _capacity)
	{
		_allocator.construct((_begin + _size), value);
		++_size;
	}
	else
	{
		pointer		temp;

		temp = _begin;
		_begin = _allocator.allocate(_capacity * 2);

		for (size_t i = 0; i < _size; i++)
		{
			_allocator.construct(_begin + i, *(temp + i));
		}
		_allocator.construct((_begin + _size), value);

		_allocator.destroy(temp);
		_allocator.deallocate(temp, _size);
		
		++_size;
		_capacity = _capacity * 2;
		
		// 재할당
		// 복사
		// 해제
		// 기타 변수 변경				
	}
}

template <typename T, typename Alloc>
void				Vector<T, Alloc>::pop_back()
{
	if (_size > 0)
	{
		_allocator.destroy(_begin + _size - 1);
		--_size;
	}
}

template <typename T, typename Alloc>
Vector<T, Alloc>::iterator			Vector<T, Alloc>::insert(iterator position, const value_type &val)
{
	*position = val;
}

template <typename T, typename Alloc>
void				Vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	
}

template <typename T, typename Alloc>
	template <class InputIterator>
void				Vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
{
	while ()
}

template <typename T, typename Alloc>
Vector<T, Alloc>::iterator			Vector<T, Alloc>::erase(iterator position)
{}

template <typename T, typename Alloc>
Vector<T, Alloc>::iterator			Vector<T, Alloc>::erase(iterator first, iterator last)
{}

template <typename T, typename Alloc>
void				Vector<T, Alloc>::swap(Vector& x)
{}

template <typename T, typename Alloc>
void				Vector<T, Alloc>::clear()
{}



#endif