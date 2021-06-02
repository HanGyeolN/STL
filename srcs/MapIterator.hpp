#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Iterator.hpp"
# include "MapNode.hpp"

template <typename T>
class MapIterator : public BaseIterator<bidirectional_iterator_tag, T>
{

public:
	typedef typename Iterator<bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename Iterator<bidirectional_iterator_tag, T>::value_type		value_type;
	typedef typename Iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef typename Iterator<bidirectional_iterator_tag, T>::pointer			pointer;
	typedef typename Iterator<bidirectional_iterator_tag, T>::reference			reference;

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
		return ((this->_element->_data));
	}

	MapIterator<T>		&operator++()
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

	MapIterator<T>		operator++(int)
	{
		MapIterator<T>	tmp(*this);
		
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
	
	MapIterator<T>		&operator--()
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

	MapIterator<T>		operator--(int)
	{
		MapIterator<T>	tmp(*this);

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
};

#endif