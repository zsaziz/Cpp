#include "WITArt.h"
#include "Rectangle.h"

namespace comp201
{
	
	WITArt::WITArt():
	ASCIIArt( 7, 40 )
	{
		const char pos = '*';
		
		ShapeCharVector v;
		v.add( new Rectangle( 7, 1, 7, 1 ), pos );
		v.add( new Rectangle( 1, 3, 1, 3 ), pos );
		v.add( new Rectangle( 7, 3, 1, 1 ), pos );
		v.add( new Rectangle( 13, 3, 1, 3 ), pos );
		
		v.add( new Rectangle( 21, 1, 1, 7 ), pos );
		
		v.add( new Rectangle( 32, 1, 1, 7 ), pos );
		v.add( new Rectangle( 32, 5, 4, 1 ), pos );
		
		drawShapes( v );
	}
	
}
