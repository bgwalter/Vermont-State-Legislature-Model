#include <iostream>

#include "Object.h"
#include "Agent.h"
#include "Bill.h"

using namespace std;

int main(void) {

	Object obj;				// create a new Object called obj
	obj.setOpns(0.2, 0.3);	// set opinion and uncertainty of obj
	obj.printOpns();		// prints out each value of the object
	// define float values to hold each of the Object's values

	Agent mmbr;						// declare a new Agent called mmbr
	mmbr.setMmbr(-0.2, 0.3, 'D');	// set opinion, uncertainty, and part of mmbr
	mmbr.printMmbr();				// prints values of mmbr

	// set float and char values for each of mmbr's attributes
	float opinion, uncertainty, opinionSegment[2];
	char pparty;	
	// give the addresses of each value to getMmbr for use as output parameters
	mmbr.getMmbr(&opinion, &uncertainty, opinionSegment, &pparty);

}
