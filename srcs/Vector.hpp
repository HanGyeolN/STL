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

// 기본생성자, allocator로 기본 용량만큼 할당받고 끝
template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(const allocator_type& alloc) : _capacity(10), _size(0), _allocator(alloc)
{
	_begin = _allocator.allocate(_capacity);
}

// n만큼 공간을 할당받고 val로 할당받은 공간에 construct 한다.
template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(size_type n, const value_type& val, const allocator_type& alloc) : _capacity(n), _size(n), _allocator(alloc)
{
	size_type		i;

	_begin = _allocator.allocate(_capacity);
	i = 0;
	while (i < n)
	{
		push_back(val);
		++i;
	}
}

// 이터레이터 생성자: 이터레이터를 돌면서 값을 집어넣는다.
// Vector<int>(10, 30) 	같은 경우 이 함수로 들어오면 안된다.
// 레퍼런스 참고
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

// 복사생성자
template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(const Vector &copy) : _capacity(copy._capacity), _size(copy._size), _allocator(copy._allocator)
{
	size_type		i;

	i = 0;
	_begin = _allocator.allocate(_capacity);
	while (i < _size)
	{
		push_back(copy[i]);
		++i;
	}
}

// 소멸자
template <typename T, typename Alloc>
Vector<T, Alloc>::~Vector()
{
	clear();
	_allocator.deallocate(_begin, _capacity);
}

/* Iterator */

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

/* Capacity */

// 현재 벡터의 사이즈 반환
template <typename T, typename Alloc>
Vector<T, Alloc>::size_type		Vector<T, Alloc>::size() const
{
	return (_size);
}

// 할당 가능한 최대 크기 반환
template <typename T, typename Alloc>
Vector<T, Alloc>::size_type		Vector<T, Alloc>::max_size() const
{
	return (_allocator.max_size());
}

// 크기 조절
// n이 현재 사이즈보다 작다면, 그 밖의 요소는 제거
// 크다면, val이 추가됨
// 현재 용량보다 n이 크다면 재할당
template <typename T, typename Alloc>
void		Vector<T, Alloc>::resize(size_type n, value_type val)
{
	size_type		i;

	if (_size > n)
	{
		while (_size > n)
			pop_back();
	}
	else if (_size < n)
	{
		while (_size < n)
			push_back(val);
	}
}

// 컨테이너에 할당된 메모리 크기 반환
template <typename T, typename Alloc>
Vector<T, Alloc>::size_type			Vector<T, Alloc>::capacity() const
{
	return (_capacity);
}

// 컨테이너가 비어있는지 확인
template <typename T, typename Alloc>
bool				Vector<T, Alloc>::empty() const
{
	if (_size == 0)
		return (true);
	else
		return (false);
}

// 벡터 용량이 최소한 n 개의 요소를 포함하기에 충분하도록 요청합니다.
// n이 현재 벡터 용량보다 크면이 함수는 컨테이너가 스토리지를 다시 할당하여 용량을 n (또는 그 이상)으로 늘립니다.
// 다른 모든 경우에는 함수 호출로 인해 재 할당이 발생하지 않으며 벡터 용량에 영향을주지 않습니다.
// 이 함수는 벡터 크기에 영향을주지 않으며 요소를 변경할 수 없습니다.
template <typename T, typename Alloc>
void				Vector<T, Alloc>::reserve(size_type n)
{
	if (n > _capacity)
	{
		pointer		temp;

		temp = _allocator.allocate(n);
		for (size_t i = 0; i < _size; i++)
			_allocator.construct(temp + i, *(temp + i));

		clear();
		_allocator.deallocate(_begin, _capacity);

		_begin = temp;
		_capacity = n;
	}
}

/* Element Access */

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

// 벡터에 새 내용을 할당하고 현재 내용을 바꾸고 그에 따라 크기를 수정합니다.
// 범위 버전 (1)에서 새 콘텐츠는 첫 번째와 마지막 사이의 범위에있는 각 요소에서 동일한 순서로 구성된 요소입니다.
// 채우기 버전 (2)에서 새 내용은 n 개의 요소이며 각각 val의 복사본으로 초기화됩니다.
// 재 할당이 발생하면 필요한 스토리지가 내부 할당자를 사용하여 할당됩니다.
// 호출 전에 컨테이너에 보유 된 모든 요소는 소멸되고 새로 구성된 요소로 대체됩니다 (요소 할당이 발생하지 않음).
// 이렇게하면 새 벡터 크기가 현재 벡터 용량을 초과하는 경우에만 할당 된 저장 공간이 자동으로 재 할당됩니다.
template <typename T, typename Alloc>
	template <typename InputIterator>
void				Vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	clear();
	while (first != last)
	{
		push_back(*first);
		++first;
	}
}

template <typename T, typename Alloc>
void				Vector<T, Alloc>::assign(size_type n, const value_type &val)
{
	clear();
	for (size_type i = 0; i < n; ++i)
	{
		push_back(val);
	}
}

// value를 뒤에 추가
// 만약 _capacity보다 _size가 커지면 재할당
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
		reserve(_capacity * 2);
		push_back(value);
	}
}

// 맨뒤에 요소를 제거하고 _size 감소
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

// _size만큼 모든 원소를 destroy
template <typename T, typename Alloc>
void				Vector<T, Alloc>::clear()
{
	while (_size)
	{
		_allocator.destroy(_begin + _size - 1);
		--_size;
	}
}



#endif