#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include "Iterator.hpp"

template <typename T>
class ListIterator : public BaseIterator<random_access_iterator_tag, T>
{
public:
	ListIterator();
	ListIterator(const ListIterator &);
	~ListIterator();
};

template <typename Category, typename T, typename Distance, typename Pointer, typename Reference>
ListIterator<Category, T, Distance, Pointer, Reference>::ListIterator()
{
}

ListIterator::~ListIterator()
{
}


#endif