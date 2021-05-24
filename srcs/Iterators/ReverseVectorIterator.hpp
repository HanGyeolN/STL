#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "Iterator.hpp"

template <typename T>
class ReverseVectorIterator : public BaseIterator<random_access_iterator_tag, T>
{
public:	
	typedef typename Iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;
	typedef typename Iterator<random_access_iterator_tag, T>::value_type			value_type;
	typedef typename Iterator<random_access_iterator_tag, T>::difference_type		difference_type;
	typedef T*																pointer;
	typedef T&																reference;
public:
	ReverseVectorIterator();
	ReverseVectorIterator(pointer element);
	ReverseVectorIterator(const ReverseVectorIterator &);
	ReverseVectorIterator&		operator=(const ReverseVectorIterator &);
	~ReverseVectorIterator();

	bool				operator==(const ReverseVectorIterator &);
	bool				operator!=(const ReverseVectorIterator &);

	reference			operator*();
	pointer				operator->();

	// void				operator=(const T &); // *a = b ?? 알아서 되지 않을까

	ReverseVectorIterator		&operator++();
	ReverseVectorIterator		operator++(int);
	
	ReverseVectorIterator		&operator--();
	ReverseVectorIterator		operator--(int);
	
	ReverseVectorIterator		operator+(int);
	friend ReverseVectorIterator		operator+(int, const ReverseVectorIterator &);
	ReverseVectorIterator		operator-(int);
	ReverseVectorIterator		operator-(const ReverseVectorIterator &);

	bool				operator<(const ReverseVectorIterator &x);
	bool				operator>(const ReverseVectorIterator &x);
	bool				operator<=(const ReverseVectorIterator &x);
	bool				operator>=(const ReverseVectorIterator &x);

	ReverseVectorIterator		&operator+=(int);
	ReverseVectorIterator		&operator-=(int);
	reference			operator[](int);
};

template <typename T>
ReverseVectorIterator<T>::ReverseVectorIterator() : BaseIterator<random_access_iterator_tag, T>()
{
}

template <typename T>
ReverseVectorIterator<T>::ReverseVectorIterator(pointer element) : BaseIterator<random_access_iterator_tag, T>()
{
	this->_element = element;
}

template <typename T>
ReverseVectorIterator<T>::ReverseVectorIterator(const ReverseVectorIterator &copy) : BaseIterator<random_access_iterator_tag, T>()
{
	this->_element = copy._element;
}

template <typename T>
ReverseVectorIterator<T>	&ReverseVectorIterator<T>::operator=(const ReverseVectorIterator &ref)
{
	this->_element = ref._element;
	return (*this);
}

template<typename T>
ReverseVectorIterator<T>::~ReverseVectorIterator()
{
}

template <typename T>
bool				ReverseVectorIterator<T>::operator==(const ReverseVectorIterator &ref)
{
	return (this->_element == ref._element);
}

template <typename T>
bool				ReverseVectorIterator<T>::operator!=(const ReverseVectorIterator &ref)
{
	return !(this->_element == ref._element);
}

template <typename T>
T					&ReverseVectorIterator<T>::operator*()
{
	return (*(this->_element));
}

template <typename T>
T					*ReverseVectorIterator<T>::operator->()
{
	return (this->_element);
}

template <typename T>
ReverseVectorIterator<T>		&ReverseVectorIterator<T>::operator++()
{
	--(this->_element);
	return (*this);
}

// 후위 연산자
template <typename T>
ReverseVectorIterator<T>		ReverseVectorIterator<T>::operator++(int)
{
	ReverseVectorIterator	tmp(*this);

	--(this->_element);
	return (tmp);
}

template <typename T>
ReverseVectorIterator<T>		&ReverseVectorIterator<T>::operator--()
{
	++(this->_element);
	return (*this);
}

template <typename T>
ReverseVectorIterator<T>		ReverseVectorIterator<T>::operator--(int)
{
	ReverseVectorIterator<T>	tmp(*this);

	++(this->_element);
	return (tmp);
}

template <typename T>
ReverseVectorIterator<T>		ReverseVectorIterator<T>::operator+(int n)
{
	return (this->_element - n);
}

template <typename T>
ReverseVectorIterator<T>		operator+(int n, const ReverseVectorIterator<T> &iter)
{
	return (iter._element - n);
}

template <typename T>
ReverseVectorIterator<T>		ReverseVectorIterator<T>::operator-(int n)
{
	return (this->_element + n);
}

template <typename T>
ReverseVectorIterator<T>		ReverseVectorIterator<T>::operator-(const ReverseVectorIterator &iter)
{
	(this->_element) += iter._element;
	return (*this);
}

template <typename T>
bool				ReverseVectorIterator<T>::operator<(const ReverseVectorIterator &x)
{
	return (this->_element > x._element);
}


template <typename T>
bool				ReverseVectorIterator<T>::operator>(const ReverseVectorIterator &x)
{
	return (this->_element < x._element);
}


template <typename T>
bool				ReverseVectorIterator<T>::operator<=(const ReverseVectorIterator &x)
{
	return (this->_element >= x._element);
}

template <typename T>
bool				ReverseVectorIterator<T>::operator>=(const ReverseVectorIterator &x)
{
	return (this->_element <= x._element);
}


template <typename T>
ReverseVectorIterator<T>		&ReverseVectorIterator<T>::operator+=(int n)
{
	(this->_element) -= n;
	return (*this);
}

template <typename T>
ReverseVectorIterator<T>		&ReverseVectorIterator<T>::operator-=(int n)
{
	(this->_element) += n;
	return (*this);
}

template <typename T>
T						&ReverseVectorIterator<T>::operator[](int n)
{
	return (*(this->_element - n));
}


#endif