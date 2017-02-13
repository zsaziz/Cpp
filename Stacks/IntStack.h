#ifndef __INTSTACK_H
#define __INTSTACK_H

#include "SLL.h"
namespace comp201
{
	class IntStack
	{
	public:
		//checks if the stack is empty
		//return true if empty
		bool Empty();
		
		//adds a number to the top of the stack
		void push(int x);

		//removes the number at the top of the stack
		int pop();
	private:
		SLL<int> var;
	};
}
#endif