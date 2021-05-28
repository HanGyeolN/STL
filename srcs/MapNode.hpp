#ifndef MAP_NODE_HPP
# define MAP_NODE_HPP

template <typename T>
class MapNode
{
public:
	T			_data;
	MapNode*	_parent;
	MapNode*	_left;
	MapNode*	_right;

	MapNode() : _data(0), _parent(0), _left(0), _right(0)
	{
	}

	MapNode(const T& data) : _data(data), _parent(0), _left(0), _right(0)
	{
	}

	MapNode(const MapNode &copy) : _data(copy._data), _parent(copy._parent), _left(copy._left), _right(copy._right)
	{
	}

	MapNode		&operator=(const MapNode &ref)
	{
		this->_data = ref._data;
		this->_parent = ref._parent;
		this->_left = ref._left;
		this->_right = ref._right;
		return (*this);
	}

	~MapNode()
	{
	}

};

#endif