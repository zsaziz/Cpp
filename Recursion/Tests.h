
#ifndef __TESTS_H
#define __TESTS_H

#include <iostream>
#include <cstdlib>

namespace comp201
{
	// Tests that test is within thresh of expected
	//
	// Postconditions: if |expected - test|>thresh, exits
	void assertEquals(double expected, double test, double thresh);
	
	// Tests that test=expected exactly
	//
	// Postconditions: if test!=expected, exits
	void assertEquals(int expected, int test);
	
	// Tests that test=expected exactly
	//
	// Postconditions: if test!=expected, exits
	template <typename T>
	void assertEquals(T expected, T test)
	{
		if ( expected != test )
		{
			std::cout << expected << " != " << test << std::endl;
			exit(1);
		}
		
		std::cout << "Passed!" << std::endl;
	}
	
	// Tests that test=expected exactly
	//
	// Postconditions: if test!=expected, exits
	void assertEquals(const char* expected, std::string test);
	
	// Tests that test is true
	//
	// Postconditions: if !test, exits
	void assertTrue(bool test);
}

#endif
