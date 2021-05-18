#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "Iterator.hpp"

template <typename T>
class VectorIterator : public BaseIterator<random_access_iterator_tag, T>
{
public:	
	typedef typename Iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;
	typedef typename Iterator<random_access_iterator_tag, T>::value_type			value_type;
	typedef typename Iterator<random_access_iterator_tag, T>::difference_type		difference_type;
	typedef T*																pointer;
	typedef T&																reference;
public:
	VectorIterator();
	VectorIterator(pointer element);
	VectorIterator(const VectorIterator &);
	VectorIterator&		operator=(const VectorIterator &);
	~VectorIterator();

	bool				operator==(const VectorIterator &);
	bool				operator!=(const VectorIterator &);

	reference			operator*();
	pointer				operator->();

	// void				operator=(const T &); // *a = b ?? 알아서 되지 않을까

	VectorIterator		&operator++();
	VectorIterator		operator++(int);
	
	VectorIterator		&operator--();
	VectorIterator		operator--(int);
	
	VectorIterator		operator+(int);
	friend VectorIterator		operator+(int, const VectorIterator &);
	VectorIterator		operator-(int);
	VectorIterator		operator-(const VectorIterator &);

	bool				operator<(const VectorIterator &x);
	bool				operator>(const VectorIterator &x);
	bool				operator<=(const VectorIterator &x);
	bool				operator>=(const VectorIterator &x);

	VectorIterator		&operator+=(int);
	VectorIterator		&operator-=(int);
	reference			operator[](int);
};

template <typename T>
VectorIterator<T>::VectorIterator() : BaseIterator<random_access_iterator_tag, T>()
{
}

template <typename T>
VectorIterator<T>::VectorIterator(pointer element) : BaseIterator<random_access_iterator_tag, T>()
{
	this->_element = element;
}

template <typename T>
VectorIterator<T>::VectorIterator(const VectorIterator &copy) : BaseIterator<random_access_iterator_tag, T>()
{
	this->_element = copy._element;
}

template <typename T>
VectorIterator<T>	&VectorIterator<T>::operator=(const VectorIterator &ref)
{
	this->_element = ref._element;
	return (*this);
}

template<typename T>
VectorIterator<T>::~VectorIterator()
{
}

template <typename T>
bool				VectorIterator<T>::operator==(const VectorIterator &ref)
{
	return (this->_element == ref._element);
}

template <typename T>
bool				VectorIterator<T>::operator!=(const VectorIterator &ref)
{
	return !(this->_element == ref._element);
}

template <typename T>
T					&VectorIterator<T>::operator*()
{
	return (*(this->_element));
}

template <typename T>
T					*VectorIterator<T>::operator->()
{
	return (this->_element);
}

template <typename T>
VectorIterator<T>		&VectorIterator<T>::operator++()
{
	++(this->_element);
	return (*this);
}


template <typename T>
VectorIterator<T>		VectorIterator<T>::operator++(int)
{
	VectorIterator	tmp(*this);

	++(this->_element);
	return (tmp);
}

template <typename T>
VectorIterator<T>		&VectorIterator<T>::operator--()
{
	--(this->_element);
	return (*this);
}

template <typename T>
VectorIterator<T>		VectorIterator<T>::operator--(int)
{
	VectorIterator<T>	tmp(*this);

	--(this->_element);
	return (tmp);
}

template <typename T>
VectorIterator<T>		VectorIterator<T>::operator+(int n)
{
	return (this->_element + n);
}

template <typename T>
VectorIterator<T>		operator+(int n, const VectorIterator<T> &iter)
{
	return (iter._element + n);
}

template <typename T>
VectorIterator<T>		VectorIterator<T>::operator-(int n)
{
	return (this->_element - n);
}

template <typename T>
VectorIterator<T>		VectorIterator<T>::operator-(const VectorIterator &iter)
{
	(this->_element) -= iter._element;
	return (*this);
}

template <typename T>
bool				VectorIterator<T>::operator<(const VectorIterator &x)
{
	return (this->_element < x._element);
}


template <typename T>
bool				VectorIterator<T>::operator>(const VectorIterator &x)
{
	return (this->_element > x._element);
}


template <typename T>
bool				VectorIterator<T>::operator<=(const VectorIterator &x)
{
	return (this->_element <= x._element);
}

template <typename T>
bool				VectorIterator<T>::operator>=(const VectorIterator &x)
{
	return (this->_element >= x._element);
}


template <typename T>
VectorIterator<T>		&VectorIterator<T>::operator+=(int n)
{
	(this->_element) += n;
	return (*this);
}

template <typename T>
VectorIterator<T>		&VectorIterator<T>::operator-=(int n)
{
	(this->_element) -= n;
	return (*this);
}

template <typename T>
T						&VectorIterator<T>::operator[](int n)
{
	return (*(this->_element + n));
}

#endif