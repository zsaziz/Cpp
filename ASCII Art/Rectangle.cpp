/* HW9
Zain Aziz
COMP208
4/15/2015

Making the class Rectangle which is a derived class of Shape.
*/

#include "Rectangle.h"
namespace comp201
{
	Rectangle::Rectangle(int x, int y, int halfWidth, int halfHeight) : Shape(x, y), halfWidth(halfWidth), halfHeight(halfHeight){} //initializes the shape with the x
																																	//and y coordinate
	int Rectangle::getHalfWidth() const { return halfWidth; } //returns the halfWidth

	int Rectangle::getHalfHeight() const { return halfHeight; } //returns the halfHeight

	bool Rectangle::coversPosition(int x, int y) const
	{
		if ((x <= getX() + getHalfWidth() && x >= getX() - getHalfWidth()) && (y <= getY() + getHalfHeight() && y >= getY() - getHalfHeight())) //returns true if the given
			return true;																														//coordinate is on the current shape
		return false;
	}
}