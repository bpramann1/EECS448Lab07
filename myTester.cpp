#include "myTester.h"
#include "LinkedListOfInts.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

myTester::myTester()
{
	srand(time(0));
}


myTester::~myTester()
{
}
void myTester::runTest(vector<int> expectedInVectorRepresentation, LinkedListOfInts actual, string lastListManipulationMethodName) {
	//Testing isEmpty
	if (expectedInVectorRepresentation.empty())
	{
		myTester::isTrue(actual.isEmpty(), "isEmpty", "Testing isEmpty method of LinkedListOfInts to check that it is empty...", 1);
	} else{
		myTester::isFalse(actual.isEmpty(), "isEmpty", "Testing isEmpty method of LinkedListOfInts to check that it is not empty...", 1);
	}

	//Testing size
	myTester::areEqual(expectedInVectorRepresentation.size(), actual.size(), "size", ("Testing size method of LinkedListOfInts to make sure that the size is " + to_string(expectedInVectorRepresentation.size()) + " ..."), 1);

	//Testing to make sure that values that should not be in the list are not in the list
	bool currentRandomNumberValid;
	for (int i = 0; i < 3; i++)
	{
		currentRandomNumber = (rand() % ((actual.size()*4)+10)) - actual.size();
		currentRandomNumberValid = true;
		for (int i = 0; i < expectedInVectorRepresentation.size(); i++)
		{
			if (currentRandomNumber == expectedInVectorRepresentation[i])
			{
				currentRandomNumberValid = false;
			}
		}
		if (currentRandomNumberValid)
		{
			myTester::isFalse(actual.search(currentRandomNumber), "search", "Testing search method of LinkedListOfInts with the value " + to_string(currentRandomNumber) + " when " + to_string(currentRandomNumber) + " should not be in the list...", 1);
		}
		else
		{
			i--;
		}
	}

	//Testing to make sure that values that should be in the list are in the list
	for (int i = 0; i < expectedInVectorRepresentation.size(); i++)
	{
		myTester::isTrue(actual.search(expectedInVectorRepresentation[i]), "search", "Testing search method of LinkedListOfInts with the value " + to_string(expectedInVectorRepresentation[i]) + " when " + to_string(expectedInVectorRepresentation[i]) + " should be in the list...", 1);
	}

	//Testing to make sure that the expected vector representation is the actual vector representation
	if (myTester::areEquivalentVectors(expectedInVectorRepresentation, actual.toVector(), lastListManipulationMethodName)) {
		if (lastListManipulationMethodName!="no")
		{
			cout << "\n" << lastListManipulationMethodName << " method of LinkedListOfInts appears to have correctly changed the list...";
		}
	}
}
void myTester::runTests(LinkedListOfInts testableList) {
	vector<int> expectedListInVectorForm;
	//testing to make sure that the list is empty
	runTest(expectedListInVectorForm, testableList, "no");
	//myTester::isTrue(testableList.isEmpty(), "isEmpty", "Testing isEmpty method of LinkedListOfInts...");

	//myTester::areEqual(0,testableList.size(), "size", "Testing size method of LinkedListOfInts...");

	//myTester::isFalse(testableList.search(0), "search", "Testing search method of LinkedListOfInts with a value when there should be none...");

	


	//testing to make sure that the list works after adding a value to the back
	cout << "\nTesting addBack method of LinkedListOfInts with a value...";
	currentRandomNumber = (rand() % 21) - 10;
	expectedListInVectorForm.push_back(currentRandomNumber);
	testableList.addBack(currentRandomNumber);
	runTest(expectedListInVectorForm, testableList, "addBack");
	expectedListInVectorForm = testableList.toVector();


	//Testing to make sure that the list is still valid after adding a second value to the back
	cout << "\nRetesting addBack method of LinkedListOfInts with a value...";
	currentRandomNumber = (rand() % 21) - 10;
	expectedListInVectorForm.push_back(currentRandomNumber);
	testableList.addBack(currentRandomNumber);
	runTest(expectedListInVectorForm, testableList, "addBack");
	expectedListInVectorForm = testableList.toVector();


	//Testing to make sure that the list is still valid after adding a value to the front
	cout << "\nTesting addFront method of LinkedListOfInts with a value...";
	currentRandomNumber = (rand() % 21) - 10;
	expectedListInVectorForm.insert(expectedListInVectorForm.begin(), currentRandomNumber);
	testableList.addFront(currentRandomNumber);
	runTest(expectedListInVectorForm, testableList, "addFront");
	expectedListInVectorForm = testableList.toVector();

	//Testing to make sure that the list is still valid after adding a second value is added to the front
	cout << "\nRetesting addFront method of LinkedListOfInts with a value...";
	currentRandomNumber = (rand() % 21) - 10;
	expectedListInVectorForm.insert(expectedListInVectorForm.begin(), currentRandomNumber);
	testableList.addFront(currentRandomNumber);
	runTest(expectedListInVectorForm, testableList, "addFront");
	expectedListInVectorForm = testableList.toVector();




	//Testing to make sure that the list is still valid after removing a value from the from the back
	cout << "\nTesting removeBack method of LinkedListOfInts with a value...";
	expectedListInVectorForm.pop_back();
	testableList.removeBack();
	runTest(expectedListInVectorForm, testableList, "removeBack");
	expectedListInVectorForm = testableList.toVector();

	//Testing to make sure that the list is still valid after removing a second value from the back
	cout << "\nRetesting removeBack method of LinkedListOfInts with a value...";
	expectedListInVectorForm.pop_back();
	testableList.removeBack();
	runTest(expectedListInVectorForm, testableList, "removeBack");
	expectedListInVectorForm = testableList.toVector();


	//Testing to make sure that the list is still valid after removing a value from the from the front
	cout << "\nTesting removeFront method of LinkedListOfInts with a value...";
	expectedListInVectorForm.erase(expectedListInVectorForm.begin());
	testableList.removeFront();
	runTest(expectedListInVectorForm, testableList, "removeFront");
	expectedListInVectorForm = testableList.toVector();

	//Testing to make sure that the list is still valid after removing a second value from the front
	cout << "\nRetesting removeFront method of LinkedListOfInts with a value...";
	expectedListInVectorForm.erase(expectedListInVectorForm.begin());
	testableList.removeFront();
	runTest(expectedListInVectorForm, testableList, "removeFront");
	expectedListInVectorForm = testableList.toVector();
}

bool  myTester::isTrue(bool valueToBeTested, string methodName, string whichTestDeclarationString, int testNestDepth) {
	string tabs = "\n";
	for (int i = 0; i < testNestDepth; i++)
	{
		tabs += "\t";
	}
	if (whichTestDeclarationString != "")
	{
		cout << tabs << whichTestDeclarationString;
	}
	if (!valueToBeTested)
	{
		cout << tabs << "\tThe method " << methodName << " was expected to return true; however, the actual value was false!\n";
		cout << tabs << "The test for method " << methodName << " failed!\n";
		return false;
	}
	cout << tabs << "\tThe method " << methodName << " was expected to return true and the actual value was true!\n";
	cout << tabs << "The test for method " << methodName << " passed!\n";
	return true;
}
bool  myTester::isFalse(bool valueToBeTested, string methodName, string whichTestDeclarationString, int testNestDepth) {
	string tabs = "\n";
	for (int i = 0; i < testNestDepth; i++)
	{
		tabs += "\t";
	}
	if (whichTestDeclarationString != "")
	{
		cout << tabs << whichTestDeclarationString;
	}
	if (!valueToBeTested)
	{
		cout << tabs << "\tThe method " << methodName << " was expected to return false and the actual value was false!\n";
		cout << tabs << "The test for method " << methodName << " passed!\n";
		return false;
	}
	cout << tabs << "The method " << methodName << " was expected to return false; however, the actual value was true!\n";
	cout << tabs << "The test for method " << methodName << " failed!\n";
	return true;
}
bool  myTester::exists() {
	return true;
}
bool myTester::areEqual(int expected, int actual, string methodName, string whichTestDeclarationString, int testNestDepth) {
	string tabs = "\n";
	for (int i = 0; i < testNestDepth; i++)
	{
		tabs += "\t";
	}
	if (whichTestDeclarationString != "")
	{
		cout << tabs << whichTestDeclarationString;
	}
	cout << tabs << "\tExpected: " << expected << ".";
	cout << tabs << "\tActual: " << actual << ".";
	if (expected == actual) {
		cout << tabs << "The test for method " << methodName << " passed!\n";
		return true;
	}
	else {
		cout << tabs << "The test for method " << methodName << " failed!\n";
		return false;
	}
}

bool myTester::areEquivalentVectors(vector<int> expected, vector<int> actual, string methodName, string whichTestDeclarationString, int testNestDepth) {
	bool testPassed = false;
	vector<int> indexesOfIncorrectValues;
	string tabs = "\n";
	for (int i = 0; i < testNestDepth; i++)
	{
		tabs += "\t";
	}
	if (whichTestDeclarationString != "")
	{
		cout << tabs << whichTestDeclarationString;
	}
	if (expected.size()==actual.size())
	{
		testPassed = true;
		for (int i = 0; i < actual.size(); i++)
		{
			if (expected[i] != actual[i]) {
				indexesOfIncorrectValues.push_back(i);
				testPassed = false;
			}
		}
	}
	if (testPassed) {
		if (methodName == "no")
		{
			cout << tabs << "The test for an unmanipulated list passed!\n";
		}
		else {
			cout << tabs << "The test for method " << methodName << " passed!\n";
		}
		return true;
	}
	else {
		cout << tabs << "\tErrors:";
		if (indexesOfIncorrectValues.size() == 0)
		{
			cout << tabs << "\t\tExpected vector size: " << expected.size() << ".";
			cout << tabs << "\t\tActual vector size: " << actual.size() << ".";
			cout << tabs << "\t\tThe sizes of the expected and actual vectors were different!";
		}
		else
		{
			for (int i = 0; i < indexesOfIncorrectValues.size(); i++)
			{
				cout << tabs << "\t\tIndex of error: " << indexesOfIncorrectValues[i] << ".";
				cout << tabs << "\t\t\tExpected: " << expected[indexesOfIncorrectValues[i]] << ".";
				cout << tabs << "\t\t\tActual: " << actual[indexesOfIncorrectValues[i]] << ".";
			}
		}
		if (methodName == "no")
		{
			cout << tabs << "The test for an unmanipulated list failed!\n";
		}
		else {
			cout << tabs << "The test for method " << methodName << " failed!\n";
		}
		return false;
	}
}
