#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef> // for ptrdiff_t

/*
이 iterator 클래스는 다른 컨테이너의 이터레이터의 base가 되는 클래스이면서,
이 자체로는 이터레이터의 역할을 수행하지 못한다.
대신 모든 이터레이터의 기본값에 대해 정의함
1. 이터레이터의 카테고리
2. 이터레이터의 타입
3. 메모리상 거리의 단위
4. 포인터
5. 레퍼런스
*/

// class형 태그를 이용
class input_iterator_tag {};
class output_iterator_tag {};
class forward_iterator_tag : public input_iterator_tag, public output_iterator_tag {};
class bidirectional_iterator_tag : public forward_iterator_tag {};
class random_access_iterator_tag : public bidirectional_iterator_tag {};

template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
class Iterator
{
public:
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
};

template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
class BaseIterator : public Iterator<Category, T, Distance>
{
protected:
	Pointer			_element;

public:
	BaseIterator();
	BaseIterator(const BaseIterator &copy);
	BaseIterator	&operator=(const BaseIterator &ref);
};

template <typename Category, typename T, typename Distance, typename Pointer, typename Reference>
BaseIterator<Category, T, Distance, Pointer, Reference>::BaseIterator() : _element(0)
{
}

template <typename Category, typename T, typename Distance, typename Pointer, typename Reference>
BaseIterator<Category, T, Distance, Pointer, Reference>::BaseIterator(const BaseIterator &copy) : _element(copy._element)
{
}

template <typename Category, typename T, typename Distance, typename Pointer, typename Reference>
BaseIterator<Category, T, Distance, Pointer, Reference>	&BaseIterator<Category, T, Distance, Pointer, Reference>::operator=(const BaseIterator &ref)
{
	_element = ref._element;
	return (*this);
}

/*
template<typename _Iterator>
struct iterator_traits
{
	typedef typename _Iterator::iterator_category iterator_category;
	typedef typename _Iterator::value_type        value_type;
	typedef typename _Iterator::difference_type   difference_type;
	typedef typename _Iterator::pointer           pointer;
	typedef typename _Iterator::reference         reference;
};

/// Partial specialization for pointer types.
template<typename _Tp>
struct iterator_traits<_Tp*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef _Tp                         value_type;
	typedef ptrdiff_t                   difference_type;
	typedef _Tp*                        pointer;
	typedef _Tp&                        reference;
};

/// Partial specialization for const pointer types.
template<typename _Tp>
struct iterator_traits<const _Tp*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef _Tp                         value_type;
	typedef ptrdiff_t                   difference_type;
	typedef const _Tp*                  pointer;
	typedef const _Tp&                  reference;
};
*/

#endif 