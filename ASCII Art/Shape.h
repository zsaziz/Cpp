
#ifndef __SHAPE_H
#define __SHAPE_H

namespace comp201
{

	// An abstract class representing a shape
	class Shape
	{
	public:
		
		// Initializes the shape at an (x,y) location
		Shape(int x, int y);
		
		// Deallocates the shape
		// (provided for subclasses, this class's
		// implementation does nothing)
		virtual ~Shape();
		
		// Gets the x position
		//
		// Returns: x coordinate of the shape
		int getX() const;
		
		// Gets the y position
		//
		// Returns: y coordinate of the shape
		int getY() const;
		
		// Determines if the shape includes the
		// provided (x,y) position inside its area
		//
		// Returns: true if the shape includes the provided point
		virtual bool coversPosition(int x, int y) const = 0;
		
	private:
		const int x;
		const int y;
	};
	
}

#endif
