/*********************************************************************
*	HW7
*	Zain Aziz
*	COMP208-03
*	4/2/15
**********************************************************************
*	Problem
*
*	Implementing the Reverse Polish Notation calculator using linked list
*
***********************************************************************
*	Analysis
*
*	Inputs:  Numbers and operators from the command line
*
*	Outputs: Final answer
*
***********************************************************************
*	Pseudocode
*
*	Implement IntStack class. It has 3 functions in it. Pop returns the
	number on top of the stack. Push adds a numbers to the top of the list.
	Empty checks if the list is empty.
	Takes in the numbers from the command line and pushes them on the stack.
	Checks if there is an operator and computes the answer for that operation,
	then pushes the answer on top of the list.
*
**********************************************************************/

#include "IntStack.h"
#include "SLL.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
using namespace comp201;
int main(int argc, char *argv[])
{
	IntStack y;
	for (int i = 1; i < argc; i++)
	{
		string a = argv[i];
		if (a.compare("+") == 0) //checks the operation
		{
			int x1 = y.pop(); //pops the top two numbers and pushes their sum
			int x2 = y.pop();
			y.push(x1 + x2);
		}
		else if (a.compare("-") == 0) //checks the operation
		{
			int x1 = y.pop(); //pops the top two numbers and pushes their difference
			int x2 = y.pop();
			y.push(x2 - x1);
		}
		else if (a.compare("x") == 0) //checks the operation
		{
			int x1 = y.pop(); //pops the top two numbers and pushes their product
			int x2 = y.pop();
			y.push(x1 * x2);
		}
		else if (a.compare("/") == 0) //checks the operation
		{
			int x1 = y.pop(); //pops the top two numbers and pushes their quotient
			int x2 = y.pop();
			y.push(x2 / x1);
		}
		else
		{
			y.push(atoi(argv[i])); //pushes the numbers on the stack
		}
	}
	cout << y.pop() << endl;  //outputs the final answer
}
