#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Iterator.hpp"
# include "MapNode.hpp"

template <typename T>
class MapIterator : public BaseIterator<bidirectional_iterator_tag, T, ptrdiff_t, MapNode<T>*, MapNode<T>&>
{
public:
	typedef typename Iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename Iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename Iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef MapNode<T>*															pointer;
	typedef MapNode<T>&															reference;

	MapIterator()
	{
	};

	MapIterator(const pointer element)
	{
		this->_element = element;
	}

	MapIterator(const MapIterator &copy)
	{
		this->_element = copy._element;
	};

	MapIterator&		operator=(const MapIterator &ref)
	{
		this->_element = ref._element;
	}

	~MapIterator()
	{};

	bool				operator==(const MapIterator &ref)
	{
		return (this->_element == ref._element);
	};

	bool				operator!=(const MapIterator &ref)
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

	MapIterator		&operator++()
	{
		if (this->_element->_right)
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

	MapIterator		operator++(int)
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
	
	MapIterator		&operator--()
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

	MapIterator		operator--(int)
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
};

#endif