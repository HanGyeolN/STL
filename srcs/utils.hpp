#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	template <typename T1, typename T2>
	class Pair
	{
	public:
		typedef	T1 first_type;
		typedef T2 second_type;

	private:
		first_type		_first;
		second_type		_second;

	public:
		Pair() : _first(), _second() {}

		Pair(const T& first, const T& second) : _first(first), _second(second) {}

		Pair(const Pair &copy) : _first(copy._first), _second(copy._second) {}
		
		Pair	&operator=(const Pair &ref)
		{
			_first = ref._first;
			_second = ref._second;
			return (*this);
		}

		first_type		first()	{ return (_first); }
		second_type		second() { return (_second); }

		template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first==rhs.first && lhs.second==rhs.second; }

		template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs==rhs); }

		template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

		template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(rhs<lhs); }

		template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return rhs<lhs; }

		template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs<rhs); }
		
	}
}

#endif