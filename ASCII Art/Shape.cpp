/* HW9
Zain Aziz
COMP208
4/15/2015

Making the class Shape.
*/

#include "Shape.h"
namespace comp201
{
	Shape::Shape(int x, int y) : x(x), y(y){} //initializes the x and y coordinates

	Shape::~Shape(){}

	int Shape::getX() const  //returns the x coordinate
	{
		return x;
	}
	int Shape::getY() const //returns the y coordinate
	{
		return y;
	}
}