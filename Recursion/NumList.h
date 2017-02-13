
#ifndef __NUM_LIST_H
#define __NUM_LIST_H

#include <list>
#include <string>

namespace comp201
{
	
	// A list of numbers
	class NumList
	{
	public:
		
		// Creates an empty list
		NumList();
		
		// Creates a new list composed of front
		// followed by the given list
		NumList(int front, const NumList& rest);
		
		// Detects if the list is empty
		//
		// Returns: true if there are no elements in the list
		bool isEmpty() const;
		
		// Returns the first element of the list
		// Note: undefined if called on an empty list
		//
		// Returns: first element of the list
		int first() const;
		
		// Returns a list containing all but the first element
		// of the list
		// Note: undefined if called on an empty list
		//
		// Returns: new list not containing the first element of this list
		NumList rest() const;
		
		// Gets a string representation of this list
		//
		// Returns: [ element1 element2 ... ]
		std::string toString() const;
		
		// Outputs the toString to the output stream
		friend std::ostream& operator <<(std::ostream& outs, const NumList& l);
		
	private:
		std::list<int> l;
	};
	
}

#endif
