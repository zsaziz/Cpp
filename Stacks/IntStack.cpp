#include "IntStack.h"
using namespace std;
namespace comp201
{
	bool IntStack::Empty()
	{
		if (var.isEmpty())  //returns true if it is empty
			return true;
		else
			return false;
	}
	void IntStack::push(int x)
	{
		var.addToFront(x);  //adds a number to the top of the stack using the addToFront function
	}
	int IntStack::pop()
	{
		return var.removeFromFront();  //pops a number from the top of the stack using the removeFromFront function
	}
}
