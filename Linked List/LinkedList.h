/*********************************************************************
*	HW6
*	Zain Aziz
*	COMP208-03
*	31 March 2015
**********************************************************************
*	Problem
*
*	Make a linked list.
*
***********************************************************************
*	Analysis
*
*	Inputs:  None
*			  
*	Outputs: Test cases
*
***********************************************************************
*	Pseudocode
*
*	- implement the class LinkedList
	- fill in different functions
	- test cases run to see if it works
*
**********************************************************************/
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <ostream>
#include "Node.h"

namespace comp201
{
	// Class implementing a doubly linked list
	//
	// Template parameter indicates the type of data in
	// each node of the list
	template <typename T>
	class LinkedList
	{

		template <class O>
		friend std::ostream& operator <<(std::ostream& outs, const LinkedList<O>& l);

	public:

		// Initializes an empty list
		LinkedList()
		{
			head = tail = NULL;  //points head and tail to NULL
		}

		// Clears the list (deallocating any memory)
		~LinkedList()
		{
			if ((head != NULL) && (tail != NULL))
			{
				while (head != NULL)
				{
					Node<T>* tmp = head;
					head = tmp->next;  //keeps pointing the head to the next node
					if (head == NULL)
						tail = NULL;  //points the tail to NULL
					delete tmp;
				}
			}
		}

		// Adds a value to the front of the list
		//
		// val - data to add to the list
		//
		// Postconditions: a new node is added to the front of the list
		Node<T>* addToFront(T val)
		{
			Node<T>* tmp;
			if (empty())
			{
				tmp = newNode(val, NULL, NULL);  //if the list is empty adds value to new node and points head and tail to it
				head = tmp;
				tail = tmp;
			}
			else
			{
				tmp = newNode(val, head, NULL);  //adds value to the the the new node and points it to the next and NULL for previous
				head->previous = tmp;
				head = tmp;
			}
			return tmp;
		}

		// Adds a value to the back of the list
		//
		// val - data to add to the list
		//
		// Postconditions: a new node is added to the back of the list
		Node<T>* addToBack(T val)
		{
			Node<T>* tmp;
			if (empty())
			{
				tmp = newNode(val, NULL, NULL);  //if the list is empty adds value to new node and points head and tail to it
				head = tmp;
				tail = tmp;
			}
			else
			{
				tmp = newNode(val, NULL, tail); //adds value to the the the new node and points it to the previous and NULL for next
				tail->next = tmp;
				tail = tmp;
			}
			return tmp;
		}

		// Adds a value to the list after a provided node
		//
		// n - reference node
		// val - data to add to the list
		//
		// Postconditions: a new node is added to the list with value val after n
		Node<T>* addAfter(Node<T>* n, T val)
		{
			Node<T>* x = head;
			for (x; x != NULL; x = x->next)
			{
				if (x == n)
				{
					if (n == tail)
					{
						Node<T>* tmp = newNode(val, NULL, n); //sets the value to a new node if the node is last
						n->next = tmp; 
						tail = tmp;
						return tmp;
					}
					else
					{
						Node<T>* tmp = newNode(val, n->next, n); //sets the value to a new node after the node given
						n->next = tmp;
						tmp->next->previous = tmp;
						return tmp;
					}
				}
			}
			return NULL;
		}

		// Adds a value to the list before a provided node
		//
		// n - reference node
		// val - data to add to the list
		//
		// Postconditions: a new node is added to the list with value val before n
		Node<T>* addBefore(Node<T>* n, T val)
		{
			Node<T>* x = head;
			for (x; x != NULL; x = x->next)
			{
				if (x == n)
				{
					if (x == head)
					{
						Node<T>* tmp = newNode(val, n, NULL);  //adds the value to a new node in the front
						n->previous = tmp;
						head = tmp;
						return tmp;
					}
					else
					{
						Node<T>* tmp = newNode(val, n, n->previous);  //adds the value to a new node before the given node
						n->previous = tmp;
						tmp->previous->next = tmp;
						return tmp;
					}
				}
			}
			return NULL;
		}

		// Finds the first node to have the provided value
		//
		// val - reference value
		//
		// Returns: the first node with value val, or NULL if none do
		Node<T>* findFirst(T val)
		{
			Node<T>* x;
			for (x = head; x != NULL; x = x->next)  
			{
				if (x->data == val)  //finds the value in a node and returns that
					return x;
			}
			return NULL;
		}

		// Removes the provided node from the list
		//
		// n - reference node
		//
		// Postconditions: node n is not in the list, its memory is deallocated
		void remove(Node<T>* n)
		{
			Node<T>* x;
			for (x = head; x != NULL; x = x->next)
			{
				if (x == n)
				{
					Node<T>* tmp = x;
					if (tmp->next == NULL && tmp->previous == NULL)  //if the tmp's next and previous point to NULL, points the head and tail tp null
						head = tail = NULL;
					else if (tmp->next == NULL)
					{
						tmp->previous->next = NULL;  //points the node before tmp to NULL
						tail = tmp->previous;
					}
					else if (tmp->previous == NULL)
					{
						tmp->next->previous = NULL;  //points the node after tmp to NULL
						head = tmp->next;
					}
					else
					{
						tmp->previous->next = tmp->next;  //points the node before tmp to tmp
						tmp->next->previous = tmp->previous;
					}
					delete tmp;
					break;
				}
			}
		}

		// Gets the front of the list
		//
		// Returns: a pointer to the first node in the list, NULL if empty
		Node<T>* first()
		{
			return head;
		}

		// Gets the tail of the list
		//
		// Returns: a pointer to the last node in the list, NULL if empty
		Node<T>* last()
		{
			return tail;
		}

		// Determines if the list is empty
		//
		// Returns: true if the list is empty
		bool empty()
		{
			if ((head == NULL) && (tail == NULL))
				return true;
			return false;
		}

		// Clears the list
		//
		// Postconditions: there are no nodes in the list, all memory is deallocated
		void clear()
		{
			if ((head != NULL) && (tail != NULL))
			{
				while (head != NULL)
				{
					Node<T>* tmp = head;
					head = tmp->next;   //keeps pointing the head to the next node
					if (head == NULL)
						tail = NULL;   //points the tail to NULL
					delete tmp;
				}
			}
		}

		// Replaces the list with the contents of the supplied array
		//
		// vals - array of values
		// size - size of vals
		//
		// Postconditions: the old list is cleared and replaced with a new
		//                 list whose nodes reflect the values and order
		//                 of vals
		void set(T vals[], int size)
		{
			clear();
			for (int i = size-1; i >= 0; i--)
			{
				addToFront(vals[i]);  //clears the list and makes a new one with values from the given array
			}
		}

	private:
		Node<T>* head;
		Node<T>* tail;

		// Utility function to create a new node with provide data, next, previous
		Node<T>* newNode(T val, Node<T>* next, Node<T>* previous)
		{
			Node<T>* newbie = new Node<T>();
			newbie->data = val;
			newbie->next = next;
			newbie->previous = previous;
			return newbie;
		}

	};

	// Overloads the insertion operator to output the list
	template <class T>
	std::ostream& operator <<(std::ostream& outs, const LinkedList<T>& l)
	{
		outs << "[";
		for (Node<T>* n = l.head; n != NULL; n = n->getNext())
		{
			outs << " " << *n;
		}
		outs << " ]";
		return outs;
	}

}

#endif
