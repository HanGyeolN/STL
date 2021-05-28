#ifndef REVERSE_MAP_ITERATOR_HPP
# define REVERSE_MAP_ITERATOR_HPP

# include "MapIterator.hpp"

template <typename T>
class ReverseMapIterator : public MapIterator<T>
{
public:
	ReverseMapIterator		&operator++()
	{
		if (this->_element->_left)
		{
			_element = _element->_left;
			while (_element->_right)
				_element = _element->_right;
		}
		else
		{
			while (_element->_parent && _element->_parent->_left == _element)
				_element = _element->_parent;
			_element = _element->_parent;
		}
		return (*this);
	}

	ReverseMapIterator		operator++(int)
	{
		MapIterator	tmp(*this);
		
		if (this->_element->_left)
		{
			_element = _element->_left;
			while (_element->_right)
				_element = _element->_right;
		}
		else
		{
			while (_element->_parent && _element->_parent->_left == _element)
				_element = _element->_parent;
			_element = _element->_parent;
		}
		return (tmp);
	}
	
	ReverseMapIterator		&operator--()
	{
		if (_element->_right)
		{
			_element = _element->_right;
			while (_element->_left)
				_element = _element->_left;
		}
		else
		{
			while (_element->_parent && _element->_parent->_right == _element)
				_element = _element->_parent;
			_element = _element->_parent;
		}
		return (*this);
	}

	ReverseMapIterator		operator--(int)
	{
		MapIterator	tmp(*this);

		if (_element->_right)
		{
			_element = _element->_right;
			while (_element->_left)
				_element = _element->_left;
		}
		else
		{
			while (_element->_parent && _element->_parent->_right == _element)
				_element = _element->_parent;
			_element = _element->_parent;
		}
		return (tmp);
	}
};

#endif