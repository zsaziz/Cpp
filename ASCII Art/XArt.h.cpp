/* HW9 
   Zain Aziz
   COMP208
   4/15/2015
   
   Making the class XArt which is a derived class of ASCIIArt.
   Use the ShapeCharVector class to draw the shape.
*/

#include "XArt.h"
#include "Point.h"
namespace comp201
{
	XArt::XArt(int sideLength) : ASCIIArt(sideLength, sideLength)
	{
		ShapeCharVector v;
		for (int i = 0; i < sideLength; i++)
		{
			v.add(new Point(i, i), 'X'); //makes an 'X' on all the points with the same x and y coordinate until the size
		}
		for (int i = 0; i < sideLength; i++)
		{
			v.add(new Point(sideLength - 1 - i, i), 'X'); //makes an 'X' on all points with decreasing x from the size till 0 and increasing y until the size
		}
		
		drawShapes(v);
	}

}