
#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "Shape.h"

namespace comp201
{
	
	// A shape representing a rectangle
	class Rectangle: public Shape
	{
	public:
		
		// Initializes the rectangle centered at position (x,y)
		// with provided half-width and half-height values
		Rectangle(int x, int y, int halfWidth, int halfHeight);
		
		// Returns the half-width
		//
		// Returns: half-width
		int getHalfWidth() const;
		
		// Returns the half-height
		//
		// Returns: half-height
		int getHalfHeight() const;
		
		// Determines if the provided (x,y) position
		// is within this rectangle
		//
		// Returns: true if the position is within this rectangle
		virtual bool coversPosition(int x, int y) const;
		
	private:
		const int halfWidth;
		const int halfHeight;
	};
	
}

#endif
