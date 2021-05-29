#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include "Iterator.hpp"
# include "Node.hpp"

template <typename T>
class ListIterator
{
public:
	Node<T>			*_element;
public:
	typedef typename Iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename Iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename Iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T*																	pointer;
	typedef T&																	reference;

	ListIterator()
	{
	};

	ListIterator(Node<T> *element)
	{
		this->_element = element;
	}

	ListIterator(const ListIterator &copy)
	{
		this->_element = copy._element;
	};

	ListIterator&		operator=(const ListIterator &ref)
	{
		this->_element = ref._element;
		return (*this);
	}

	~ListIterator()
	{};

	bool				operator==(const ListIterator &ref)
	{
		return (this->_element == ref._element);
	};

	bool				operator!=(const ListIterator &ref)
	{
		return !(this->_element == ref._element);
	};

	reference			operator*() const
	{
		return (_element->_data);
	}

	pointer				operator->()
	{
		return (&(_element->_data));
	}

	ListIterator		&operator++()
	{
		this->_element = this->_element->_next;
		return (*this);
	}

	ListIterator		operator++(int)
	{
		ListIterator	tmp(*this);

		this->_element = this->_element->_next;
		return (tmp);
	}
	
	ListIterator		&operator--()
	{
		this->_element = this->_element->_prev;
		return (*this);
	}

	ListIterator		operator--(int)
	{
		ListIterator	tmp(*this);

		this->_element = this->_element->_prev;
		return (tmp);
	}
};

#endif