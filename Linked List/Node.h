#ifndef __NODE_H
#define __NODE_H

#include <ostream>

namespace comp201
{

	// Class representing a node in a doubly linked list
	//
	// Template parameter indicates the type of data
	template <typename T>
	class Node
	{
		template <class O>
		friend std::ostream& operator <<(std::ostream& outs, const Node<O>& n);

		template <class O>
		friend class LinkedList;

	public:

		// Gets the next node
		//
		// Returns: pointer to the next node
		Node<T>* getNext()
		{
			return next;
		}

		// Gets the previous node
		//
		// Returns: pointer to the previous node
		Node<T>* getPrevious()
		{
			return previous;
		}

		// Gets the payload
		//
		// Returns: data held by the node
		T getData()
		{
			return data;
		}

	private:
		T data;
		Node<T>* next;
		Node<T>* previous;
	};

	// Overloads the insertion operator to output the node data
	template <class T>
	std::ostream& operator <<(std::ostream& outs, const Node<T>& n)
	{
		outs << n.data;
		return outs;
	}

}

#endif
