/*********************************************************************
*	HW8
*	Zain Aziz
*	COMP208-03
*	10/4/15
**********************************************************************
*	Problem
*
*	Implement functions used by NumList by using recursion
*
***********************************************************************
*	Pseudocode
*
*	- implement functions using recursions that are used by NumList
*	- make a helper function if needed
*	- make sure all the test cases work
*
**********************************************************************/

#include "NumList.h"
#include "HW8.h"

namespace comp201
{
	
	int sumHelper(int sum, const NumList& l)
	{
		if ( l.isEmpty() )
		{
			return sum;
		}
		else
		{
			return sumHelper( sum + l.first(), l.rest() );
		}
	}
	
	int sum(const NumList& l)
	{
		// You're welcome :)
		return sumHelper( 0, l );
	}
	
	//

	int productHelper(int prod, const NumList& l)
	{
		if (l.isEmpty())
		{
			return 1;  //returns the new list if the original list is empty
		}
		else
		{
			return productHelper( prod * l.first(), l.rest() );  // calls the same function after multiplying the first number of the list by the product
		}														 // and setting that to the new list
	}
	
	int product(const NumList& l)
	{
		return productHelper(1, l);
	}
	
	//

	NumList reverseHelper(NumList& x, const NumList& l)
	{
		if (l.isEmpty())
		{
			return x; //returns the new list if the original list is empty
		}
		else
		{
			return reverseHelper(NumList(l.first(), x), l.rest()); // sets the first number of the original list in the new list and calls the same function
		}														   // with the rest of the original list
	}
	
	NumList reverse(const NumList& l)
	{
		return reverseHelper(NumList(), l);
	}
	
	//
	
	NumList appendHelper(NumList& x, const NumList& first, const NumList& second)
	{
		if (first.isEmpty() && second.isEmpty())
		{
			return reverse(x);  //returns the new reversed list if both the lists are empty
		}
		else if (first.isEmpty())
		{
			return appendHelper(NumList(second.first(), x), first, second.rest()); //sets all the values of the second list to the new list
		}
		else
		{
			return appendHelper(NumList(first.first(), x), first.rest(), second); //sets all the values of the first list to the new list
		}
	}

	NumList append(const NumList& first, const NumList& second)
	{
		return appendHelper(NumList(), first, second);
	}
	
	//

	NumList filterEvenHelper(NumList& x, const NumList& l)
	{
		if (l.isEmpty())
		{
			return reverse(x); //returns the new reversed list if the original list is empty
		}
		else
		{
			if (l.first() % 2 == 0)
			{
				return filterEvenHelper(NumList(l.first(), x), l.rest());  //adds the number of the original list to the new list if it is even
			}
			else
			{
				return filterEvenHelper(x, l.rest());  //returns the same lsit without changing it
			}
		}
	}
	
	NumList filterEven(const NumList& l)
	{
		return filterEvenHelper(NumList(),l);
	}
	
	//

	NumList filterOddHelper(NumList& x, const NumList l)
	{
		if (l.isEmpty())
		{
			return reverse(x); //returns the new reversed list if the original list is empty
		}
		else
		{
			if (l.first() % 2 != 0)
			{
				return filterOddHelper(NumList(l.first(), x), l.rest()); //adds the number of the original list to the new list if it is odd
			}
			else
			{
				return filterOddHelper(x, l.rest()); //returns the same lsit without changing it
			}
		}
	}
	
	NumList filterOdd(const NumList& l)
	{
		return filterOddHelper(NumList(),l);
	}
	
	//

	NumList rotateHelper(NumList& x, const NumList& l, int n)
	{
		if (n > 0)
		{
			if (!x.isEmpty()) //checks if the new list is not empty
			{
				NumList help = reverse(l);					   // makes a temporary NumList 'help' and sets the reversed list to it
				help = reverse(NumList(x.first(), help));	   // sets 'help' with the new list's first number, rest of the numbers from 'help' and reverses that
				return rotateHelper(x.rest(), help, n);		   
			}
			else
			{
				if (!l.isEmpty()) //checks if original list is not empty
				{
					return rotateHelper(NumList(l.first(), x), l.rest(), n - 1); //function calls itself with the original list's first number and gives it the new list's rest
				}																 //gives it the rest of the original list and decreases n by 1
				else
				{
					return l; //returns the original list if it is empty
				}
			}
		}
		else if (!x.isEmpty())
			{
				NumList help = reverse(l);					    // makes a temporary NumList 'help' and sets the reversed list to it
				help = reverse(NumList(x.first(), help));	    // sets 'help' with the new list's first number, rest of the numbers from 'help' and reverses that
				return rotateHelper(x.rest(), help, n);
			}
			else
			{
				return l; //returns the original list if it is empty
			}
	}
	
	NumList rotate(const NumList& l, int n)
	{
		return rotateHelper(NumList(), l, n);
	}
	
	//

	NumList chopHelper(NumList& x, const NumList& l, int n)
	{
		if (n > 0)
		{
			if (!l.isEmpty()) //checks if list is not empty
			{
				return chopHelper(NumList(l.first(), x), l.rest(), n - 1); //gives the new list the original list's first number and its own rest, gives it the original's rest
			}															   //and decreases n by 1
			return reverse(l); //returns the original reversed list if it is empty
		}
		else
		{
			return reverse(l); //returns the original reversed list
		}
	}
	
	NumList chop(const NumList& l, int n)
	{
		return chopHelper(NumList(),reverse(l),n);
	}
	
	//

	NumList insertHelper(NumList& x, const NumList& first, const NumList& second, int n)
	{
		if (n > 0)
		{
			return insertHelper(NumList(first.first(), x), first.rest(), second, n - 1); //adds the first n numbers of the first list to the new list
		}
		else if (!second.isEmpty())
		{
			return insertHelper(NumList(second.first(), x), first, second.rest(), n); //adds the numbers in the second list to the new list
		}
		else if (!first.isEmpty())
		{
			return insertHelper(NumList(first.first(), x), first.rest(), second, n); //adds the numbers in the first list to the new list
		}
		else
			return reverse(x); //returns the new reversed list is n = 0
	}
	
	NumList insert(const NumList& first, const NumList& second, int n)
	{
		return insertHelper(NumList(), first, second, n);
	}
	
}