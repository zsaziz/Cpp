#include <iostream>

#include "TestRecursion.h"
#include "NumList.h"
#include "Tests.h"
#include "HW8.h"

using namespace std;

namespace comp201
{
	
	const comp201::NumList lEmpty;
	const comp201::NumList lOne( 1, lEmpty );
	const comp201::NumList lTwo( 2, lEmpty );
	const comp201::NumList lOneTwo( 1, lTwo );
	const comp201::NumList lOneTwoThreeFour( 1, comp201::NumList( 2, comp201::NumList( 3, comp201::NumList( 4, lEmpty ) ) ) );
	const comp201::NumList lSevenEightNine( 7, comp201::NumList( 8, comp201::NumList( 9, lEmpty ) ) );
	
	//
	
	void header(const char* title)
	{
		cout << endl;
		cout << "##################" << endl;
		cout << "## " << title << endl;
		cout << "##################" << endl << endl;
	}

	void testToString()
	{
		
		header( "toString" );
		{
			assertEquals( "[ ]", lEmpty.toString() );
			assertEquals( "[ 1 ]", lOne.toString() );
			assertEquals( "[ 2 ]", lTwo.toString() );
			assertEquals( "[ 1 2 ]", lOneTwo.toString() );
			assertEquals( "[ 1 2 3 4 ]", lOneTwoThreeFour.toString() );
			assertEquals( "[ 7 8 9 ]", lSevenEightNine.toString() );
		}
		cout << endl;
		
	}
	
	void testSum()
	{
		
		header( "Sum" );
		{
			assertEquals<int>( 0, sum( lEmpty ) );
			assertEquals<int>( 1, sum( lOne ) );
			assertEquals<int>( 2, sum( lTwo ) );
			assertEquals<int>( 3, sum( lOneTwo ) );
			assertEquals<int>( 10, sum( lOneTwoThreeFour ) );
			assertEquals<int>( 24, sum( lSevenEightNine ) );
		}
		cout << endl;
		
	}
	
	void testProduct()
	{
		
		header( "Product" );
		{
			assertEquals<int>( 1, product( lEmpty ) );
			assertEquals<int>( 1, product( lOne ) );
			assertEquals<int>( 2, product( lTwo ) );
			assertEquals<int>( 2, product( lOneTwo ) );
			assertEquals<int>( 24, product( lOneTwoThreeFour ) );
			assertEquals<int>( 504, product( lSevenEightNine ) );
		}
		cout << endl;
		
	}
	
	void testReverse()
	{
		
		header( "Reverse" );
		{
			assertEquals( "[ ]", reverse( lEmpty ).toString() );
			assertEquals( "[ 1 ]", reverse( lOne ).toString() );
			assertEquals( "[ 2 ]", reverse( lTwo ).toString() );
			assertEquals( "[ 2 1 ]", reverse( lOneTwo ).toString() );
			assertEquals( "[ 4 3 2 1 ]", reverse( lOneTwoThreeFour ).toString() );
			assertEquals( "[ 9 8 7 ]", reverse( lSevenEightNine ).toString() );
		}
		cout << endl;
		
	}
	
	void testAppend()
	{
		
		header( "Append" );
		{
			assertEquals( "[ 7 8 9 7 8 9 ]", append( lSevenEightNine, lSevenEightNine ).toString() );
			
			assertEquals( "[ 7 8 9 ]", append( lSevenEightNine, lEmpty ).toString() );
			assertEquals( "[ 7 8 9 ]", append( lEmpty, lSevenEightNine ).toString() );
			
			assertEquals( "[ 7 8 9 1 ]", append( lSevenEightNine, lOne ).toString() );
			assertEquals( "[ 1 7 8 9 ]", append( lOne, lSevenEightNine ).toString() );
			
			assertEquals( "[ 7 8 9 2 ]", append( lSevenEightNine, lTwo ).toString() );
			assertEquals( "[ 2 7 8 9 ]", append( lTwo, lSevenEightNine ).toString() );
			
			assertEquals( "[ 7 8 9 1 2 ]", append( lSevenEightNine, lOneTwo ).toString() );
			assertEquals( "[ 1 2 7 8 9 ]", append( lOneTwo, lSevenEightNine ).toString() );
			
			assertEquals( "[ 7 8 9 1 2 3 4 ]", append( lSevenEightNine, lOneTwoThreeFour ).toString() );
			assertEquals( "[ 1 2 3 4 7 8 9 ]", append( lOneTwoThreeFour, lSevenEightNine ).toString() );
		}
		cout << endl;
		
	}
	
	void testFilterEven()
	{
		
		header( "FilterEven" );
		{
			assertEquals( "[ ]", filterEven( lEmpty ).toString() );
			assertEquals( "[ ]", filterEven( lOne ).toString() );
			assertEquals( "[ 2 ]", filterEven( lTwo ).toString() );
			assertEquals( "[ 2 ]", filterEven( lOneTwo ).toString() );
			assertEquals( "[ 2 4 ]", filterEven( lOneTwoThreeFour ).toString() );
			assertEquals( "[ 8 ]", filterEven( lSevenEightNine ).toString() );
			
			assertEquals( "[ ]", reverse( filterEven( lEmpty ) ).toString() );
			assertEquals( "[ ]", reverse( filterEven( lOne ) ).toString() );
			assertEquals( "[ 2 ]", reverse( filterEven( lTwo ) ).toString() );
			assertEquals( "[ 2 ]", reverse( filterEven( lOneTwo ) ).toString() );
			assertEquals( "[ 4 2 ]", reverse( filterEven( lOneTwoThreeFour ) ).toString() );
			assertEquals( "[ 8 ]", reverse( filterEven( lSevenEightNine ) ).toString() );
		}
		cout << endl;
		
	}
	
	void testFilterOdd()
	{
		
		header( "FilterOdd" );
		{
			assertEquals( "[ ]", filterOdd( lEmpty ).toString() );
			assertEquals( "[ 1 ]", filterOdd( lOne ).toString() );
			assertEquals( "[ ]", filterOdd( lTwo ).toString() );
			assertEquals( "[ 1 ]", filterOdd( lOneTwo ).toString() );
			assertEquals( "[ 1 3 ]", filterOdd( lOneTwoThreeFour ).toString() );
			assertEquals( "[ 7 9 ]", filterOdd( lSevenEightNine ).toString() );
			
			assertEquals( "[ ]", reverse( filterOdd( lEmpty ) ).toString() );
			assertEquals( "[ 1 ]", reverse( filterOdd( lOne ) ).toString() );
			assertEquals( "[ ]", reverse( filterOdd( lTwo ) ).toString() );
			assertEquals( "[ 1 ]", reverse( filterOdd( lOneTwo ) ).toString() );
			assertEquals( "[ 3 1 ]", reverse( filterOdd( lOneTwoThreeFour ) ).toString() );
			assertEquals( "[ 9 7 ]", reverse( filterOdd( lSevenEightNine ) ).toString() );
		}
		cout << endl;
		
	}
	
	void testRotate()
	{
		
		header( "Rotate" );
		{
			assertEquals( "[ ]", rotate( lEmpty, 0 ).toString() );
			assertEquals( "[ ]", rotate( lEmpty, 1 ).toString() );
			
			assertEquals( "[ 1 ]", rotate( lOne, 0 ).toString() );
			assertEquals( "[ 1 ]", rotate( lOne, 1 ).toString() );
			assertEquals( "[ 1 ]", rotate( lOne, 2 ).toString() );
			
			assertEquals( "[ 2 ]", rotate( lTwo, 0 ).toString() );
			assertEquals( "[ 2 ]", rotate( lTwo, 1 ).toString() );
			assertEquals( "[ 2 ]", rotate( lTwo, 2 ).toString() );
			
			assertEquals( "[ 1 2 ]", rotate( lOneTwo, 0 ).toString() );
			assertEquals( "[ 2 1 ]", rotate( lOneTwo, 1 ).toString() );
			assertEquals( "[ 1 2 ]", rotate( lOneTwo, 2 ).toString() );
			assertEquals( "[ 2 1 ]", rotate( lOneTwo, 3 ).toString() );
			
			assertEquals( "[ 1 2 3 4 ]", rotate( lOneTwoThreeFour, 0 ).toString() );
			assertEquals( "[ 2 3 4 1 ]", rotate( lOneTwoThreeFour, 1 ).toString() );
			assertEquals( "[ 3 4 1 2 ]", rotate( lOneTwoThreeFour, 2 ).toString() );
			assertEquals( "[ 4 1 2 3 ]", rotate( lOneTwoThreeFour, 3 ).toString() );
			assertEquals( "[ 1 2 3 4 ]", rotate( lOneTwoThreeFour, 4 ).toString() );
			assertEquals( "[ 2 3 4 1 ]", rotate( lOneTwoThreeFour, 5 ).toString() );
			
			assertEquals( "[ 7 8 9 ]", rotate( lSevenEightNine, 0 ).toString() );
			assertEquals( "[ 8 9 7 ]", rotate( lSevenEightNine, 1 ).toString() );
			assertEquals( "[ 9 7 8 ]", rotate( lSevenEightNine, 2 ).toString() );
			assertEquals( "[ 7 8 9 ]", rotate( lSevenEightNine, 3 ).toString() );
			assertEquals( "[ 8 9 7 ]", rotate( lSevenEightNine, 4 ).toString() );
			
		}
		cout << endl;
		
	}
	
	void testChop()
	{
		
		header( "Chop" );
		{
			assertEquals( "[ ]", chop( lEmpty, 0 ).toString() );
			assertEquals( "[ ]", chop( lEmpty, 1 ).toString() );
			
			assertEquals( "[ 1 ]", chop( lOne, 0 ).toString() );
			assertEquals( "[ ]", chop( lOne, 1 ).toString() );
			
			assertEquals( "[ 2 ]", chop( lTwo, 0 ).toString() );
			assertEquals( "[ ]", chop( lTwo, 1 ).toString() );
			
			assertEquals( "[ 1 2 ]", chop( lOneTwo, 0 ).toString() );
			assertEquals( "[ 1 ]", chop( lOneTwo, 1 ).toString() );
			assertEquals( "[ ]", chop( lOneTwo, 2 ).toString() );
			
			assertEquals( "[ 1 2 3 4 ]", chop( lOneTwoThreeFour, 0 ).toString() );
			assertEquals( "[ 1 2 3 ]", chop( lOneTwoThreeFour, 1 ).toString() );
			assertEquals( "[ 1 2 ]", chop( lOneTwoThreeFour, 2 ).toString() );
			assertEquals( "[ 1 ]", chop( lOneTwoThreeFour, 3 ).toString() );
			assertEquals( "[ ]", chop( lOneTwoThreeFour, 4 ).toString() );
			
			assertEquals( "[ 7 8 9 ]", chop( lSevenEightNine, 0 ).toString() );
			assertEquals( "[ 7 8 ]", chop( lSevenEightNine, 1 ).toString() );
			assertEquals( "[ 7 ]", chop( lSevenEightNine, 2 ).toString() );
			assertEquals( "[ ]", chop( lSevenEightNine, 3 ).toString() );
			
		}
		cout << endl;
		
	}
	
	void testInsert()
	{
		
		header( "Insert" );
		{
			assertEquals( "[ 7 8 9 ]", insert( lEmpty, lSevenEightNine, 0 ).toString() );
			assertEquals( "[ 7 8 9 ]", insert( lSevenEightNine, lEmpty, 0 ).toString() );
			assertEquals( "[ 7 8 9 ]", insert( lSevenEightNine, lEmpty, 1 ).toString() );
			assertEquals( "[ 7 8 9 ]", insert( lSevenEightNine, lEmpty, 2 ).toString() );
			assertEquals( "[ 7 8 9 ]", insert( lSevenEightNine, lEmpty, 3 ).toString() );
			
			assertEquals( "[ 7 8 9 1 ]", insert( lOne, lSevenEightNine, 0 ).toString() );
			assertEquals( "[ 1 7 8 9 ]", insert( lOne, lSevenEightNine, 1 ).toString() );
			assertEquals( "[ 1 7 8 9 ]", insert( lSevenEightNine, lOne, 0 ).toString() );
			assertEquals( "[ 7 1 8 9 ]", insert( lSevenEightNine, lOne, 1 ).toString() );
			assertEquals( "[ 7 8 1 9 ]", insert( lSevenEightNine, lOne, 2 ).toString() );
			assertEquals( "[ 7 8 9 1 ]", insert( lSevenEightNine, lOne, 3 ).toString() );
			
			assertEquals( "[ 7 8 9 2 ]", insert( lTwo, lSevenEightNine, 0 ).toString() );
			assertEquals( "[ 2 7 8 9 ]", insert( lTwo, lSevenEightNine, 1 ).toString() );
			assertEquals( "[ 2 7 8 9 ]", insert( lSevenEightNine, lTwo, 0 ).toString() );
			assertEquals( "[ 7 2 8 9 ]", insert( lSevenEightNine, lTwo, 1 ).toString() );
			assertEquals( "[ 7 8 2 9 ]", insert( lSevenEightNine, lTwo, 2 ).toString() );
			assertEquals( "[ 7 8 9 2 ]", insert( lSevenEightNine, lTwo, 3 ).toString() );
			
			assertEquals( "[ 7 8 9 1 2 ]", insert( lOneTwo, lSevenEightNine, 0 ).toString() );
			assertEquals( "[ 1 7 8 9 2 ]", insert( lOneTwo, lSevenEightNine, 1 ).toString() );
			assertEquals( "[ 1 2 7 8 9 ]", insert( lOneTwo, lSevenEightNine, 2 ).toString() );
			assertEquals( "[ 1 2 7 8 9 ]", insert( lSevenEightNine, lOneTwo, 0 ).toString() );
			assertEquals( "[ 7 1 2 8 9 ]", insert( lSevenEightNine, lOneTwo, 1 ).toString() );
			assertEquals( "[ 7 8 1 2 9 ]", insert( lSevenEightNine, lOneTwo, 2 ).toString() );
			assertEquals( "[ 7 8 9 1 2 ]", insert( lSevenEightNine, lOneTwo, 3 ).toString() );
			
			assertEquals( "[ 7 8 9 1 2 3 4 ]", insert( lOneTwoThreeFour, lSevenEightNine, 0 ).toString() );
			assertEquals( "[ 1 7 8 9 2 3 4 ]", insert( lOneTwoThreeFour, lSevenEightNine, 1 ).toString() );
			assertEquals( "[ 1 2 7 8 9 3 4 ]", insert( lOneTwoThreeFour, lSevenEightNine, 2 ).toString() );
			assertEquals( "[ 1 2 3 7 8 9 4 ]", insert( lOneTwoThreeFour, lSevenEightNine, 3 ).toString() );
			assertEquals( "[ 1 2 3 4 7 8 9 ]", insert( lOneTwoThreeFour, lSevenEightNine, 4 ).toString() );
			assertEquals( "[ 1 2 3 4 7 8 9 ]", insert( lSevenEightNine, lOneTwoThreeFour, 0 ).toString() );
			assertEquals( "[ 7 1 2 3 4 8 9 ]", insert( lSevenEightNine, lOneTwoThreeFour, 1 ).toString() );
			assertEquals( "[ 7 8 1 2 3 4 9 ]", insert( lSevenEightNine, lOneTwoThreeFour, 2 ).toString() );
			assertEquals( "[ 7 8 9 1 2 3 4 ]", insert( lSevenEightNine, lOneTwoThreeFour, 3 ).toString() );
			
			assertEquals( "[ 7 8 9 7 8 9 ]", insert( lSevenEightNine, lSevenEightNine, 0 ).toString() );
			assertEquals( "[ 7 7 8 9 8 9 ]", insert( lSevenEightNine, lSevenEightNine, 1 ).toString() );
			assertEquals( "[ 7 8 7 8 9 9 ]", insert( lSevenEightNine, lSevenEightNine, 2 ).toString() );
			assertEquals( "[ 7 8 9 7 8 9 ]", insert( lSevenEightNine, lSevenEightNine, 3 ).toString() );
		}
		cout << endl;
		
	}
	
}
