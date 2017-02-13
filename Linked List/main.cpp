#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

typedef comp201::LinkedList<int> LL_int_t;
typedef comp201::LinkedList<string> LL_str_t;

typedef comp201::Node<string> Node_str_t;
typedef Node_str_t* Node_str_ptr;

int main()
{
	LL_int_t l;
	cout << l << " = [ ]" << endl;

	l.addToBack(3);
	cout << l << " = [ 3 ]" << endl;

	l.addToBack(1);
	cout << l << " = [ 3 1 ]" << endl;

	l.addToBack(4);
	cout << l << " = [ 3 1 4 ]" << endl;

	l.addToBack(1);
	cout << l << " = [ 3 1 4 1 ]" << endl;

	l.addToBack(5);
	cout << l << " = [ 3 1 4 1 5 ]" << endl;

	l.addToBack(9);
	cout << l << " = [ 3 1 4 1 5 9 ]" << endl;

	l.remove(l.findFirst(3));
	cout << l << " = [ 1 4 1 5 9 ]" << endl;

	l.remove(l.findFirst(9));
	cout << l << " = [ 1 4 1 5 ]" << endl;

	l.remove(l.findFirst(9));
	cout << l << " = [ 1 4 1 5 ]" << endl;

	l.remove(l.findFirst(4));
	cout << l << " = [ 1 1 5 ]" << endl;

	l.remove(l.findFirst(1));
	cout << l << " = [ 1 5 ]" << endl;

	l.remove(l.findFirst(5));
	cout << l << " = [ 1 ]" << endl;

	l.remove(l.findFirst(1));
	cout << l << " = [ ]" << endl;

	l.remove(l.findFirst(3));
	cout << l << " = [ ]" << endl;

	l.addToFront(2);
	cout << l << " = [ 2 ]" << endl;

	l.addToBack(7);
	cout << l << " = [ 2 7 ]" << endl;

	l.addToBack(1);
	cout << l << " = [ 2 7 1 ]" << endl;

	l.addToBack(8);
	cout << l << " = [ 2 7 1 8 ]" << endl;

	int killCounter = 0;
	while (!l.empty())
	{
		l.remove(l.first());
		cout << l;

		switch (killCounter)
		{
		case 0:
			cout << " = [ 7 1 8 ]";
			break;

		case 1:
			cout << " = [ 1 8 ]";
			break;

		case 2:
			cout << " = [ 8 ]";
			break;

		case 3:
			cout << " = [ ]";
			break;
		}
		cout << endl;
		killCounter++;
	}

	l.addToFront(1);
	cout << l << " = [ 1 ]" << endl;

	l.addToFront(0);
	cout << l << " = [ 0 1 ]" << endl;

	l.addToFront(2);
	cout << l << " = [ 2 0 1 ]" << endl;

	killCounter = 0;
	while (!l.empty())
	{
		l.remove(l.last());
		cout << l;

		switch (killCounter)
		{
		case 0:
			cout << " = [ 2 0 ]";
			break;

		case 1:
			cout << " = [ 2 ]";
			break;

		case 2:
			cout << " = [ ]";
			break;
		}
		cout << endl;
		killCounter++;
	}

	l.addToFront(0);
	cout << l << " = [ 0 ]" << endl;

	int year[] = { 2, 0, 1, 5 };
	l.set(year, 4);
	cout << l << " = [ 2 0 1 5 ]" << endl;

	//

	LL_str_t l2;
	cout << l2 << " = [ ]" << endl;

	Node_str_ptr comp = l2.addToFront("COMP");
	cout << l2 << " = [ COMP ]" << endl;

	Node_str_ptr derbinsky = l2.addToBack("Derbinsky");
	cout << l2 << " = [ COMP Derbinsky ]" << endl;

	l2.addAfter(comp, "201");
	cout << l2 << " = [ COMP 201 Derbinsky ]" << endl;

	l2.addBefore(derbinsky, "Professor");
	cout << l2 << " = [ COMP 201 Professor Derbinsky ]" << endl;

	l2.addBefore(comp, "!!!");
	cout << l2 << " = [ !!! COMP 201 Professor Derbinsky ]" << endl;

	l2.addAfter(derbinsky, "!!!");
	cout << l2 << " = [ !!! COMP 201 Professor Derbinsky !!! ]" << endl;

	string done[] = { "fin" };
	l2.set(done, 1);
	cout << l2 << " = [ fin ]" << endl;

	return 0;
}
