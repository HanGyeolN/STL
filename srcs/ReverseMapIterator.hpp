#ifndef REVERSE_MAP_ITERATOR_HPP
# define REVERSE_MAP_ITERATOR_HPP

# include "Iterator.hpp"
# include "MapNode.hpp"

template <typename T>
class ReverseMapIterator
{
public:
	MapNode<T>			*_element;

public:
	typedef typename Iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename Iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename Iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef typename Iterator<bidirectional_iterator_tag, T>::pointer			pointer;
	typedef typename Iterator<bidirectional_iterator_tag, T>::reference			reference;

public:
	
	ReverseMapIterator()
	{
	};

	ReverseMapIterator(MapNode<T> *element)
	{
		this->_element = element;
	}

	ReverseMapIterator(const ReverseMapIterator &copy)
	{
		this->_element = copy._element;
	};

	ReverseMapIterator&		operator=(const ReverseMapIterator &ref)
	{
		this->_element = ref._element;
		return (*this);
	}

	~ReverseMapIterator()
	{};

	bool				operator==(const ReverseMapIterator &ref)
	{
		return (this->_element == ref._element);
	};

	bool				operator!=(const ReverseMapIterator &ref)
	{
		return !(this->_element == ref._element);
	};

	reference			operator*()
	{
		return (this->_element->_data);
	}

	pointer				operator->()
	{
		return (&(this->_element->_data));
	}

	ReverseMapIterator<T>		&operator++()
	{
		if (this->_element->_left)
		{
			this->_element = this->_element->_left;
			while (this->_element->_right)
				this->_element = this->_element->_right;
		}
		else
		{
			while (this->_element->_parent && this->_element->_parent->_left == this->_element)
				this->_element = this->_element->_parent;
			this->_element = this->_element->_parent;
		}
		return (*this);
	}


	ReverseMapIterator<T>		operator++(int)
	{
		ReverseMapIterator<T>	tmp(*this);

		if (this->_element->_left)
		{
			this->_element = this->_element->_left;
			while (this->_element->_right)
				this->_element = this->_element->_right;
		}
		else
		{
			while (this->_element->_parent && this->_element->_parent->_left == this->_element)
				this->_element = this->_element->_parent;
			this->_element = this->_element->_parent;
		}
		return (tmp);
	}
	
	ReverseMapIterator<T>		&operator--()
	{
		if (this->_element->_right)
		{
			this->_element = this->_element->_right;
			while (this->_element->_left)
				this->_element = this->_element->_left;
		}
		else
		{
			while (this->_element->_parent && this->_element->_parent->_right == this->_element)
				this->_element = this->_element->_parent;
			this->_element = this->_element->_parent;
		}
		return (*this);
	}

	ReverseMapIterator<T>		operator--(int)
	{
		ReverseMapIterator<T>	tmp(*this);
		
		if (this->_element->_right)
		{
			this->_element = this->_element->_right;
			while (this->_element->_left)
				this->_element = this->_element->_left;
		}
		else
		{
			while (this->_element->_parent && this->_element->_parent->_right == this->_element)
				this->_element = this->_element->_parent;
			this->_element = this->_element->_parent;
		}
		return (tmp);
	}
};

#endif