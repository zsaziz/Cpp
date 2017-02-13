/* HW9
Zain Aziz
COMP208
4/15/2015

Making the class Circle which is a derived class of Ellipse.
*/

#include "Circle.h"
namespace comp201
{
	Circle::Circle(int x, int y, int radius) :Ellipse(x, y, radius, radius){} //initializes the ellipse with the measurments of a circle

	int Circle::getRadius()
	{
		return getYRadius(); //returns the radius of the circle
	}
}