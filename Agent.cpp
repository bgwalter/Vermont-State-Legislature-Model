/*
	Agent.cpp
	2014 December 4
	Brendon Walter (bwalter@bennington.edu)

	Methods for Agent class
*/

#include <iostream>

#include "Object.h"
#include "Agent.h"

using namespace std;

/*
	Parameters: opinion, uncertainty, and party values of a new agent
	Returns: 1 if success, 0 if invalid input
	Sets the initial values for an agent
*/
int Agent::setMmbr(float opinion, float uncertainty, char pparty) {
	
	// call function from Object class
	setOpns(opinion, uncertainty);

	// check validity of parameters
	if (pparty == 'D' || pparty == 'd' ||	// democrat
		pparty == 'R' || pparty == 'r' ||	// republican
		pparty == 'P' || pparty == 'p')	{	// progressive
		
		party = pparty;
		return 1;
	}
	cout << "Party can only be D/d, R/r, or P/p.\n";
	return 0;	
}

/*
	Parameters: Address of values to hold each attribute of the agent
		Output: Value of each attribute of the agent
	Returns: None
	Returns agent's value as output parameters
*/
void Agent::getMmbr(float* opinion, float* uncertainty, float opinionSegment[], 
			char* pparty) {
	getOpns(opinion, uncertainty, opinionSegment);	// fctn from Object class
	*pparty = party;
}

/*
	Parameters: None
	Returns: None
	Prints out each attribute of the agent
*/
void Agent::printMmbr(void) {
	printOpns();		// function called from Object class
	cout << "Party: " << party << endl;	
}
