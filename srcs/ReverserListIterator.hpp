#ifndef REVERSE_LIST_ITERATOR_HPP
# define REVERSE_LIST_ITERATOR_HPP

# include "Iterator.hpp"
# include "Node.hpp"

template <typename T>
class ListIterator : public BaseIterator<bidirectional_iterator_tag, T, ptrdiff_t, Node<T>*, Node<T>&>
{
public:
	typedef typename Iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename Iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename Iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef Node<T>*															pointer;
	typedef Node<T>&															reference;

	ListIterator()
	{
	};

	ListIterator(const pointer element)
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
	}

	~ListIterator()
	{};

	bool				operator==(const ListIterator &)
	{
		return (this->_element == ref._element);
	};

	bool				operator!=(const ListIterator &)
	{
		return !(this->_element == ref._element);
	};

	reference			operator*()
	{
		return (*(this->_element));
	}

	pointer				operator->()
	{
		return (this->_element);
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