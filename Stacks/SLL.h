
#ifndef __SLL_H
#define __SLL_H

#include <cstdlib>

namespace comp201
{

	// Node in an SLL
	template <typename T>
	struct SLLNode
	{
		T data;
		SLLNode<T>* next;
	};

	// A singly linked list
	template <typename T>
	class SLL
	{
	public:

		// Initializes an empty list
		SLL()
		{
			head = NULL;
		}

		// Releases all list memory
		~SLL()
		{
			while (!isEmpty())
				removeFromFront();
		}

		// Determines if the list is empty
		//
		// Returns: true if the list is empty
		bool isEmpty()
		{
			return (head == NULL);
		}

		// Adds a datum to the front of the list
		//
		// PostConditions: data is at the head of the list
		void addToFront(T data)
		{
			SLLNode<T>* tmp = new SLLNode<T>();
			tmp->data = data;
			tmp->next = head;
			head = tmp;
		}

		// Removes a character from the front of the list
		//
		// PostConditions: the datum at the front of
		//                 the list has been removed
		// Returns: datum at the front of the list,
		//          0 if the list was empty
		T removeFromFront()
		{
			T return_val = 0;

			if (head != NULL)
			{
				SLLNode<T>* tmp = head;
				head = tmp->next;
				return_val = tmp->data;
				delete tmp;
			}

			return return_val;
		}

	private:
		SLLNode<T>* head;
	};

}

#endif
