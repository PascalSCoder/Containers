#pragma once

namespace ft
{

template<class T1, class T2>
class pair
{
public:

typedef T1	first_type;
typedef T2	second_type;

	// default (1)	
	pair() {}

	// copy (2)	
	template<class U, class V>
	pair (const pair<U, V>& pr)
	{
		*this = pr;
	}

	// initialization (3)	
	pair (const first_type& a, const second_type& b) : first(a), second(b)
	{
	}

	pair& operator= (const pair& pr)
	{
		first = pr.first;
		second = pr.second;
		return *this;
	}

	T1 first;
	T2 second;
};

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
