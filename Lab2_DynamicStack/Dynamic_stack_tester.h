/*************************************************
* Dynamic_stack_tester
* A class for testing dynamic stack-as-arrays.
*
* Author:  Douglas Wilhelm Harder
* Copyright (c) 2006 by Douglas Wilhelm Harder.  All rights reserved.
*
* DO NOT EDIT THIS FILE
*************************************************/

#ifndef DYNAMIC_STACK_TESTER_H
#define DYNAMIC_STACK_TESTER_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include "Tester.h"
#include "Dynamic_stack.h"

#include <iostream>

using namespace std;

template <typename Type>
class Dynamic_stack_tester :public Tester< Dynamic_stack<Type> > {
	using Tester< Dynamic_stack<Type> >::object;
	using Tester< Dynamic_stack<Type> >::command;

public:
	Dynamic_stack_tester(Dynamic_stack<Type> *obj = 0) :Tester< Dynamic_stack<Type> >(obj) {
		// empty
	}
	void process();
};

/****************************************************
* void process()
*
* Process the current command.  For dynamic stack-as-arrays, these include:
*
*  Accessors
*
*   size n          size            the size equals n
*   capacity n      capacity        the capcity equals n
*   empty b         empty           the result is the Boolean value b
*   top n           top            n is the top element in the stack
*   top!            top            the underflow exception is thrown
*
*  Mutators
*
*   push n          push    the element can be push (always succeeds)
*   pop n           pop    the top can be pop
*   pop!            pop    the underflow exception is thrown
*
*   details                         details about memory allocation
****************************************************/

template <typename Type>
void Dynamic_stack_tester<Type>::process() {
	if (command == "new") {
		object = new Dynamic_stack<Type>();
		std::cout << "Okay" << std::endl;
	}
	else if (command == "new:") {
		int n;
		std::cin >> n;
		object = new Dynamic_stack<Type>(n);
		std::cout << "Okay" << std::endl;

	}
	else if (command == "size") {
		// check if the size equals the next integer read

		int expected_size;

		cin >> expected_size;

		int actual_size = object->size();

		if (actual_size == expected_size) {
			cout << "Okay" << endl;
		}
		else {
			cout << "Failure in size(): expecting the value '" << expected_size << "' but got '" << actual_size << "'" << endl;
		}
	}
	else if (command == "capacity") {
		// check if the capacity equals the next integer read

		int expected_capacity;

		cin >> expected_capacity;

		int actual_capacity = object->capacity();

		if (actual_capacity == expected_capacity) {
			cout << "Okay" << endl;
		}
		else {
			cout << "Failure in capacity(): expecting the value '" << expected_capacity << "' but got '" << actual_capacity << "'" << endl;
		}
	}
	else if (command == "empty") {
		// check if the empty status equals the next Boolean read

		bool expected_empty;

		cin >> expected_empty;

		bool actual_empty = object->empty();

		if (actual_empty == expected_empty) {
			cout << "Okay" << endl;
		}
		else {
			cout << "Failure in empty(): expecting the value '" << expected_empty << "' but got '" << actual_empty << "'" << endl;
		}
	}
	else if (command == "top") {
		// checks if the top integer in the stack equals the next integer read

		Type expected_top;

		cin >> expected_top;

		Type actual_top = object->top();

		if (actual_top == expected_top) {
			cout << "Okay" << endl;
		}
		else {
			cout << "Failure in top(): expecting the value '" << expected_top << "' but got '" << actual_top << "'" << endl;
		}
	}
	else if (command == "top!") {
		// top of an empty stack - catch an exception

		Type actual_top;

		try {
			actual_top = object->top();
			cout << "Failure in top(): expecting to catch an exception but got '" << actual_top << "'" << endl;
		}
		catch (underflow) {
			cout << "Okay" << endl;
		}
		catch (...) {
			cout << "Failure in top(): expecting an underflow exception but caught a different exception" << endl;
		}
	}
	else if (command == "push") {
		// push the next integer read to the front of the stack

		Type n;

		cin >> n;

		object->push(n);
		cout << "Okay" << endl;
	}
	else if (command == "pop") {
		// pop the top integer from the stack

		Type expected_popped_element;

		cin >> expected_popped_element;

		Type actual_popped_element = object->pop();

		if (actual_popped_element == expected_popped_element) {
			cout << "Okay" << endl;
		}
		else {
			cout << "Failure in pop(): expecting the value '" << expected_popped_element << "' but got '" << actual_popped_element << "'" << endl;
		}
	}
	else if (command == "pop!") {
		// pop from an empty stack - catch an exception

		Type actual_popped_element;

		try {
			actual_popped_element = object->pop();
			cout << "Failure in pop(): expecting to catch an exception but got '" << actual_popped_element << "'" << endl;
		}
		catch (underflow) {
			cout << "Okay" << endl;
		}
		catch (...) {
			cout << "Failure in pop(): expecting an underflow exception but caught a different exception" << endl;
		}

	}
	else if (command == "assign") {
		Dynamic_stack<Type> *new_object = new Dynamic_stack<Type>();

		*new_object = *(object);

		std::cout << "Okay" << std::endl;

		Dynamic_stack_tester<Type> tester(new_object);

		tester.run();

	}
	else if (command == "clear") {
		object->clear();

		cout << "Okay" << endl;

	}
	else if (command == "print") {
		//object->print();

		cout << "PRINT NOT IMPLEMENTED" << endl;
	}
	else {
		cout << command << ": Command not found." << endl;
	}
}
#endif
