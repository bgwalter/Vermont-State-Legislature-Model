/*
	Object.cpp
	2014 December 4
	Brendon Walter (bwalter@bennington.edu)

	Methods for Object class
*/

#include <iostream>

#include "Object.h"

using namespace std;

/*
	Parameters: object's values for opinion and uncertainty about opinion
	Returns: 1 if success, 0 if input values are invalid
	Sets the inital values for each object 
*/
int Object::setOpns(float opinion, float uncertainty) {

	if (opinion < -1 || opinion > 1) {
		cout << "Opinion value can only be between -1 and 1\n";
		return 0;
	}

	if (uncertainty < 0 || uncertainty > 1) {
		cout << "Uncertainty value can only be between 0 and 1\n";
		return 0;
	} 

	opn = opinion;
	uncrtn = uncertainty;
	opnSeg[0] = opn - uncrtn;
	opnSeg[1] = opn + uncrtn;
	return 1;
}


/*
	Parameters: Pointer to each of the object's values
		Output: Each of the object's values as stored in the class
	Returns: None
	Returns each of the object's values as output parameters
*/
void Object::getOpns(float* opinion, float* uncertainty, float opinionSegment[]) {
	*opinion = opn;
	*uncertainty = uncrtn;
	opinionSegment = opnSeg;
}

/*
	Parameters: None
	Returns: None
	Prints out each of the object's values to the screen
*/
void Object::printOpns(void) {
	cout << "Opinion: " << opn 
		 << "\tUncertainty: " << uncrtn 
		 << "\tOpinion Segment: " << opnSeg[0] << " " << opnSeg[1]
		 << endl;
}
