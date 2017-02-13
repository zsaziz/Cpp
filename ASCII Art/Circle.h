
#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "Ellipse.h"

namespace comp201
{
	
	// A shape representing a circle
	class Circle: public Ellipse
	{
	public:
		
		// Initializes the circle
		// at the provided (x,y) position
		// and radius
		Circle(int x, int y, int radius);
		
		// Gets the radius
		//
		// Returns: radius
		int getRadius();
	};
	
}

#endif
