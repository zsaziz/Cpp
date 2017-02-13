
#ifndef __ELLIPSE_H
#define __ELLIPSE_H

#include "Shape.h"

namespace comp201
{
	
	// A shape representing an ellipse
	class Ellipse: public Shape
	{
	public:
		
		// Initializes the ellipse at position (x,y)
		// with x-radius and y-radius provided
		Ellipse(int x, int y, int xRadius, int yRadius);
		
		// Gets the x-radius
		//
		// Returns: x-radius
		int getXRadius() const;
		
		// Gets the y-radius
		//
		// Returns: y-radius
		int getYRadius() const;
		
		// Determines if the provided point is within
		// the area of the ellipse
		//
		// Returns: true if provided position (x,y)
		//          is within this ellipse
		virtual bool coversPosition(int x, int y) const;
		
	private:
		int xRadius;
		int yRadius;
	};
	
}

#endif
