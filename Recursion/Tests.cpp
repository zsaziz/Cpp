#include <iostream>
#include <cstdlib>
#include <string>

#include "Tests.h"
#include "NumList.h"

using namespace std;

namespace comp201
{

	bool sameByTolerance(double d1, double d2, double tolerance)
	{
		double diff = ( d1 - d2 );
		if ( diff < 0 ) {
			diff *= -1;
		}
		
		return ( diff <= tolerance );
	}

	void assertEquals(double expected, double test, double thresh)
	{
		if ( !sameByTolerance( expected, test, thresh ) )
		{
			cout << expected << " != " << test << endl;
			exit(1);
		}
		
		cout << "Passed!" << endl;
	}
	
	void assertEquals(const char* expected, std::string test)
	{
		if ( expected != test )
		{
			cout << expected << " != " << test << endl;
			exit(1);
		}
		
			cout << "Passed!" << endl;
	}

	void assertTrue(bool test)
	{
		if ( !test )
		{
			cout << "Not true" << endl;
			exit(1);
		}
		
		cout << "Passed!" << endl;
	}

}
