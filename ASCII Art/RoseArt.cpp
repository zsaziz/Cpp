#include "RoseArt.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Point.h"

namespace comp201
{
	
	RoseArt::RoseArt():
	ASCIIArt( 20, 40 )
	{
		ShapeCharVector v;
		
		v.add( new Rectangle( 15, 10, 12, 8 ), '|' );
		v.add( new Circle( 15, 10, 7 ), ' ' );
		
		const int size = 10;
		const char rose[] = { '@', '}', '-', ',', '-', '`', '-', '-', '-', '-' };
		for ( int i=0; i<size; i++ )
			v.add( new Point( 10+i, 10 ), rose[i] );
		
		drawShapes( v );
	}
	
}
