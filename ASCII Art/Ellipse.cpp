#include "Ellipse.h"

namespace comp201
{
	
	Ellipse::Ellipse(int x, int y, int xRadius, int yRadius):
	Shape( x, y ), xRadius( xRadius ), yRadius( yRadius ) {}
	
	int Ellipse::getXRadius() const
	{
		return xRadius;
	}
	
	int Ellipse::getYRadius() const
	{
		return yRadius;
	}
	
	bool Ellipse::coversPosition(int x, int y) const
	{
		double xDiff = ( x - getX() );
		double yDiff = ( y - getY() );
		
		double normalizedXDiffSquared = ( xDiff / xRadius )*( xDiff / xRadius );
		double normalizedYDiffSquared = ( yDiff / yRadius )*( yDiff / yRadius );
		
		return ( ( normalizedXDiffSquared + normalizedYDiffSquared ) <= 1 );
	}
	
}
