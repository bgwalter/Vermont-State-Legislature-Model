/*
	Bill.cpp
	2015 January 30
	Brendon Walter (bwalter@bennington.edu)

	Methods for Object class
*/

#include <stdlib.h>

#include "Object.h"
#include "Bill.h"

using namespace std;

/*
	Parameters: opinion
	Returns: 1 if success, 0 if invalid input
	Sets the initial values for an agent
*/
int Bill::setBill(float opinion) {
	// call function from Object class
	setOpns(opinion, 1);
	return 0;	
}

/*
	Parameters: Address of values to hold each attribute of the agent
		Output: Value of each attribute of the agent
	Returns: None
	Returns agent's value as output parameters
*/
void Bill::getBill(float* opinion) {
	float uncertainty, opinionSegment[2];
	getOpns(opinion, &uncertainty, opinionSegment);	// fctn from Object class
}

/*
	Parameters: None
	Returns: None
	Prints out position of bill
*/
void Bill::printBill(void) {
	printOpns();		// function called from Object class
}