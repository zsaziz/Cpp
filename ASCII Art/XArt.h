
#ifndef __X_ART_H
#define __X_ART_H

#include "ASCIIArt.h"

namespace comp201
{

	// Makes a variable-sized square
	// that is X'd using the 'X' character
	// For example (size=3):
	// X X
	//  X 
	// X X
	class XArt : public ASCIIArt
	{
	public:
		
		// Draws the shapes
		XArt(int sideLength);
		
	};
	
}

#endif
