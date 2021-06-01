#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "VectorIterator.hpp"
# include "ReverseVectorIterator.hpp"

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool			lexicographical_compare ( InputIterator1 first1, InputIterator1 last1,
											InputIterator2 first2, InputIterator2 last2)
	{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first1 < *first2)
			return (true);
		++first1;
		++first2;
	}
	return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool			equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

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
		allocator_type		_allocator;
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

		Vector				&operator=(const Vector &copy)
		{
			clear();
			size_type		i;

			i = 0;
			_begin = _allocator.allocate(_capacity);
			while (i < copy._size)
			{
				push_back(copy[i]);
				++i;
			}
			return (*this);
		}

		iterator			begin();
		const_iterator		begin() const
		{ return (_begin); }
		iterator			end();
		const_iterator 		end() const
		{ return (_begin + _size); }
		reverse_iterator	rbegin();
		const_reverse_iterator rbegin() const
		{ return (_begin + _size - 1); }
		reverse_iterator	rend();
		const_reverse_iterator rend() const
		{ return (_begin - 1); }

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

		friend bool operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{
			if (lhs.size() == rhs.size())
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			else
				return (false);
		}

		friend bool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{ return (!(lhs == rhs)); }

		friend bool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

		friend bool operator<=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{ return (!(rhs < lhs)); }

		friend bool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{ return (rhs < lhs); }

		friend bool operator>=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
		{ return (!(lhs < rhs)); }
	
	private:
		template <typename U>
		void			swap(U &x, U &y)
		{
			U	temp;

			temp = x;
			x = y;
			y = temp;
		}

		template <typename X>
		void				private_vector(X first, X last);

		template <>
		void				private_vector<int>(int n, int val)
		{
			size_type		i;

			_begin = _allocator.allocate(_capacity);
			i = 0;
			while (i < static_cast<size_type>(n))
			{
				push_back(static_cast<value_type>(val));
				++i;
			}
		}

		

		void				insert_private(iterator position, int n, int val)
		{
			for (size_type i = 0; i < n; ++i)
			{
				insert(position, val);
			}
		}

		template <typename InputIterator>
		void				insert_private(iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *first);
				++position;
				++first;
			}
		}

		template <typename InputIterator>
		void				assign_private(InputIterator first, InputIterator last)
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void				assign_private(int n, int val)
		{
			clear();
			for (size_type i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}
	};

		
}

// 기본생성자, allocator로 기본 용량만큼 할당받고 끝
template <typename T, typename Alloc>
ft::Vector<T, Alloc>::Vector(const allocator_type& alloc) : _capacity(0), _size(0), _allocator(alloc)
{
	_begin = _allocator.allocate(_capacity);
}

// n만큼 공간을 할당받고 val로 할당받은 공간에 construct 한다.
template <typename T, typename Alloc>
ft::Vector<T, Alloc>::Vector(size_type n, const value_type& val, const allocator_type& alloc) : _capacity(n), _size(n), _allocator(alloc)
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

template <typename T, typename Alloc>
	template <typename X>
void		ft::Vector<T, Alloc>::private_vector(X first, X last)
{
	_begin = _allocator.allocate(_capacity);
	while (first != last)
	{
		push_back(*first);
		first++;
	}
}

// 이터레이터 생성자: 이터레이터를 돌면서 값을 집어넣는다.
// Vector<int>(10, 30) 	같은 경우 이 함수로 들어오면 안된다.
// 레퍼런스 참고
template <typename T, typename Alloc>
	template <typename InputIterator>
ft::Vector<T, Alloc>::Vector(InputIterator first, InputIterator last, const allocator_type& alloc) : _capacity(1), _size(0), _allocator(alloc)
{
	private_vector(first, last);
}

// 복사생성자
template <typename T, typename Alloc>
ft::Vector<T, Alloc>::Vector(const Vector &copy) : _capacity(copy._capacity), _size(0), _allocator(copy._allocator)
{
	size_type		i;

	i = 0;
	_begin = _allocator.allocate(_capacity);
	while (i < copy._size)
	{
		push_back(copy[i]);
		++i;
	}
}

// 소멸자
template <typename T, typename Alloc>
ft::Vector<T, Alloc>::~Vector()
{
	clear();
	_allocator.deallocate(_begin, _capacity);
}

/* Iterator */

template <typename T, typename Alloc>
VectorIterator<T>		ft::Vector<T, Alloc>::begin()
{
	return (_begin);
}

template <typename T, typename Alloc>
VectorIterator<T>		ft::Vector<T, Alloc>::end()
{
	return (_begin + _size);
}

template <typename T, typename Alloc>
ReverseVectorIterator<T>	ft::Vector<T, Alloc>::rbegin()
{
	return (_begin + _size - 1);
}

template <typename T, typename Alloc>
ReverseVectorIterator<T>	ft::Vector<T, Alloc>::rend()
{
	return (_begin - 1);
}

/* Capacity */

// 현재 벡터의 사이즈 반환
template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::size_type		ft::Vector<T, Alloc>::size() const
{
	return (_size);
}

// 할당 가능한 최대 크기 반환
template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::size_type		ft::Vector<T, Alloc>::max_size() const
{
	return (_allocator.max_size());
}

// 크기 조절
// n이 현재 사이즈보다 작다면, 그 밖의 요소는 제거
// 크다면, val이 추가됨
// 현재 용량보다 n이 크다면 재할당
template <typename T, typename Alloc>
void		ft::Vector<T, Alloc>::resize(size_type n, value_type val)
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
typename ft::Vector<T, Alloc>::size_type		ft::Vector<T, Alloc>::capacity() const
{
	return (_capacity);
}

// 컨테이너가 비어있는지 확인
template <typename T, typename Alloc>
bool				ft::Vector<T, Alloc>::empty() const
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
void				ft::Vector<T, Alloc>::reserve(size_type n)
{
	if (n == 0)
		n = 1;
	if (n > _capacity)
	{
		pointer		temp;
		size_type	temp_size;

		if (n > _capacity)
		{
			temp = _allocator.allocate(n);
			for (size_t i = 0; i < _size; i++)
				_allocator.construct(temp + i, *(_begin + i));
			temp_size = _size;
			clear();
			_allocator.deallocate(_begin, _capacity);
			_size = temp_size;
			_begin = temp;
			_capacity = n;
		}
	}
}

/* Element Access */

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::reference				ft::Vector<T, Alloc>::operator[](size_type n)
{
	return (*(_begin + n));
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::const_reference				ft::Vector<T, Alloc>::operator[](size_type n) const
{
	return (*(_begin + n));
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::reference				ft::Vector<T, Alloc>::at(size_type n)
{
	if (empty() || n >= _size)
		throw (std::out_of_range("_M_range_check"));
	else
		return (*(_begin + n));
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::const_reference				ft::Vector<T, Alloc>::at(size_type n) const
{
	if (empty() || n >= _size)
		throw (std::out_of_range("_M_range_check"));
	else
		return (*(_begin + n));
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::reference				ft::Vector<T, Alloc>::front()
{
	if (empty())
		throw (std::out_of_range("empty"));
	else
		return (*(_begin));
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::const_reference				ft::Vector<T, Alloc>::front() const
{
	if (empty())
		throw (std::out_of_range("empty"));
	else
		return (*(_begin));
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::reference				ft::Vector<T, Alloc>::back()
{
	if (empty())
		throw (std::out_of_range("empty"));
	else
		return (*(_begin + _size - 1));
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::const_reference				ft::Vector<T, Alloc>::back() const
{
	if (empty())
		throw (std::out_of_range("empty"));
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
void				ft::Vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	assign_private(first, last);
}

template <typename T, typename Alloc>
void				ft::Vector<T, Alloc>::assign(size_type n, const value_type &val)
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
void					ft::Vector<T, Alloc>::push_back(const value_type &value)
{
	if (_size < _capacity)
	{
		_allocator.construct((_begin + _size), value);
		++_size;
	}
	else
	{
		reserve(_capacity * 2);
		_allocator.construct((_begin + _size), value);
		++_size;
	}
}

// 맨뒤에 요소를 제거하고 _size 감소
template <typename T, typename Alloc>
void				ft::Vector<T, Alloc>::pop_back()
{
	if (_size > 0)
	{
		_allocator.destroy(_begin + _size - 1);
		--_size;
	}
}

// 벡터는 지정된 위치의 요소 앞에 새 요소를 삽입하여 확장되며 삽입 된 요소 수만큼 컨테이너 크기를 효과적으로 늘립니다.
// 이렇게하면 새 벡터 크기가 현재 벡터 용량을 초과하는 경우에만 할당 된 저장 공간이 자동으로 재 할당됩니다.
// 벡터는 배열을 기본 저장소로 사용하기 때문에 벡터 끝이 아닌 위치에 요소를 삽입하면 컨테이너가 위치 이후에 있던 모든 요소를 ​​새 위치로 재배치합니다. 
// 이것은 일반적으로 다른 종류의 시퀀스 컨테이너 (예 : list 또는 forward_list)에 의해 동일한 작업에 대해 수행되는 작업에 비해 비효율적 인 작업입니다.
// 매개 변수는 삽입되는 요소 수와 초기화되는 값을 결정합니다.
template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::iterator			ft::Vector<T, Alloc>::insert(iterator position, const value_type &val)
{
	value_type	front;
	value_type	temp;

	if (position != end()) // 끝이 아니라면
	{
		front = *position;
		*position = val;
		position++;
		
		while (position != end())
		{
			
			temp = *position;
			*position = front;
			position++;
			front = temp;
		}
		push_back(front);
	}
	else
	{
		push_back(val);
	}
	return (_begin);
}

// 
template <typename T, typename Alloc>
void				ft::Vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	for (size_type i = 0; i < n; ++i)
	{
		insert(position, val);
	}
}

template <typename T, typename Alloc>
	template <class InputIterator>
void				ft::Vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
{
	insert_private(position, first, last);
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::iterator			ft::Vector<T, Alloc>::erase(iterator position)
{
	size_type	i;
	pointer		ret;
	pointer		temp;
	iterator	iter;

	i = 0;

	// 생성
	temp = _allocator.allocate(_capacity);
	iter = begin();

	// 복사
	while (iter != end())
	{
		if (iter != position)
		{
			_allocator.construct(&temp[i], *iter);
			++i;
		}
		else
		{
			ret = &temp[i];
		}
		++iter;
	}

	// 이전 요소 제거
	clear();
	_allocator.deallocate(_begin, _capacity);
	_begin = temp;
	_size = i;
	
	return (ret);
}

template <typename T, typename Alloc>
typename ft::Vector<T, Alloc>::iterator			ft::Vector<T, Alloc>::erase(iterator first, iterator last)
{
	size_type	i;
	pointer		temp;
	iterator	iter;

	i = 0;

	// 생성
	temp = _allocator.allocate(_capacity);
	iter = begin();

	// 복사
	while (iter != end())
	{
		if (iter == first)
		{
			iter = last - 1;
		}
		else
		{
			_allocator.construct(&temp[i], *iter);
			++i;
		}
		++iter;
	}

	// 이전 요소 제거
	clear();
	_allocator.deallocate(_begin, _capacity);
	_begin = temp;
	_size = i;
	
	return (last);
}

template <typename T, typename Alloc>
void				ft::Vector<T, Alloc>::swap(Vector& x)
{
	swap(_allocator, x._allocator);
	swap(_begin, x._begin);
	swap(_capacity, x._capacity);
	swap(_size, x._size);
}

// _size만큼 모든 원소를 destroy
template <typename T, typename Alloc>
void				ft::Vector<T, Alloc>::clear()
{
	while (_size)
	{
		_allocator.destroy(_begin + _size - 1);
		--_size;
	}
}

#endif