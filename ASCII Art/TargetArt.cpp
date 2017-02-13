#include "TargetArt.h"
#include "Circle.h"

namespace comp201
{
	
	TargetArt::TargetArt():
	ASCIIArt( 25, 25 )
	{
		const char pos = '+';
		const char neg = ' ';
		
		ShapeCharVector v;
		v.add( new Circle( 12, 12, 13 ), pos );
		v.add( new Circle( 12, 12, 10 ), neg );
		v.add( new Circle( 12, 12, 7 ), pos );
		v.add( new Circle( 12, 12, 4 ), neg );
		v.add( new Circle( 12, 12, 1 ), pos );
		
		drawShapes( v );
	}
	
}