
#ifndef __POINT_H
#define __POINT_H

#include "Shape.h"

namespace comp201
{
	// A shape representing a single point
	class Point: public Shape
	{
	public:
		
		// Initializes the point location
		Point(int x, int y);
		
	protected:
		
		// Determines if the provided point
		// is the same as this point's location
		//
		// Returns: true if provided (x,y) are the same
		//          as this shape's (x,y)
		virtual bool coversPosition(int x, int y) const;
	};
}

#endif
