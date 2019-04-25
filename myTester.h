#pragma once
#include "LinkedListOfInts.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class myTester
{
public:
	myTester();
	~myTester();
	int currentRandomNumber;
	void runTests(LinkedListOfInts testableList);
	void runTest(vector<int> expectedInVectorRepresentation, LinkedListOfInts actual, string lastListManipulationMethodName);
	bool exists();
	bool areEqual(int expected, int actual, string methodName, string whichTestDeclarationString = "", int testNestDepth = 0);
	bool  isTrue(bool valueToBeTested, string methodName, string whichTestDeclarationString = "", int testNestDepth = 0);
	bool isFalse(bool valueToBeTested, string methodName, string whichTestDeclarationString = "", int testNestDepth = 0);
	bool areEquivalentVectors(vector<int> expected, vector<int> actual, string methodName, string whichTestDeclarationString = "", int testNestDepth = 0);
};

