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

/*
	Parameters: Bill object to form opinion on
	Return: float indicating how the agent feels about the bill
	Form an opinion on a given bill
*/
float Agent::formOpn(Bill bill) {
	/*
		The functions to determine how an agent feels about a bill are simple
		linear functions (one with a positive slope, the other with a negative 
		slope). An output of 1 indicates that the position of the bill is the
		same as the agent's opinion.
		
		Any value greater than 0 indicates the the agent is favorable of the 
		bill. 
		
		A value of 0 indicates that the position of the bill is at the edge of
		the agent's opinion segment
		
		A negative value indicates that the bill is outside of the agent's 
		opinion segment, and thus feels negatively about the bill.
	*/

	// get position of bill
	float billOpn;
	bill.getBill(&billOpn);

	// if the bill is to the left of the agent's opinion
	if (billOpn < opn) return (1 + (billOpn - opn) / uncrtn);
	// if the bill is to the right of hte agent's opinion
	if (billOpn > opn) return (1 + (opn - billOpn) / uncrtn);
	// if the bill's position is the same as the agent's
	else return 1;
}

/*
	Parameters: Interacting Agent
	Returns: 1 if opinions changed, 0 if they did not influence each other
	Interact with another agent. If their opinion segments overlap, they will 
	influence one another towards a more middle ground
*/
int Agent::interact(Agent *member) {

	int returnValue = 0;

	// check to make sure the opinion segments of the two members overlap
	if (opnSeg[0] < member->opnSeg[1] || opnSeg[1] > member->opnSeg[0]) {
		// agents interact and pull eachother closer to agreement
		opn += uncrtn * (member->opn - opn);
		member->opn += member->uncrtn * (opn - member->opn);

		// interaction occured, increment returnValue to be 1
		returnValue++;
	}

	/* 
		TODO introduce 'hardening' of member's opinions by decreasing 
		members' uncertainty. Refer to Meet, Discuss, and Segregate! 
		(Weisbuch et. al., 2002), equations 3 through 6
	*/

	// update opinion segments to reflect the change in new opinion
	setOpns(opn, uncrtn);
	member->setOpns(member->opn, member->uncrtn);

	// return either 0 or 1
	return returnValue;
}
