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

		first_type		first;
		second_type		second;

	public:
		Pair() : first(), second() {}

		Pair(const first_type& f, const second_type& s) : first(f), second(s) {}

		template <typename C1, typename C2>
		Pair(const Pair<C1, C2> &copy) : first(copy.first), second(copy.second) {}

		Pair<T1, T2>	&operator=(const Pair<T1, T2> &ref)
		{
			first = ref.first;
			second = ref.second;
			return (*this);
		}

		Pair<T1, T2>	make_pair(const T1 &v1, const T2 &v2)
		{ return (Pair(v1, v2)); }

		friend bool operator== (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
		{ return lhs.first==rhs.first && lhs.second==rhs.second; }

		friend bool operator!= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
		{ return !(lhs==rhs); }

		friend bool operator<  (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
		{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

		friend bool operator<= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
		{ return !(rhs<lhs); }

		friend bool operator>  (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
		{ return rhs<lhs; }

		friend bool operator>= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
		{ return !(lhs<rhs); }
		
	};
}

#endif