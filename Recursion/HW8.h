
#ifndef __HW8_H
#define __HW8_H

namespace comp201
{

	// Sums up all elements of a list
	//
	// Returns: sum of all elements of l, 0 if list is empty
	int sum(const NumList& l);
	
	// Multiplies all elements of a list
	//
	// Returns: product of all elements of l, 1 if list is empty
	int product(const NumList& l);
	
	// Returns the reverse of a list
	// e.g. [ 1 2 3 ] -> [ 3 2 1 ]
	//
	// Returns: reversed list
	NumList reverse(const NumList& l);
	
	// Returns a list that has all the
	// elements of the first list followed
	// by all the elements of the second list
	// e.g. [ 1 2 ], [ 3 4 ] -> [ 1 2 3 4 ]
	//
	// Returns: new list [ first second ]
	NumList append(const NumList& first, const NumList& second);
	
	// Returns a list that has all the elements
	// of the list that are even in value in the
	// same order that they appear
	// e.g. [ 4 4 1 3 2 0 ] -> [ 4 4 2 0 ]
	//
	// Returns: new filtered list
	NumList filterEven(const NumList& l);
	
	// Returns a list that has all the elements
	// of the list that are odd in value in the
	// same order that they appear
	// e.g. [ 4 4 1 3 2 0 ] -> [ 1 3 ]
	//
	// Returns: new filtered list
	NumList filterOdd(const NumList& l);
	
	// Returns a list that is equal to the original list
	// with the first n elements moved to the end
	// of the list
	// e.g. [ 1 2 3 4 ], 2 -> [ 3 4 1 2 ]
	//
	// Returns: new rotated list
	NumList rotate(const NumList& l, int n);
	
	// Returns a list that is equal to the original list
	// without the last n elements
	// e.g. [ 1 2 3 4 ], 2 -> [ 1 2 ]
	//
	// Precondition: n <= size of l
	// Returns: new chopped list
	NumList chop(const NumList& l, int n);
	
	// Returns a list comprising the first n elements of
	// the first list, followed by all the elements of the
	// second list, followed by the remaining elements of the
	// first list
	// e.g. [ 1 2 3 ], [ 4 5 6 ], 2 -> [ 1 2 4 5 6 3 ]
	//
	// Preconditions: n <= size of first
	// Returns: new resulting list
	NumList insert(const NumList& first, const NumList& second, int n);
	
}

#endif
