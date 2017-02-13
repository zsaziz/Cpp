/* HW9
Zain Aziz
COMP208
4/15/2015

Making the class Point which is a derived class of Shape.
*/

#include "Point.h"
namespace comp201
{
	Point::Point(int x, int y) :Shape(x, y){} //initializes the point with x and y coordinate

	bool Point::coversPosition(int x, int y) const
	{
		if (getX() == x && getY() == y) //returns true if the given coordinate is on the current shape
		{
			return true;
		}
		return false;
	}
}