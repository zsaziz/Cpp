
#include "ASCIIArt.h"

namespace comp201
{
	
	ShapeCharVector::~ShapeCharVector()
	{
		for ( std::vector<shape_char_t>::iterator it=v.begin();
			 it!= v.end();
			 it++ )
		{
			delete it->first;
		}
	}
	
	void ShapeCharVector::add(Shape* shape, char c)
	{
		v.push_back( std::make_pair( shape, c ) );
	}
	
	//
	
	ASCIIArt::ASCIIArt(int height, int width):
	height( height ), width( width )
	{
		canvas = new char*[ height ];
		for ( int i=0; i<height; i++ )
		{
			canvas[i] = new char[ width+1 ];
			canvas[i][ width ] = '\0';
			
			for ( int j=0; j<width; j++ )
			{
				canvas[i][j] = ' ';
			}
		}
	}
	
	ASCIIArt::~ASCIIArt()
	{
		for ( int i=0; i<height; i++ )
		{
			delete[] canvas[i];
		}
		delete[] canvas;
	}
	
	int ASCIIArt::getHeight() const
	{
		return height;
	}
	
	int ASCIIArt::getWidth() const
	{
		return width;
	}
	
	std::string ASCIIArt::asString() const
	{
		std::string result;
		
		for ( int i=( height-1 ); i>=0; i-- )
		{
			result += canvas[i];
			result += "\n";
		}
		
		return result;
	}
	
	std::ostream& operator <<(std::ostream& outs, const comp201::ASCIIArt& art)
	{
		outs << art.asString();
		return outs;
	}
	
	void ASCIIArt::drawShape(const Shape& shape, char c)
	{
		for ( int row=0; row<height; row++ )
		{
			for ( int col=0; col<width; col++ )
			{
				if ( shape.coversPosition( col, row ) )
				{
					canvas[ row ][ col ] = c;
				}
			}
		}
	}
	
	void ASCIIArt::drawShapes(const ShapeCharVector& shapes)
	{
		for ( std::vector<shape_char_t>::const_iterator it=shapes.v.begin();
			 it!= shapes.v.end();
			 it++ )
		{
			drawShape( *( it->first ), it->second );
		}
	}
	
}
