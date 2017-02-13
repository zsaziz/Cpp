/*********************************************************************
*	HW 5
*	Zain Aziz
*	COMP208-03
*	03/09/2015
**********************************************************************
*	Problem
*
*	There are 3 classes that are being used: Point2D, Rectangle and 
*	Triangle. There a bunch of test cases to test these.
*
***********************************************************************
*	Analysis
*
*	Inputs:  Coordinates for 3 points if there is a command line argument
*
*	Outputs: Many test cases.
*
***********************************************************************
*	Pseudocode
*
*	There are 3 classes that are being used. First one is Point2D, which
*	has a many different functions, such as functions that can set the
*	coordinates and outputting the coordinates as string. The second one
*	is Rectangle, which uses the Point2D class to make a rectangle using
*	two points. It also has many functions such as, area and setting the
*	coordinates. The third one is Triangle, which also uses the Point2D
*	class and Rectangle class in one function. It uses 3 points to make
*	a triangle and has many functiions such as area and to check if it
*	a right angle triangle or not. The main carries out test cases if there
*	are no command line arguments, otherwise it asks the user for 3 points
*	from which it makes a triangle.
*
**********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

// Needed for utility functions before class definitions
class Point2D;

///////////////////////////////////////////////////////////////////////////
// Utility functions
///////////////////////////////////////////////////////////////////////////

// Converts an int to a string
//
// Returns: x as a string
string to_string2(int x);

// Computes the maximum of two integers
//
// Returns: maximum value of n1/n2
int max(int n1, int n2);

// Computes the minimum of two integers
//
// Returns: minimum value of n1/n2
int min(int n1, int n2);

// Detects if two numbers the same
// within some tolerance
//
// Returns: true if | d1 - d2 | <= tolerance
bool sameByTolerance(double d1, double d2, double tolerance);

// Computes the angle (in degrees) between the vectors ab and ac
//
// Returns: the angle (in degrees) between ab and ac
double angle(const Point2D& a, const Point2D& b, const Point2D& c);

///////////////////////////////////////////////////////////////////////////
// Testing functions
///////////////////////////////////////////////////////////////////////////

// Tests that test is within thresh of expected
//
// Postconditions: if |expected - test|>thresh, exits
void assertEquals(double expected, double test, double thresh);

// Tests that test=expected exactly
//
// Postconditions: if test!=expected, exits
void assertEquals(int expected, int test);

// Tests that test is true
//
// Postconditions: if !test, exits
void assertTrue(bool test);

// Runs a set of tests on the Point2D class
void testPoint2D();

// Runs a set of tests on the Rectangle class
void testRectangle();

// Runs a set of tests on the Triangle class
void testTriangle();

///////////////////////////////////////////////////////////////////////////
// Class definitions
///////////////////////////////////////////////////////////////////////////

// A class to represent a point in two dimensions
class Point2D
{
public:

	// Initializes the point
	//
	// Postconditions: point is at (0,0)
	Point2D();

	// Initializes the point
	//
	// Postconditions: point is at (initialX, initialY)
	Point2D(int initialX, int initialY);

	// Get the x-coordinate
	//
	// Returns: value of the x-coordinate
	int getX() const;

	// Get the y-coordinate
	//
	// Returns: value of the y-coordinate
	int getY() const;

	// Returns the Euclidean distance from this point and other
	//
	// Preconditions: other is initialized
	// Returns: Euclidean distance to other
	double distance(const Point2D& other) const;

	// Changes the x-coordinate
	//
	// Postconditions: x-coordinate is newX
	void setX(int newX);

	// Changes the y-coordinate
	//
	// Postconditions: y-coordinate is newX
	void setY(int newY);

	// Changes both coordinates
	//
	// Postconditions: point is at (newX, newY)
	void set(int newX, int newY);

	// Puts this point at the origin
	//
	// Postconditions: point is at (0,0)
	void setOrigin();

	// Sets this point at the same location as p
	//
	// Postconditions: this is at (p.x, p.y)
	void copyPoint(const Point2D& p);

	// Prompts the user to supply this point's
	// coordinates from the keyboard
	//
	// Postconditions: this is at the location entered by the user
	void readInput();

	// Returns this point's coordinates as a string
	//
	// Return: pattern = (x, y)
	string toString() const;

	// Compares two points
	//
	// Preconditions: p1 and p2 are initialized
	// Returns: true if p1 and p2 are at the same location
	friend bool operator ==(const Point2D& p1, const Point2D& p2);

	// Compares two points
	//
	// Preconditions: p1 and p2 are initialized
	// Returns: true if p1 and p2 are NOT at the same location
	friend bool operator !=(const Point2D& p1, const Point2D& p2);

	// Outputs a point's string representation to an output stream
	//
	// Postconditions: p's string representation is sent to outs
	// Returns: outs
	friend ostream& operator <<(ostream& outs, const Point2D& p);
private:
	double x, y;
};

// A class to represent a rectangle
class Rectangle
{
public:

	// Initializes the rectangle
	//
	// Postconditions: this is the square (0,0) -> (1,1)
	Rectangle();

	// Sets the rectangle via two points
	// Valid points are those that lead to non-zero area
	// Note: these points need not be lower left/upper right
	//
	// Postconditions: if valid corners, rectangle location is
	//                 defined by p1, p2
	// Returns: true if points were valid corners
	bool setCorners(const Point2D& p1, const Point2D& p2);

	// Gets the area of the rectangle
	//
	// Returns: rectangle area
	int area() const;

	// Gets the lower-left corner of the rectangle
	//
	// Returns: lower-left corner of the rectangle
	Point2D getLeftLowerPoint() const;

	// Gets the upper-right corner of the rectangle
	//
	// Returns: upper-right corner of the rectangle
	Point2D getUpperRightPoint() const;

	// Moves this rectangle along the x-axis
	//
	// Postconditions: rectangle is moved distance units along
	//                 the x-axis (negative means left)
	void moveHorizontal(int distance);

	// Moves this rectangle along the y-axis
	//
	// Postconditions: rectangle is moved distance units along
	//                 the y-axis (negative means down)
	void moveVertical(int distance);
private:
	double x1, y1, x2, y2;
};

// A class to represent a triangle
class Triangle
{
public:

	// Initializes the triangle
	//
	// Postconditions: this is the right, isosceles triangle with
	//                 vertices (0, 0), (0, 1), (1, 0)
	Triangle();

	// Sets the vertices of the triangle
	// Valid points satisfy the triangle inequality
	//
	// Postconditions: if valid vertices, vertices are p1, p2, p3
	// Return: true if the points were valid
	bool setPoints(const Point2D& p1, const Point2D& p2, const Point2D& p3);

	// Gets the triangle area
	//
	// Return: triangle area
	double area() const;

	// Determines if this is a right triangle
	//
	// Returns: true if any of the triangle's angles are within
	//          tolerance degrees of 90
	bool isRight(double tolerance) const;

	// Determines if this is an isosceles triangle
	//
	// Returns: true if two of the triangle's angles are equal
	//          within tolerance degrees
	bool isIsosceles(double tolerance) const;

	Rectangle boundingBox() const;
private:
	double x1, x2, x3, y1, y2, y3;
};

///////////////////////////////////////////////////////////////////////////
// Main
///////////////////////////////////////////////////////////////////////////

// If no arguments given, runs tests for Point2D, Rectangle, and Triangle
// ELSE
// A program that asks the user for three triangle vertices
// using the readInput method of Point2D. Then attempts to
// create a triangle with those points, providing an error
// if they are not legal, otherwise outputting the area of
// the triangle and if it is right & isosceles.
// It finally computes the triangle bounding box, outputting
// the lower left & upper right corners as well as the area.
//
// Example runs:
//
// > hw5 foo
//
// == Vertex 1 ==
// Enter x: 0
// Enter y: 0
//
// == Vertex 2 ==
// Enter x: 0
// Enter y: 1
//
// == Vertex 3 ==
// Enter x: 0
// Enter y: 2
//
// Error setting triangle vertices!
//
// > hw5 foo
//
// == Vertex 1 ==
// Enter x: 0
// Enter y: 0
//
// == Vertex 2 ==
// Enter x: 0
// Enter y: 1
//
// == Vertex 3 ==
// Enter x: 2
// Enter y: 0
//
// == Triangle ==
// Area: 1
// Right: true
// Isosceles: false
//
// == Bounding Box ==
// Lower left corner: (0, 0)
// Upper right corner: (2, 1)
// Area: 2
//
int main(int argc, char *argv[])
{

	if (argc == 1)
	{
		testPoint2D();
		testRectangle();
		testTriangle();
	}
	else
	{
		Point2D p1, p2, p3;
		Triangle t;
		cout << "Enter your coordinates for the first point of a triangle\n";	 //
		p1.readInput();															 //
		cout << "Enter your coordinates for the second point of a triangle\n";	 //asks the user for 3 points using the readInput function
		p2.readInput();															 //
		cout << "Enter your coordinates for the third point of a triangle\n";	 //
		p3.readInput();															 //
		if (t.setPoints(p1, p2, p3) == false)  //checks if the points are valid
		{
			cout << "Error setting triangle vertices!" << endl; //sends an error message if they are invalid
			return 0;
		}
		cout << "== Triangle ==" << endl;		 //
		cout << "Area: " << t.area() << endl;	 //
		if (t.isRight(1) == true)				 //
			cout << "Right: true" << endl;		 //
		else									 // outputs the area of the triangle, whether it is a right angle triangle or not
			cout << "Right: false" << endl;		 // and whether it is an isosceles triangle or not
		if (t.isIsosceles(1) == true)			 //
			cout << "Isosceles: true" << endl; 	 //
		else									 //
			cout << "Isosceles: false" << endl;	 //
		cout << "== Bounding Box ==" << endl;														 //
		cout << "Lower left corner: " << t.boundingBox().getLeftLowerPoint().toString() << endl;	 // outputs the area of the bounding box, and outputs the
		cout << "Upper right corner: " << t.boundingBox().getUpperRightPoint().toString() << endl;	 // lower left corner and upper right corner
		cout << "Area: " << t.boundingBox().area() << endl;											 //
	}

	return 0;

}

///////////////////////////////////////////////////////////////////////////
// Class member/friend function definitions
///////////////////////////////////////////////////////////////////////////

Point2D::Point2D()
{
	x = y = 0;  //sets the point to (0,0)
}

Point2D::Point2D(int initialX, int initialY)
{
	x = initialX; // sets the x-coordinate to the given value
	y = initialY; //sets the y-coordinate to the given value
}

int Point2D::getX() const
{
	return x; //returns the value of x-cooridnate
}

int Point2D::getY() const
{
	return y; //returns the value of y-coordinate
}

double Point2D::distance(const Point2D& other) const
{
	double x;
	x = pow((other.x - this->x), 2) + pow((other.y - this->y), 2);
	x = sqrt(x);  //calculates the distance and returns it
	return x;
}

void Point2D::setX(int newX)
{
	x = newX; //sets the x-coordinate
}

void Point2D::setY(int newY)
{
	y = newY; //sets the y-coordinate
}

void Point2D::set(int newX, int newY)
{
	x = newX; // sets the x-coordinate to the given value
	y = newY; //sets the y-coordinate to the given value
}

void Point2D::setOrigin()
{
	x = y = 0;  //sets the point to (0,0)
}

void Point2D::copyPoint(const Point2D& p)
{
	x = p.x;  //copies the x-coordinate to a new point
	y = p.y;  //copies the y-coordinate to a new point
}

void Point2D::readInput()
{
	double x, y;
	cout << "Enter the x-coordinate: ";
	cin >> x;
	cout << "Enter the y-coordinate: ";
	cin >> y;
	this->x = x;  //asks the user for the coordinates and sets it to the x and y coordinates
	this->y = y;
}

string Point2D::toString() const
{
	string x = to_string2(this->x);
	string y = to_string2(this->y);
	string ans = "(" + x + ", " + y + ")";  //sets the coordinates in a string to a pattern of (x, y) and returns that
	return ans;
}

bool operator ==(const Point2D& p1, const Point2D& p2)
{
	if ((p1.x == p2.x) && (p1.y == p2.y))  //compares two points and if they are the same then returns true
		return true;
	return false;
}

bool operator !=(const Point2D& p1, const Point2D& p2)
{
	if ((p1.x != p2.x) || (p1.y != p2.y))  //compares two points and if they are not the same, returns true
		return true;
	return false;
}

ostream& operator <<(ostream& outs, const Point2D& p)
{
	outs << "(" << p.x << ", " << p.y << ")";  //outputs the coordinates
	return outs;
}

Rectangle::Rectangle()
{
	x1 = y1 = 0;  //sets the first point to (0,0)
	x2 = y2 = 1;  //sets the second point to (1,1)
}

bool Rectangle::setCorners(const Point2D& p1, const Point2D& p2)
{
	double p1x = p1.getX();
	double p2x = p2.getX();
	double length = p1x - p2x;  //calculates the length
	if (length < 0)
		length = -(length);
	double width = p1.getY() - p2.getY();  //calculates the width
	if (width < 0)
		width = -(width);
	if ((width*length) != 0)  //checks if the area is not zero
	{
		x1 = p1.getX(); y1 = p1.getY(); //sets the first x and y coordinates to that of the first point
		x2 = p2.getX(); y2 = p2.getY(); //sets the second x and y coordinates to that of the second point
		return true;
	}
	else
		return false;
}

int Rectangle::area() const
{
	double length = x1 - x2;
	if (length < 0)
		length = -(length);  //checks if the length is negative. If it is, it makes it positive
	double width = y1 - y2;
	if (width < 0)
		width = -(width);  //checks if the width is negative. If it is, it makes it positive
	double area = length * width;
	return area;  //calculates and returns the area
}

Point2D Rectangle::getLeftLowerPoint() const
{
	Point2D p(x1, y1);
	if (p.getX() > x2)
		p.setX(x2);
	if (p.getY() > y2)
		p.setY(y2);
	return p;  //returns the lower left point of the rectangle
}

Point2D Rectangle::getUpperRightPoint() const
{
	Point2D p(x1, y1);
	if (p.getX() < x2)
		p.setX(x2);
	if (p.getY() < y2)
		p.setY(y2);
	return p;  //returns the upper right point of the rectangle
}

void Rectangle::moveHorizontal(int distance)
{
	x1 = x1 + distance;  //moves both x coordinates by the given distance
	x2 = x2 + distance;
}

void Rectangle::moveVertical(int distance)
{
	y1 = y1 + distance;  //moves both y coordinates by the given distance
	y2 = y2 + distance;
}

Triangle::Triangle()
{
	x1 = y1 = 0; //sets the first point to (0,0)
	x2 = 0; y2 = 1; //sets the second point to (0,1)
	x3 = 1; y3 = 0; //sets the third point to (1,0)
}

bool Triangle::setPoints(const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	double a = p1.distance(p2);   //
	double b = p1.distance(p3);	  // sets the distance of the sides of the triangle to three variables
	double c = p2.distance(p3);	  //
	if (a + b > c && a + c > b && b + c > a)  //checks to see if the points meet the triangle inequality criteria
	{
		x1 = p1.getX(); y1 = p1.getY();  //
		x2 = p2.getX(); y2 = p2.getY();	 // sets the points to the ones given
		x3 = p3.getX(); y3 = p3.getY();	 //
		return true;
	}
	return false;
}

double Triangle::area() const
{
	double area;
	area = ((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))) / 2.0;  //calculates the area
	area = abs(area); //makes it positive if it is negative
	return area;
}

bool Triangle::isRight(double tolerance) const
{
	Point2D a(x1, y1);
	Point2D b(x2, y2);
	Point2D c(x3, y3);
	double abtobc = angle(a, b, c);  //
	double bctoca = angle(b, c, a);	 // sets the angles between the 3 points to 3 different variables
	double catoab = angle(c, a, b);	 //
	if (sameByTolerance(abtobc, 90, tolerance) == true)	  //
		return true;									  //
	if (sameByTolerance(bctoca, 90, tolerance) == true)	  //  if one of the angles difference from 90 is within or equal to the tolerance, it returns true
		return true;									  //
	if (sameByTolerance(catoab, 90, tolerance) == true)	  //
		return true;									  //
	return false;
}

bool Triangle::isIsosceles(double tolerance) const
{
	Point2D a(x1, y1);
	Point2D b(x2, y2);
	Point2D c(x3, y3);
	double abtobc = angle(a, b, c); //
	double bctoca = angle(b, c, a);	// sets the angles between the 3 points to 3 different variables
	double catoab = angle(c, a, b);	//
	if (sameByTolerance(abtobc, bctoca, tolerance) == true) //
		return true;										//
	if (sameByTolerance(abtobc, catoab, tolerance) == true)	//  if one of the angles difference from another angle is within or equal to the tolerance, it returns true
		return true;										//
	if (sameByTolerance(bctoca, catoab, tolerance) == true)	//
		return true;										//
	return false;
}

Rectangle Triangle::boundingBox() const
{
	Rectangle r;
	double minx = x1; //
	if (x2 < minx)	  //
		minx = x2;	  // checks to find the minimum x-coordinate
	if (x3 < minx)	  //
		minx = x3;	  //
	double miny = y1; //
	if (y2 < miny)	  //
		miny = y2;	  // checks to find the minimum y-coordinate
	if (y3 < miny)	  //
		miny = y3;	  //
	Point2D p1(minx, miny); //makes a new point with the minimum x and y coordinates
	double maxx = x1; //
	if (x2 > maxx)	  //
		maxx = x2;	  // checks to find the maximum x-coordinate
	if (x3 > maxx)	  //
		maxx = x3;	  //
	double maxy = y1; //
	if (y2 > maxy)	  //
		maxy = y2;	  // checks to find the maximum y-coordinate
	if (y3 > maxy)	  //
		maxy = y3;	  //
	Point2D p2(maxx, maxy); //makes a new point with the maximum x and y coordinates
	r.setCorners(p1, p2);  //sets the corners of the rectangle r to the max and min points
	return r;
}

///////////////////////////////////////////////////////////////////////////
// Utility function definitions
///////////////////////////////////////////////////////////////////////////

string to_string2(int x)
{
	ostringstream o;
	string ret;

	o << x;
	ret.assign(o.str());

	return ret;
}

int max(int n1, int n2)
{
	return std::max(n1, n2);
}

int min(int n1, int n2)
{
	return std::min(n1, n2);
}

bool sameByTolerance(double d1, double d2, double tolerance)
{
	double diff = (d1 - d2);
	if (diff < 0) {
		diff *= -1;
	}

	return (diff <= tolerance);
}

double angle(const Point2D& a, const Point2D& b, const Point2D& c)
{
	int abx = (b.getX() - a.getX());
	int aby = (b.getY() - a.getY());

	int acx = (c.getX() - a.getX());
	int acy = (c.getY() - a.getY());

	return (180.0 / 3.14159265359) * acos(
		(abx*acx + aby*acy) /
		(sqrt(abx*abx + aby*aby) * sqrt(acx*acx + acy*acy))
		);
}

///////////////////////////////////////////////////////////////////////////
// Testing function definitions
///////////////////////////////////////////////////////////////////////////

void assertEquals(int expected, int test)
{
	if (expected != test)
	{
		cout << expected << " != " << test << endl;
		exit(1);
	}

	cout << "Passed!" << endl;
}

void assertEquals(double expected, double test, double thresh)
{
	if (!sameByTolerance(expected, test, thresh))
	{
		cout << expected << " != " << test << endl;
		exit(1);
	}

	cout << "Passed!" << endl;
}

void assertTrue(bool test)
{
	if (!test)
	{
		cout << "Not true" << endl;
		exit(1);
	}

	cout << "Passed!" << endl;
}

void testPoint2D()
{

	cout << endl;
	cout << "##################" << endl;
	cout << "## Point2D" << endl;
	cout << "##################" << endl << endl;

	// set-get
	{
		Point2D p;

		cout << "== set-get-1 ==" << endl;
		p.setOrigin();
		assertEquals(0, p.getX());
		assertEquals(0, p.getY());
		assertTrue(p.toString() == "(0, 0)");

		cout << "== set-get-2 ==" << endl;
		p.setX(1);
		assertEquals(1, p.getX());
		assertTrue(p.toString() == "(1, 0)");

		cout << "== set-get-3 ==" << endl;
		p.setY(2);
		assertEquals(2, p.getY());
		assertTrue(p.toString() == "(1, 2)");

		cout << "== set-get-4 ==" << endl;
		p.set(3, 4);
		assertEquals(3, p.getX());
		assertEquals(4, p.getY());
		assertTrue(p.toString() == "(3, 4)");
	}

	// equals
	{
		Point2D p1;
		Point2D p2;

		cout << "== equals-1 ==" << endl;
		p1.setX(1);
		p1.setY(2);
		p2.set(1, 2);
		assertTrue(p1 == p1);
		assertTrue(p2 == p2);
		assertTrue(p1 == p2);
		assertTrue(p2 == p1);
		assertTrue(!(&p1 == &p2));

		cout << "== equals-2 ==" << endl;
		p1.setOrigin();
		assertTrue(p1 != p2);
		assertTrue(p2 != p1);

		cout << "== equals-3 ==" << endl;
		p2.setOrigin();
		assertTrue(p1 == p2);
		assertTrue(p2 == p1);
	}

	// copy
	{
		Point2D p1;
		Point2D p2;

		cout << "== copy-1 ==" << endl;
		p1.set(1, 1);
		p2.copyPoint(p1);
		assertTrue(p1 == p2);
		assertTrue(p2 == p1);

		cout << "== copy-2 ==" << endl;
		p1.set(2, 2);
		assertTrue(p1 != p2);
		assertTrue(p2 != p1);
	}

	// distance
	{
		Point2D p1;
		Point2D p2;

		cout << "== distance-1 ==" << endl;
		p1.setOrigin();
		p2.set(1, 1);
		assertEquals(0, p1.distance(p1), 0.0001);
		assertEquals(0, p2.distance(p2), 0.0001);
		assertEquals(sqrt(2), p1.distance(p2), 0.0001);
		assertEquals(sqrt(2), p2.distance(p1), 0.0001);

		cout << "== distance-2 ==" << endl;
		p2.set(1, 0);
		assertEquals(1, p1.distance(p2), 0.0001);
		assertEquals(1, p2.distance(p1), 0.0001);

		cout << "== distance-3 ==" << endl;
		p2.set(0, 1);
		assertEquals(1, p1.distance(p2), 0.0001);
		assertEquals(1, p2.distance(p1), 0.0001);

		cout << "== distance-4 ==" << endl;
		p2.set(0, -1);
		assertEquals(1, p1.distance(p2), 0.0001);
		assertEquals(1, p2.distance(p1), 0.0001);

		cout << "== distance-5 ==" << endl;
		p2.set(-1, 0);
		assertEquals(1, p1.distance(p2), 0.0001);
		assertEquals(1, p2.distance(p1), 0.0001);
	}

	cout << endl;

}

void testRectangle()
{

	cout << endl;
	cout << "##################" << endl;
	cout << "## Rectangle" << endl;
	cout << "##################" << endl << endl;

	// bad
	{
		Point2D p1;
		Point2D p2;
		Rectangle r;

		cout << "== bad-1 ==" << endl;
		p1.setOrigin();
		p2.setOrigin();
		assertTrue(!r.setCorners(p1, p2));
		assertTrue(!r.setCorners(p2, p1));

		cout << "== bad-2 ==" << endl;
		p1.set(1, 0);
		assertTrue(!r.setCorners(p1, p2));
		assertTrue(!r.setCorners(p2, p1));

		cout << "== bad-3 ==" << endl;
		p1.set(0, 1);
		assertTrue(!r.setCorners(p1, p2));
		assertTrue(!r.setCorners(p2, p1));
	}

	// good
	{
		Point2D p1;
		Point2D p2;
		Rectangle r;

		cout << "== good-1 ==" << endl;
		p1.setOrigin();
		p2.set(2, 3);
		assertTrue(r.setCorners(p1, p2));
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(0, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(2, 3)");

		cout << "== good-2 ==" << endl;
		p1.set(0, 0);
		p2.set(0, 0);
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(0, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(2, 3)");

		cout << "== good-3 ==" << endl;
		r.moveHorizontal(0);
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(0, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(2, 3)");

		cout << "== good-4 ==" << endl;
		r.moveVertical(0);
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(0, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(2, 3)");

		cout << "== good-5 ==" << endl;
		r.moveHorizontal(1);
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(1, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(3, 3)");

		cout << "== good-6 ==" << endl;
		r.moveVertical(-1);
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(1, -1)");
		assertTrue(r.getUpperRightPoint().toString() == "(3, 2)");

		cout << "== good-7 ==" << endl;
		assertTrue(p1.toString() == "(0, 0)");
		assertTrue(p2.toString() == "(0, 0)");

		cout << "== good-8 ==" << endl;
		p1.set(0, 3);
		p2.set(2, 0);
		assertTrue(r.setCorners(p1, p2));
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(0, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(2, 3)");

		cout << "== good-9 ==" << endl;
		r.moveHorizontal(-1);
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(-1, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(1, 3)");

		cout << "== good-10 ==" << endl;
		r.moveVertical(1);
		assertEquals(6, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(-1, 1)");
		assertTrue(r.getUpperRightPoint().toString() == "(1, 4)");
		assertTrue(p1.toString() == "(0, 3)");
		assertTrue(p2.toString() == "(2, 0)");
	}

	cout << endl;

}

void testTriangle()
{

	cout << endl;
	cout << "##################" << endl;
	cout << "## Triangle" << endl;
	cout << "##################" << endl << endl;

	// bad
	{
		Point2D p1;
		Point2D p2;
		Point2D p3;
		Triangle t;

		cout << "== bad-1 ==" << endl;
		p1.setOrigin();
		p2.set(0, 1);
		p3.set(0, 3);
		assertTrue(!t.setPoints(p1, p2, p3));
		assertTrue(!t.setPoints(p1, p3, p2));
		assertTrue(!t.setPoints(p2, p1, p3));
		assertTrue(!t.setPoints(p2, p3, p1));
		assertTrue(!t.setPoints(p3, p1, p2));
		assertTrue(!t.setPoints(p3, p2, p1));
	}

	// right isosceles
	{
		Point2D p1;
		Point2D p2;
		Point2D p3;
		Triangle t;
		Rectangle r;

		cout << "== right-isosceles-1 ==" << endl;
		p1.setOrigin();
		p2.set(0, 1);
		p3.set(1, 0);
		assertTrue(t.setPoints(p1, p2, p3));
		assertEquals(0.5, t.area(), 0.0001);
		assertTrue(t.isRight(0.00001));
		assertTrue(t.isIsosceles(0.01));

		cout << "== right-isosceles-2 ==" << endl;
		r = t.boundingBox();
		assertEquals(1, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(0, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(1, 1)");
	}

	// right
	{
		Point2D p1;
		Point2D p2;
		Point2D p3;
		Triangle t;
		Rectangle r;

		cout << "== right-1 ==" << endl;
		p1.setOrigin();
		p2.set(0, 1);
		p3.set(2, 0);
		assertTrue(t.setPoints(p1, p2, p3));
		assertEquals(1.0, t.area(), 0.0001);
		assertTrue(t.isRight(0.00001));
		assertTrue(!t.isIsosceles(0.01));

		cout << "== right-2 ==" << endl;
		r = t.boundingBox();
		assertEquals(2, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(0, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(2, 1)");
	}

	// isosceles
	{
		Point2D p1;
		Point2D p2;
		Point2D p3;
		Triangle t;
		Rectangle r;

		cout << "== isosceles-1 ==" << endl;
		p1.setOrigin();
		p2.set(-1, 5);
		p3.set(1, 5);
		assertTrue(t.setPoints(p1, p2, p3));
		assertEquals(5.0, t.area(), 0.0001);
		assertTrue(!t.isRight(0.00001));
		assertTrue(t.isIsosceles(0.01));

		cout << "== isosceles-2 ==" << endl;
		r = t.boundingBox();
		assertEquals(10, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(-1, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(1, 5)");
	}

	// ordinary
	{
		Point2D p1;
		Point2D p2;
		Point2D p3;
		Triangle t;
		Rectangle r;

		cout << "== ordinary-1 ==" << endl;
		p1.setOrigin();
		p2.set(-2, 5);
		p3.set(1, 5);
		assertTrue(t.setPoints(p1, p2, p3));
		assertEquals(7.5, t.area(), 0.0001);
		assertTrue(!t.isRight(0.00001));
		assertTrue(!t.isIsosceles(0.01));

		cout << "== ordinary-2 ==" << endl;
		r = t.boundingBox();
		assertEquals(15, r.area());
		assertTrue(r.getLeftLowerPoint().toString() == "(-2, 0)");
		assertTrue(r.getUpperRightPoint().toString() == "(1, 5)");
	}

	cout << endl;

}

