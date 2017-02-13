
#ifndef __ASCII_ART_H
#define __ASCII_ART_H

#include <string>
#include <ostream>
#include <vector>
#include "Shape.h"

namespace comp201
{
	
	// Shortcut for a Shape*/character pair
	typedef std::pair< Shape*, char > shape_char_t;
	
	// A vector of Shape*/character pairs
	class ShapeCharVector
	{
		friend class ASCIIArt;
		
	public:
		
		// Deallocates all Shape* in the vector
		~ShapeCharVector();
		
		// Adds a Shape*/character to the vector
		//
		// Postconditions: the Shape*/character is added;
		//                 ownership of the pointer is now
		//                 with this vector
		void add(Shape* shape, char c);
		
	private:
		std::vector<shape_char_t> v;
	};
	
	// An ASCII art class (http://en.wikipedia.org/wiki/ASCII_art)
	class ASCIIArt
	{
	public:
		
		// Initializes the art with a clear canvas
		// of the provided height and width
		ASCIIArt(int height, int width);
		
		// Deallocates the art
		//
		// Postconditions: all allocated memory is released
		virtual ~ASCIIArt() = 0;
		
		// Gets the height of the art
		//
		// Returns: height of the art
		int getHeight() const;
		
		// Gets the width of the art
		//
		// Returns: width of the art
		int getWidth() const;
		
		// Gets the art as a string
		//
		// Returns: the art as a string
		std::string asString() const;
		
		// Outputs the art to a stream
		//
		// Postconditions: the string representation fo the art is sent to the stream
		// Returns: the provided stream
		friend std::ostream& operator <<(std::ostream& outs, const ASCIIArt& art);
		
	protected:
		
		// Draws a vector of Shape*/Character pairs to this artwork
		//
		// Postconditions: each shape is drawn to the canvas with the associated character
		void drawShapes(const ShapeCharVector& shapes);
		
	private:
		void drawShape(const Shape& shape, char c);
		
		char **canvas;
		const int height;
		const int width;
		
	};
	
}

#endif
