#include <iostream>
#include <cstdlib>
#include "XArt.h"
#include "TargetArt.h"
#include "WITArt.h"
#include "RoseArt.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace comp201;
using namespace std;

template <typename T>
void assertEquals(T expected, T test)
{
	if ( expected != test )
	{
		cout << expected << " != " << test << endl;
		exit(1);
	}
	
	cout << "Passed!" << endl;
}

void header(const char* title)
{
	cout << "####################" << endl;
	cout << "## " << title << endl;
	cout << "####################" << endl;
}

//

void _testCoverage(const char* ex[], int width, int height, const Shape& s)
{
	for ( int i=0; i<height; i++ )
	{
		for ( int j=0; j<width; j++ )
		{
			assertEquals( ex[i][j] == '*', s.coversPosition( j, height-i-1 ) );
		}
	}
}

void testPoint()
{
	header( "Point1" );
	{
		Point sP1( 0, 1 );
		assertEquals( 0, sP1.getX() );
		assertEquals( 1, sP1.getY() );
	}
	cout << endl;
	
	header( "Point2" );
	{
		Point sP2( 3, 4 );
		
		const int width = 8;
		const int height = 8;
		const char* ex[] = {
			"--------",
			"--------",
			"--------",
			"---*----",
			"--------",
			"--------",
			"--------",
			"--------"
		};
		
		_testCoverage( ex, width, height, sP2 );
	}
	cout << endl;
}

void testCircle()
{
	header( "Circle1" );
	{
		Circle sC1( 0, 1, 2 );
		assertEquals( 0, sC1.getX() );
		assertEquals( 1, sC1.getY() );
		assertEquals( 2, sC1.getRadius() );
		assertEquals( 2, sC1.getXRadius() );
		assertEquals( 2, sC1.getYRadius() );
	}
	cout << endl;
	
	header( "Circle2" );
	{
		Circle sC2( 3, 4, 2 );
		
		const int width = 8;
		const int height = 8;
		const char* ex[] = {
			"--------",
			"---*----",
			"--***---",
			"-*****--",
			"--***---",
			"---*----",
			"--------",
			"--------"
		};
		
		_testCoverage( ex, width, height, sC2 );
	}
	cout << endl;
}

void testRectangle()
{
	header( "Rectangle1" );
	{
		Rectangle sR1( 0, 1, 2, 3 );
		assertEquals( 0, sR1.getX() );
		assertEquals( 1, sR1.getY() );
		assertEquals( 2, sR1.getHalfWidth() );
		assertEquals( 3, sR1.getHalfHeight() );
	}
	cout << endl;
	
	header( "Rectangle2" );
	{
		Rectangle sR2( 4, 3, 1, 2 );
		
		const int width = 8;
		const int height = 8;
		const char* ex[] = {
			"--------",
			"--------",
			"---***--",
			"---***--",
			"---***--",
			"---***--",
			"---***--",
			"--------"
		};
		
		_testCoverage( ex, width, height, sR2 );
	}
	cout << endl;
}

void testX()
{
	const int size = 5;
	const char* ex[] = {
		"X   X",
		" X X ",
		"  X  ",
		" X X ",
		"X   X"
	};
	
	string expected;
	for ( int i=0; i<size; i++ )
	{
		expected += ex[i];
		expected += "\n";
	}
	
	header( "X" );
	assertEquals( expected, XArt( size ).asString() );
	cout << endl;
}

//

void pictures()
{
	cout << XArt( 25 ) << endl;
	cout << TargetArt() << endl;
	cout << WITArt() << endl;
	cout << RoseArt() << endl;
}

int main(int argc, const char* argv[])
{
	if ( argc > 1 )
	{
		pictures();
	}
	else
	{
		testPoint();
		testCircle();
		testRectangle();
		testX();
	}
	
	return 0;
}
