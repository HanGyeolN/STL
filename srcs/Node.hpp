#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>

template <typename T>
class Node
{
public:
	T				_data;
	Node			*_next;
	Node			*_prev;

public:
// Constructor
	Node();
	Node(const T &data);
	Node(const Node &);
// Destructor
	~Node();
// etc
	Node	&operator=(const Node &);
	Node	&operator++();
	Node	&operator--();
};

template <typename T>
Node<T>::Node() : _data(0), _next(0), _prev(0)
{
	std::cout << "Node constructor called." << std::endl; // test
}

template <typename T>
Node<T>::Node(const T &data) : _data(data), _next(0), _prev(0)
{
}

template <typename T>
Node<T>::Node(const Node<T> &copy) : _data(copy._data), _next(copy._next), _prev(copy._prev)
{
}

template <typename T>
Node<T>::~Node()
{
	std::cout << "Node destructor called." << std::endl; // test
}

template <typename T>
Node<T>		&Node<T>::operator=(const Node<T> &ref)
{
	_data = ref._data;
	_next = ref._next;
	_prev = ref._prev;
	return (*this);
}

template <typename T>
Node<T>		&Node<T>::operator++()
{
	return *(this->_next);
}

template <typename T>
Node<T>		&Node<T>::operator--()
{
	return *(this->_prev);
}

#endif