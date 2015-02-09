/*
	Outside.cpp
	2015 Feb 8
	Brendon Walter (bwalter@bennington.edu)

	Methods for outside influences (witnesses, media, constiuency) class
*/

#include "Object.h"
#include "Outside.h"

using namespace std;

/*
	Parameters: opinion of new witness
	Returns: 1 if success, 0 if failure
	Creates a new witness
*/
int Outside::setWitness(float opinion) {
	setOpns(opinion, 1);
	return 1;
}

/*
	Parameters: address of opinion and opinion segment to hold witness' value 
		for each
		Output: witness' opinion and opinion segment
	Returns: None
	Get information of a witness using output paramters
*/
void Outside::getWitness(float* opinion, float opinionSegment[]) {
	float uncertainty;
	getOpns(opinion, &uncertainty, opinionSegment); // fnctn from Object class
}

/*
	Parameters: None
	Returns: None
	Prints the witness' values
*/
void Outside::printWitness(void) {
	printOpns();		// function from Object class
}