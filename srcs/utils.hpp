#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	template <typename U>
	void			swap(U &x, U &y)
	{
		U	temp;

		temp = x;
		x = y;
		y = temp;
	}

	// 사전식 비교
	template <class InputIterator1, class InputIterator2>
	bool			lexicographical_compare ( InputIterator1 first1, InputIterator1 last1,
											InputIterator2 first2, InputIterator2 last2)
	{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first1 < *first2)
			return (true);
		++first1;
		++first2;
	}
	return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool			equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	// 함수 객체를 위해 타입을 정의한 객체
	template <typename Arg1, typename Arg2, class Result>
	class binary_function
	{
	public:
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	// less 함수 객체
	template <typename T>
	class less : public binary_function <T, T, bool>
	{
	public:
		bool operator() (const T& x, const T& y) const
		{
			return (x < y);
		}
	};

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