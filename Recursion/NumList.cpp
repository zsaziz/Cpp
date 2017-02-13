#include <string>
#include <cstdlib>
#include <sstream>
#include <ostream>
#include "NumList.h"

template <typename T>
std::string to_string_from_t(T x)
{
	std::ostringstream o;
	std::string ret;
	
	o << x;
	ret.assign( o.str() );
	
	return ret;
}

namespace comp201
{
	NumList::NumList()
	{
	}
	
	NumList::NumList(int front, const NumList& rest)
	{
		l.push_back( front );
		
		for ( std::list<int>::const_iterator it=rest.l.begin(); it!=rest.l.end(); it++ )
		{
			l.push_back( (*it) );
		}
	}
	
	bool NumList::isEmpty() const
	{
		return l.empty();
	}
	
	int NumList::first() const
	{
		return l.front();
	}
	
	NumList NumList::rest() const
	{
		NumList nl;
		for ( std::list<int>::const_iterator it=l.begin(); it!=l.end(); it++ )
		{
			if ( it != l.begin() )
				nl.l.push_back( (*it) );
		}
		
		return nl;
	}
	
	std::string NumList::toString() const
	{
		std::string result = "[";
		
		for ( std::list<int>::const_iterator it=l.begin(); it!=l.end(); it++ )
		{
			result += " ";
			result += to_string_from_t<int>( (*it) );
		}
		
		result += " ]";
		
		return result;
	}
	
	std::ostream& operator <<(std::ostream& outs, const NumList& l)
	{
		outs << l.toString();
		return outs;
	}
	
}
