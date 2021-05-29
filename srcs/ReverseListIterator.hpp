#ifndef REVERSE_LIST_ITERATOR_HPP
# define REVERSE_LIST_ITERATOR_HPP

# include "Iterator.hpp"
# include "Node.hpp"

template <typename T>
class ReverseListIterator
{
private:
	Node<T>			*_element;
public:
	typedef typename Iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename Iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename Iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T*															pointer;
	typedef T&															reference;

	ReverseListIterator()
	{
	};

	ReverseListIterator(Node<T> *element)
	{
		this->_element = element;
	}

	ReverseListIterator(const ReverseListIterator &copy)
	{
		this->_element = copy._element;
	};

	ReverseListIterator&		operator=(const ReverseListIterator &ref)
	{
		this->_element = ref._element;
	}

	~ReverseListIterator()
	{};

	bool				operator==(const ReverseListIterator &ref)
	{
		return (this->_element == ref._element);
	};

	bool				operator!=(const ReverseListIterator &ref)
	{
		return !(this->_element == ref._element);
	};

	reference			operator*()
	{
		return ((this->_element->_data));
	}

	pointer				operator->()
	{
		return (this->_element);
	}

	ReverseListIterator		&operator++()
	{
		this->_element = this->_element->_prev;
		return (*this);
	}

	ReverseListIterator		operator++(int)
	{
		ReverseListIterator	tmp(*this);

		this->_element = this->_element->_prev;
		return (tmp);
	}
	
	ReverseListIterator		&operator--()
	{
		this->_element = this->_element->_next;
		return (*this);
	}

	ReverseListIterator		operator--(int)
	{
		ReverseListIterator	tmp(*this);

		this->_element = this->_element->_next;
		return (tmp);
	}
};

#endif