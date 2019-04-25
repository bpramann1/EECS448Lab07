/**
*	@author 
*	@date 
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
#include "LinkedListOfInts.h"
#include "myTester.h"

int main(int argc, char** argv)
{
	//Example of declaring a LinkedListOfInts
	LinkedListOfInts testableList;

	//You won't do all the tests in main; that's what your Test class will be for
	//Example:
	std::cout << "Running...\n";
	myTester myTester;
	myTester.runTests(testableList);
	
	std::cout << "\nAnd we're done.\nGoodbye.\n";
	
	return (0);

}

